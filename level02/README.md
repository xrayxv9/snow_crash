```bash
level02@SnowCrash:~$ ll
total 24
dr-x------ 1 level02 level02  120 Mar  5  2016 ./
d--x--x--x 1 root    users    340 Aug 30  2015 ../
-r-x------ 1 level02 level02  220 Apr  3  2012 .bash_logout*
-r-x------ 1 level02 level02 3518 Aug 30  2015 .bashrc*
----r--r-- 1 flag02  level02 8302 Aug 30  2015 level02.pcap
-r-x------ 1 level02 level02  675 Apr  3  2012 .profile*
```

Here we go we now have something to search for,
What is a pcap ?
A pcap is a file made by wireshark of a network.

So we take the file to our real machine to be able to use the level02.pcap

```bash
scp -P 4242 level02@<ip> level02.pcap .
```

We can now look through all the packets, until we find one that says "Pas sword"
we then follow the packet, 
Finally we find this : "ft_wandr...NDRel.L0L"
The question is what are this '.'
To understand that we put wireshark in hexa: 
```
66 = f
74 = t
5f = _
77 = w
61 = a
6e = n
64 = d
72 = r
7f = <del>
7f = <del>
7f = <del>
4e = N
44 = D
52 = R
65 = e
6c = l
7f = <del>
4c = L
30 = O
4c = L
0d = <enter>
```

```bash
su flag02
ft_waNDReL0L
```
ANNDDDDDD getflag
