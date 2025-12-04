```bash
level01@SnowCrash:~$ ll
total 12
dr-x------ 1 level01 level01  100 Mar  5  2016 ./
d--x--x--x 1 root    users    340 Aug 30  2015 ../
-r-x------ 1 level01 level01  220 Apr  3  2012 .bash_logout*
-r-x------ 1 level01 level01 3518 Aug 30  2015 .bashrc*
-r-x------ 1 level01 level01  675 Apr  3  2012 .profile*
```
Same as the last exercice, we have nothing.
Not even an hint
So the first we have to do when it's like that, it is to cat the /etc/passwd
and tadam
```bash
cat /etc/passwd
42hDRfypTqqnw
```
We have it !!
just kidding, this doesn't work, because we have to use the john command !

```bash
echo '42hDRfypTqqnw' > token
john token
abcdefg
```
And yes, the final password to connect to flag01 is abcdefg..

```bash
su flag01
abcdefg
```
and now we can use the getflag command !
