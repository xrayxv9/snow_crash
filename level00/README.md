```bash
level00@SnowCrash:~$ ll
total 12
dr-xr-x---+ 1 level00 level00  100 Mar  5  2016 ./
d--x--x--x  1 root    users    340 Aug 30  2015 ../
-r-xr-x---+ 1 level00 level00  220 Apr  3  2012 .bash_logout*
-r-xr-x---+ 1 level00 level00 3518 Aug 30  2015 .bashrc*
-r-xr-x---+ 1 level00 level00  675 Apr  3  2012 .profile*
```

For this first exercise We can Use the Video in the intra to get some help.

the hint is:
FIND this first file who can run only as flag00

So when we see this, we can understand that the find command will be of use
We can also understand that one file has flag00 as user

so we can do this command :
```bash
level00@SnowCrash:~$ find / -user flag00 2> /dev/null
/usr/sbin/john
/rofs/usr/sbin/john
```

`find / -user flag00`: This is used to search for a file made by the user flag00
`2> /dev/null`: This is just to remove every errors in the output

We can now cd, to any of the two output and cat the john file
```bash
level00@SnowCrash:/rofs/usr/sbin$ cat john
cdiiddwpgswtgt
```
Althought it looks like the flag, this is not
It looks like a flag simply encripted,
So we can try the Caesar code
We can use the decode website
and now we achieve the password to use the su command

```bash
su flag00
nottohardhere
```

To finish, we can now use the getflag command !

