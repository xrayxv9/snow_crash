```bash
level13@SnowCrash:~$ ll
total 20
dr-x------ 1 level13 level13  120 Mar  5  2016 ./
d--x--x--x 1 root    users    340 Aug 30  2015 ../
-r-x------ 1 level13 level13  220 Apr  3  2012 .bash_logout*
-r-x------ 1 level13 level13 3518 Aug 30  2015 .bashrc*
-rwsr-sr-x 1 flag13  level13 7303 Aug 30  2015 level13*
-r-x------ 1 level13 level13  675 Apr  3  2012 .profile*
```
let's try this:

```bash
level13@SnowCrash:~$ ./level13
UID 2013 started us but we we expect 4242
```
So How to get the UID in C, with getuid which is in the code, thx to the strings:
```bash
level13@SnowCrash:~$ strings ./level13
/lib/ld-linux.so.2
__gmon_start__
libc.so.6
_IO_stdin_used
exit
strdup
printf
getuid
```
So Let's do a simple asm class right now, when we call a function the return value will always be stored within the rax, sooooo
let's open up gdb and modify the rax 

```bash
level13@SnowCrash:~$ gdb ./level13
layout asm
b getuid
run
n
set $eax = 0x1092
info reg $eax
0x1092
n
n
```
And here you should have the flag, be careful it might be glitched somewhere on your screen 👍
good job you have the flag
