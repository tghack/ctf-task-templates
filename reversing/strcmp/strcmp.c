#include <stdio.h>
#include <string.h>

void print_flag()
{
	char *ret_val;
	char buffer [100];
	FILE *file;
	
	file = fopen("flag.txt","r");
	ret_val = fgets(buffer, 100, file);

	if (ret_val != NULL) {
		puts(buffer);
	}

	fclose(file);
	return;
}

int main(void)
{
	int answer;
	char input[64];
  
	setvbuf(stdout, NULL, _IONBF, 0);
	puts("I am Groot");

	fgets(input, 64, stdin);
	input[strcspn(input, "\n")] = '\0';

	answer = strcmp(input, "Groot");
	if (answer == 0) {
		puts("\nInteresting..\n");
		print_flag();
	} else {
		puts("Groot. Groot groot. Grooot.");
	}

	return 0;
}
