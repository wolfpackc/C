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


# ¿WinSock es solo “más fácil y visual”?

No exactamente

WinSock NO existe solo para comodidad, sino porque:

Windows NO expone sockets como file descriptors

Windows separa:

Files

Sockets

Pipes

Necesita una API específica

👉 En Linux no hace falta, porque todo es fd.
