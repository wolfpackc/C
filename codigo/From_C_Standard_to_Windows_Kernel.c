//tal como se supone que tienes que saber, cuando hablamos de C , nos encontramos 3 burbujas enlazadas.
//La primera burbuja es "C estandar", esta burbuja consiste en funciones como printf, scanf. Estas funciones 
//son funciones que todas las librerias libc de cada SO, son capaces de traducir a unas funciones que entiende el 
//API y por consiguiente el SO.
//***************************************************************************************************
//La siguiente burbuja la podemos llamar libc de windows,tambien conocidas como MSVCRT/UCRT, diciendolo desde una 
//forma abstracta podemos decir que se trata de un cerebro/traductor que recibe funcines de la burbuja "C estandar" y 
//las traduce a funciones que la API de windows puede entender. POr ejemplo, si ponemos fprintf eso llega a manos de "libc de
// windows" y lo codifica a writeFile(blablabla). Una vez traducido se envia al sistema operativa para que lo digiera y lo 
//convierta a NTwriteFile(blablabla)
//
//Cabe señalar que en linux... tambien dispone de una API propia que es capaz de hacer exactamente lo mismo que la API DE WINDOWS
//la diferencia es que no "expulsará "lo mismo dado que ambos sistemas operativos no hablan el mismo idioma*

//*IMPORTANTE: puede que hayas escuchado eso de que linux y windows hablan el mismo idioma, y tecnicamente es cierto,porque,
//en cuanto a la arquitectura , tanto linux como windows estan sobre las arquitecuras de INtel y AMD, y es cierto que ambos entienden solamente
//el lenguaje ensamblador x82_64(amd tiene funciones extra btw).
//teniendo esto en cuenta podriamos pensar que linux y w al final hablan lo mismo, y realmente eso es verdad, aunque el problemas
//es lo que habla o mas bien espera recibir cada sistema operativo. A esto se le conoce como ABI.
//***************************************************************************************************
//La otra burjuja se trata de las APIS, para que quede claro esto, son las APIS  encangadas enviar solicitudes al kernel,
//windows tiene la API win32,esta,recibe funciones directas y de la libc de windows,las recoge y las codifica normalmente poniendo prefijos como 
//ntXXXXXXX y luego hace un syscall.Lo que recibe con handler.
//En cambio en Linux la API se llama POSIX y se trata de mas o menos lo mismo, solamente es que esta api tiene internamente la libc de linux, cosa que
//es diferente en windows ya que esta separado.
//
//Este es un ejemplo claro donde podemos ver dos funciones, una pertenece a C estandar,es decir, al compilador esa funcion va a pasar por libc de windows(si el libc fuese de linux 
//no daria problemas, el problema es que al estar windows, la api win32 va a recibir una función que solo entendería POSIX). LA otra función va directamente a la api win32.
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(int argc, char **argv) {

    /* C estándar → pasa por UCRT */
    fprintf(stdout, "hola desde C estandar\n");

    /* Win32 directo → NO pasa por UCRT */
    const char msg[] = "hola desde Win32 API\n";
    DWORD written;

    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    WriteFile(
        hStdout,          // HANDLE Win32
        msg,              // buffer
        sizeof(msg) - 1,  // bytes
        &written,         // bytes escritos
        NULL
    );
//como se pueder ver es mas tedioso
    return 0;
}
