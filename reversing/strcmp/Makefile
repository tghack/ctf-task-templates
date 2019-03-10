CC=gcc 
CFLAGS=-Wall -Wextra

.PHONY: all, run, clean
all: strcmp

flip: strcmp.c
	$(CC) $(CFLAGS) $^ -o $@

run: strcmp
	./$^

clean:
	rm -vf strcmp
