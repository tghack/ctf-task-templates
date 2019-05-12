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

## More tips
* https://github.com/Naetw/CTF-pwn-tips
* https://github.com/ctfhacker/ctf-writeups/blob/master/campctf-2015/bitterman-pwn-400/README.md : 
How to leak libc address by ROPing to puts(9 using puts as an argument.
