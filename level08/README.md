```bash
total 24
dr-x------ 1 level07 level07  120 Mar  5  2016 ./
d--x--x--x 1 root    users    340 Aug 30  2015 ../
-r-x------ 1 level07 level07  220 Apr  3  2012 .bash_logout*
-r-x------ 1 level07 level07 3518 Aug 30  2015 .bashrc*
-rwsr-sr-x 1 flag07  level07 8805 Mar  5  2016 level07*
-r-x------ 1 level07 level07  675 Apr  3  2012 .profile*
```
Ok so once again we have a binary file
```bash
level08@SnowCrash:~$ ./level08
./level08 [file to read]

level08@SnowCrash:~$ ./level08 token
You may not access 'token'
```
So We see that we are not alowed to open the token file
SOOOOOOOOO
To make sure of what are the rules of which a file can be opened or not, 
let's open it in a decompiler (You will need to copy the file to your machine of course)
https://dogbolt.org/

Once You have read the code, you will understand that it's litteraly the name token that is not allowed,
so to keep the same content without any rights on the file, how can we do to just change the name of the file ?
we create a symbolic link

```bash
level08@SnowCrash:~$ ln -s /home/user/level08/token /tmp/my_file 
level08@SnowCrash:~$ ./level08 /tmp/my_file
<hidden>
```
be careful, you need to put the absolute path to make the symbolic link
GG it's finished
