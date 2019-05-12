#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int logged_in;
static char *username;
static int running = 1;

static void print_menu(void)
{
	if (logged_in)
		printf("Hello, %s!\n", username);
	puts("1. ping");
	if (logged_in)
		puts("2. log out");
	else
		puts("2. log in");
	puts("3. edit username");
	puts("4. exit");
	printf("> ");
}

static int get_num(void)
{
	char buf[16] = { 0 };

	if (!fgets(buf, sizeof(buf), stdin)) {
		perror("fgets()");
		exit(EXIT_FAILURE);
	}

	return atoi(buf);
}use_after_free

static void run_cmd(void)
{
	static char *cmd;

	if (!cmd) {
		cmd = malloc(128);
		strcpy(cmd, "ping -c 3 127.0.0.1");
	}

	system(cmd);
}

static void edit_name(void)
{
	printf("Username: ");
	if (!fgets(username, 128, stdin)) {
		perror("fgets()");
		exit(EXIT_FAILURE);
	}

	/* strip newline */
	username[strcspn(username, "\n")] = '\0';
}

static void log_in_out(void)
{
	if (logged_in) {
		free(username);
		logged_in = 0;
		return;
	}

	username = malloc(128);
	edit_name();
	logged_in = 1;
}

int main(void)
{
	int choice;
	alarm(30);
	setvbuf(stdout, NULL, _IONBF, 0);

	while (running) {
		print_menu();
		choice = get_num();

		switch (choice) {
		case 1:
			run_cmd();
			break;
		case 2:
			log_in_out();
			break;
		case 3:
			edit_name();
			break;
		case 4:
			running = 0;
			break;
		default:
			printf("Invalid menu option %d!\n", choice);
		}
	}

	return 0;
}
