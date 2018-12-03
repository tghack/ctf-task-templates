#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	char buf[128] = { 0 };
	char flag[] = "TG18{PLACEHOLDER}";

	alarm(30);
	setvbuf(stdout, NULL, _IONBF, 0);

	printf("Give me your data please: ");
	if (!fgets(buf, sizeof(buf), stdin)) {
		perror("fgets()");
		exit(EXIT_FAILURE);
	}

	printf("Here you go: ");
	printf(buf);

	return 0;
}
