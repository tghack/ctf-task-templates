# Pwn templates

## socat
It is common to use `socat` to host pwn challenges. That is a 
program making it possible to run programs as services which
the contestants connect to. 

To host a task onport 4444, start `socat` this way:
```
socat tcp-listen:4444,fork,reuseaddr exec:./<program>,stderr
```

To start a task as root, and then drop privileges to the TG:Hack
contestant, in order to not kill the `socat` process. E.g:
```
socat tcp-listen:1337,fork,reuseaddr exec:"su tghack -c '/home/tghack/pwn101/pwn101'",stderr
```

## 32-bit binaries on 64-bit OS
To run 32 bit binaries on your 64-bit machine, use the following 
script to download and install software to support 32-bit binaries.
```
#!/bin/bash

set -eux

dpkg --add-architecture i386
apt update
apt install -y libc6:i386
```

## Using pwntools template
The Python library `pwntools` has this awesome function for
generating solve scripts.

Using the following command, you specify the remote address and 
the binary that is to be pwned and paste the generated template 
into the file `solve.py`:
```
pwn template --host pwn.tghack.no --port 1000 ./binary > solve.py
```

If you want GDB to act as when you normally run `gdb ./binary`,
you can change the if sentence in the `start()` function to the 
following snippet:
```
    if args.GDB:
        # The line below is the one we comment out and replace
        #return gdb.debug([exe.path] + argv, gdbscript=gdbscript, *a, **kw)
        io = process('./binary')
        gdb.attach(io, gdbscript)
        return io
```


Now, you may run the solve script locally with `gdb` like this:
```
python solve.py DEBUG GDB
```

To not use `gdb`, just skipt the `GDB` flag. 

To run against the remote server, just run the script without any
flags:
```
python solve.py
```

## More tips
* General pwn tips: https://github.com/Naetw/CTF-pwn-tips
* Leak libc address: https://github.com/ctfhacker/ctf-writeups/blob/master/campctf-2015/bitterman-pwn-400/README.md 
