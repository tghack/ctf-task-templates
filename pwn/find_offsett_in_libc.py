from pwn import *

libc = ELF('libc.so')
system_off = libc.symbols['system'] # in this case we find system
