
## Winsock es como una especie de interfaz o traductor.

vamos a hablar acerca de winsocks. es una API que lo que hace es simplemente proporcionar funciones que mejoran digamos la creación de código más manejable.

WINSOCK --> socket puro --> kernel

# stdio
se trata de una libreria de C permite utilizar ciertas funciones que no tienen ni idea de lo que son los descriptores. Estas funciones solo permiten utilzar FILE*.
Estas funciones suelen empezar por "f" como por ejemplo:
                              ->fprintf
                              ->fputs
estas funciones requieren de un parametro FILE *  
en la compilacion se traducen a funciones kernel.


# libc

Una cosa interesante que se tiene que saber tiene que ver con la libreria libc, esta libreria diría que viene enlazada con el compilador, y consiste en una especie de traductor, que permite
que ciertas funciones específicas o ESTANDAR, puedan ser interpretadas de manera correcta por el sistema operativo. Al fin y al cabo,gran parte de comandos de C, requieren o son dependientes del sistema
operativo.

Por ello LIBC permite que funciones tan simples como imprimir por pantalla lo entienda tanto linux como windows. esto es importante vamos a ver, cunado tu te instalas el compilador te viene esa libreria libc¿cierto? pues 
es importante recordar que ese compilador puede ser para linux o para windows, y por lo tanto esa libc tambien puede ser para linuxo para debian o mac o cualquier so.

