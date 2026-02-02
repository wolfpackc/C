
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

Lo importante aqui es entender que al igual que existen varios compiladores distintos, por lógica se entiende que tambien hay libc´s distintas¿cierto? y que cada libc esta hecha para funcinar con un sistema operativo.

Seré clarito, si yo tengo un compilador para Windows,entonces voy a tener un libc que sepa traducir las funciones estandar de C a fuciones que entienda solamente el sistema operativo Windows.Si yo, con ese mismo compilador y libc, 
intentase compilarlo en linux,ademas de otros problemas que no importan, el cargadador(o compilador,no me acuerdo quien) va a coger esa función C estandar, la va a traducir a una función entendible para windows y entonces el sistema 
oeprativo LINUX no va saber que narices significa eso. por lo tanto crasheo TOTAL.

resumen: 
COMPILADOR WINDOWS--LIBC PARA WINDOWS--> SO WINDOWS/
COMPILADOR DEBIAN--LIBC PARA DEBIAN--->SO LINUX


## “Las librerías C como glibc o UCRT siempre vienen con el compilador y traducen las funciones de C estándar a llamadas que el sistema operativo entiende. POSIX es un estándar en Linux que glibc implementa; en Windows, la libc traduce a Win32 API.”


realmente cuando instalamos este tipo de cosas en nuestro ordenador, gran parte de las veces no instalamos el libc solamente, a menudo se instala lo que se conoce como SDK(software development kit) que no es mas que un conjunto de archivos necesarios para que la compilaciíon de nuestro codigo sea exitosa. 

SObre esto cabe señalar que en distribuciones como Linux, la mayoria de las veces ya viene instalado todo, pero cuando no lo esta, al isntalar el LINUX SDK, se nos descarga los headers necesarios, glibc y el compilador en si.

Por otro lado, en windows, al instalar el WINDOWS SDK, solamente se nos instala los headers y el libc correspondiente, pero como puedes observar el compilador no entra dentro del SDK, es decir se debe de instalar a parte. 
En cuanto a la compatibilidad entre SDK Y compilador windows, no deberia de darnos problemas siempre y cuando no se utilicen versiones muy antiguas.
