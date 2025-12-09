```bash
level14@SnowCrash:~$ ll
total 12
dr-x------ 1 level14 level14  100 Mar  5  2016 ./
d--x--x--x 1 root    users    340 Aug 30  2015 ../
-r-x------ 1 level14 level14  220 Apr  3  2012 .bash_logout*
-r-x------ 1 level14 level14 3518 Aug 30  2015 .bashrc*
-r-x------ 1 level14 level14  675 Apr  3  2012 .profile*
```
For the final exercise, we dont see any file to exploit,
What would be a great finale ?
hide the flag within the most important command, getflag
so let's take a look with gdb
when we open gdb we can see that there is a protection right at the beginning with ptrace,
so we can go right after the funtion and chage eax, which is the return value:
```
level14@SnowCrash:~$ which getflag
/bin/getflag
level14@SnowCrash:~$ gdb --tui /bin/getflag
(gdb) layout asm
(gdb) b main
(gdb) ni (until the call to ptrace is done)
(gdb) info reg $eax
(gdb) set $eax = 1
```
Good job, like that we gaslighted the program to think we were not on gdb !
nowwwwww,
To make things easier I would advise to use this
https://dogbolt.org/
on the getflag command, so that you can see what the code looks like in C.
Now the next step is no go until the first call to isLib,
the first time you see it you shall put it's return value to 1
then you can leave it alone the second time,
now the third time, you should put it again to 1.
The first time was to put a variable to a certain value, the second time, we don't do it because it's a else if,
which means that it won't continue the code if you keep putting 1
The third time is to have access to all the flags.
Good job.
Now at some point you will get on a call, which is a getuid call, but you don't have the right UID, we don't care,
we change it !
but which one is it ?
let's see
if you are already on gdb, to solutions.
I.
You open a new ssh connection and make the
``` bash   
level14@SnowCrash:~$ id flag14
uid=3014(flag14) gid=3014(flag14) groups=3014(flag14),1001(flag)
```
II.
you just Ctrl + z, which will suspend the process
```bash
level14@SnowCrash:~$ id flag14
uid=3014(flag14) gid=3014(flag14) groups=3014(flag14),1001(flag)
```
and fg to re-open gdb where you left it.
now let's have a look to what is the return value of the getuid

```bash
(gdb) info reg $eax
2014
```
we don't want that as we know so let's change it
```bash
(gdb) set $eax = 3014
```
now we can just keep doing ni
until we see the flag
GG you have all the bonuses !

