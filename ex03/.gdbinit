 set print pretty on
 set print array on
 set print array-indexes on
 set history save on
 set history size 1000
 set confirm off

 define asm
   set disassembly-flavor intel
   layout asm
 end

     # Raccourcis utiles
     define r32
       info registers eax ebx ecx edx esi edi esp ebp
     end

     define r64
       info registers rax rbx rcx rdx rsi rdi rsp rbp
     end

     # Afficher une string
     define pstr
       if $argc == 1
         x/s $arg0
       else
         echo "Usage: pstr <register_or_address>\n"
       end
     end

     # Afficher des bytes
     define pbytes
       if $argc == 2
         x/$arg1cb $arg0
       else
         echo "Usage: pbytes <address> <count>\n"
       end
     end
