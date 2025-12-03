```bash
level09@SnowCrash:~$ ll
total 24
dr-x------ 1 level09 level09  140 Mar  5  2016 ./
d--x--x--x 1 root    users    340 Aug 30  2015 ../
-r-x------ 1 level09 level09  220 Apr  3  2012 .bash_logout*
-r-x------ 1 level09 level09 3518 Aug 30  2015 .bashrc*
-rwsr-sr-x 1 flag09  level09 7640 Mar  5  2016 level09*
-r-x------ 1 level09 level09  675 Apr  3  2012 .profile*
----r--r-- 1 flag09  level09   26 Mar  5  2016 token
```
This one is a little disapointing,
we can see a binary when we try it

```bash
level09@SnowCrash:~$ ./level09
You need to provied only one arg.
level09@SnowCrash:~$ ./level09 aaaaaaaaaaaaaaaaaaaaaaaaaa
abcdefghijklmnopqrstuvwxyz
```
we can try to read the token,
```bash
level09@SnowCrash:~$ cat token
f4kmm6p|=pnDBDu{
```
so we understand that this has been done with the level09.
So if have to create the exact opposite
BUTTTTT you have been pranked 
```bash
level09@SnowCrash:~$ cat -A token
f4kmm6p|=M-^B^?pM-^BnM-^CM-^BDBM-^CDu{^?M-^LM-^I$
```
I would advice you to make a script that takes from the token file
```bash
./a.out token
f3iji1ju5yuevaus41q1afiuq
```
To finish you can simply switch to flag09 and GG
