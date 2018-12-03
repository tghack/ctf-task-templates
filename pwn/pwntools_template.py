from pwn import *

# sett debug = True når man skal teste løsningen lokalt
debug = False
if debug == True:
    r = process("./binary")
    # uncomment if using ssh
    #context(terminal = ["tmux", "splitw"])
    gdb.attach(r, """
        c
        """)
else:
    r = remote("localhost", 1337)

r.sendline()
r.recvline()
r.send("lolol\n")
r.recvuntil("lololol")

r.interactive()
