# Tips and tools

This page is meant to help you on your journey of becoming a 1337 hacker 
(in CTFs). We will tell you about a few tools that will help you on your way. 
A part of the hacker training is to get your black belt in google-foo. You 
need to train your google-foo skills, so we can not provide you with much 
information on how to use the tools! As all hackers know, the learning curve 
in hacking is tremendously steep, but when your hacker and google skills 
arrive at a certain level, the thirst for knowledge is hard to stop and you 
suddenly obtain your black belt in google-foo.

In addition to providing the list of tools on this page, we have a little 
starting kit for your hacker journey. That starting kit is the tutorials on 
using _Python_ to make solution scripts for CTF tasks in general, and then a
little more in detail on how to use these _Python_ skills to solve cryptography
and pwn tasks. Those of you who have a little experience with Python scripting,
and simple encoding and encryption, you may skip this tutorial and move 
straight on to the **n00b** tasks. You find the tutorials 
[here](https://tghack.no/page/Tutorial), and the corresponding tasks in the 
_n00b_, _crypto_ and _pwn_ categories at the [tasks page](https://tghack.no/categories). 

______

<br>

## Tools
### General tools
* [Google, google and more google](http://lmgtfy.com/?q=google): Searching for 
information and learning new things by doing so, might be the most powerful tool 
for hackers! And remember, you need to train hard to get your google-foo black belt!
* By googling: Web pages with converting programs, e.g. hex to ascii. Calculators 
and decoders for different ciphers within cryptography. And a lot more!!!
* Wikipedia 
* Kali Linux: An image of an operating system with loads of tools. 
* [zarduz/ctf-tools](https://github.com/zardus/ctf-tools) github repo with loads of CTF tools.
* [CyberChef](https://gchq.github.io/CyberChef/) for encoding and decoding.

<br>

### Cryptography
* Sagemath
* Python scripting: 
  * [pycrypto](https://github.com/dlitz/pycrypto)
  * [pwntools](https://github.com/Gallopsled/pwntools)
* [CyberChef](https://gchq.github.io/CyberChef/)

<br>

### Web Security
* DevTools in web browser: When in a website, open with `Ctrl+Shift+I`, 
`f12`, or right click on the page and select `Inspect`.
* [Burp Suite](https://portswigger.net/burp).
* [Fiddler](https://www.telerik.com/fiddler).
* [Online JavaScript Beautifier](https://beautifier.io/)
* [swisskyrepo/PayloadsAllTheThings](https://github.com/swisskyrepo/PayloadsAllTheThings): 
A list of useful payloads and bypass for Web Application Security and Pentest/CTF

<br>

### Forensics
* [Wireshark](https://www.wireshark.org/docs/man-pages/wireshark.html)
* [tshark](https://www.wireshark.org/docs/man-pages/tshark.html)
* [tcpdump](https://www.tcpdump.org/tcpdump_man.html)
* [python scapy](http://scapy.readthedocs.io/en/latest/introduction.html)
* [foremost](https://tools.kali.org/forensics/foremost) for recovering files from disk images or other files.
* [Sleuth Kit](https://www.sleuthkit.org/sleuthkit/download.php) Disk image forensic toolkit.
* [Volatility](https://github.com/volatilityfoundation/volatility) Memory forensics framework.

<br>

### Reverse Engineering
* [Ghidra](https://ghidra-sre.org/): A free reverse engineering toolset with a built-in decompiler.
* [IDA](https://www.hex-rays.com/products/ida/support/download.shtml): A nice tool for reverse engineering.
* Terminal command: `strings`
* [Online disassembler](https://onlinedisassembler.com/static/home/)
* [RetDec decompiler](https://retdec.com/)
* [Binary Ninja](https://binary.ninja/demo/): Disassembler and hex editor.
* [x64dbg](https://x64dbg.com/) Open source x64/x32 windows debugger.
* [radare2 cutter](https://github.com/radareorg/cutter) Open source GUI for radare2.
* Python scripting:
 * [Angr](https://angr.io/): a python framework for analyzing binaries. It combines both static and dynamic 
 symbolic ("concolic") analysis, making it applicable to a variety of tasks.

<br>

### Pwn
* gdb: GNU Debugger
* [gdb-peda](https://github.com/longld/peda): Makes the debugger nicer
* Terminal command: `ltrace` for tracing library calls. Use the man page.
* Terminal command: `strace` for tracing syscalls. Use the man page.
* [pwntools](https://github.com/Gallopsled/pwntools)

<br>

### Steganography
* [Audacity](https://www.audacityteam.org/), for sound files.
* [Sonic Visualizer](https://www.sonicvisualiser.org/), for sound files.
* [Online spectrum analyzer](https://academo.org/demos/spectrum-analyzer/), for sound files.
* [Stegsolve](https://github.com/zardus/ctf-tools/tree/master/stegsolve) for image files.
* [Zsteg](https://github.com/zed-0xff/zsteg) for png image files.
* [Stego toolkit](https://github.com/DominicBreuker/stego-toolkit), a collection of many steganography tools.

<br>

### Misc
* [z3](https://github.com/Z3Prover/z3): "Z3 is a theorem prover from Microsoft Research."
* [pwntools](https://github.com/Gallopsled/pwntools)

<br>

### Terminal tools
* man pages: Manual pages for functions. Write man in front of any terminal command or C function. 
* `strings`: Use the man page.
* `file`: Finds header information about a file. 
* `binwalk`: Looks for all known file headers in a file.
* `ltrace`: Tracing library calls. Use the man page.
* `strace`: Tracing syscalls. Use the man page.

<br>

### Python
* Python is a very easy, yet powerful scripting language. It is very relevant for CTFs. Python probably can be used for all the categories of CTFs.
* [Codecademy](https://www.codecademy.com/learn/learn-python): Nice page to learn python.
* [pycrypto](https://github.com/dlitz/pycrypto): Read about usage in Python tutorial.
* [pwntools](https://github.com/Gallopsled/pwntools): Read about usage in Python tutorial.
* [scapy](http://scapy.readthedocs.io/en/latest/introduction.html): For forensics

<br>

_______

<br>

## Tips for binary files
* Binaries may be run in the terminal by putting a `./` in front of it. However, we must know that it is an executable first. We may check that by using either [**file**](#Terminal-tools) or [**binwalk**](#Terminal-tools). 
* Sometimes a binary must be changed to be an executable. That may happen if you get an error while trying to run the executable, such as a message saying permission denied. You may try fix that by using the terminal command `chmod +x binaryname`, and run it again.
* You may input things to a binary by piping input into the binary, like in the two following terminal commands:

```sh
$ echo "Hello!" | ./binary_name
$ python3 -c 'print("A" * 30)' | ./binary_name
```
	
* To find all functions in an executable, you can use `readelf -a ./executable`, or sometimes it is possible to simply write `disas ` and autocomplete when in [gdb-peda](#gdb-peda) to get a list of functions. 
The source code of an executable have the same information, as all the functions are written inside the code. Therefore, this step may only be useful for the tasks that do not provide source files. 
However, you could try to run the command on a task where the source code is provided, to test it and see if you understand it.

<br>

## Tips for gdp-peda
* gdb-peda is a plugin for your terminal to make debugging easier and more understandable.
* Download gdb-peda from [this site](https://github.com/longld/peda).
* Useful commands:
  * Run with `gdb-peda$ r`
  * Disassemble with `gdb-peda$ disas functionname`
  * Find memory address of a function by entering `gdb-peda$ p functionname` 
  * Set breakpoint using `gdb-peda$ b *memoryadress` or `gdb-peda$ b functionname`
* Read the tutorial if you want to see examples of usage.
