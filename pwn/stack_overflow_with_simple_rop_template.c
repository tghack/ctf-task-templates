#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void supersecret(void)
{
	system("cat flag.txt");
}

void store_secret(void)
{
	char name[20];

	setvbuf(stdout, NULL, _IONBF, 0);
	printf("Welcome hackerman!\nPlease enter your secret password to go back in time: ");

	read(STDIN_FILENO, name, 64);	
}

int main(void) 
{
	store_secret();
	
	return 0;
}
