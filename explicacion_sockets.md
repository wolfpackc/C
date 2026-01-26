
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
