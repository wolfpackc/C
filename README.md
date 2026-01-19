# winsocks  ¿Dónde vive WinSock?
En user mode

Principalmente en:

ws2_32.dll

mswsock.dll

Llama internamente a ntdll.dll → syscalls → kernel
---------------------------------------
## En Linux:

socket() → syscall → kernel TCP/IP


## En Windows:

socket() → WinSock (ws2_32.dll) → kernel TCP/IP

**pero para ser muy claros tcp/ip esta realmente en el kernel**
