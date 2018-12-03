#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

static void __attribute__((constructor)) print_system(void)
{
	void *addr;

	addr = dlsym(RTLD_NEXT, "system");
	if (!addr)
		exit(EXIT_FAILURE);

	printf("system: %p\n", addr);
}

int main(void)
{
	printf("heyyy\n");

	return 0;
}

/* $ gcc tmp.c -o tmp -m32 -ldl
 * $ ./tmp
 * system: 0xf763a940
 * heyyy */
