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



# ¿cómo funciona el compilado?

el compilado es bastante sencillo ya que siempre se aplica las mismas reglas 
en primer lugar entra en la fase de precompilacion donde lo que ocurre es que se 
añaden las directivas y macros que tiene el código.

el siguiente es la obtencion de una especio de codigo ensamblador pero que en realidad es 
mas como un codigo universal que al mismo tiempo no funciona en ningun sitio.

a continuación , se traduce ese codigo universal(IR) a lenguaje ensamblador ya adaptado al hardware en el que se encuentra
com por ejemplo intel, amd...

Después vendria la creacion de archivos OBJETOS que tras realizar un "link " de todos los objetos y otras cosas obtendriamos 
los que se conoce como ejecutable (.out/.exe).
