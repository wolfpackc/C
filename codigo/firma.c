//FIRMAR UN MENSAJE Y COMPROBAR SU AUTENTICIDAD
//se requiere de la descarga de libsodium antes de compilar para que funcione
#include <sodium.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // 1. Inicializar libsodium
    if (sodium_init() < 0) {
        return 1;
    }

    // 2. Crear par de claves
    unsigned char pk[crypto_sign_PUBLICKEYBYTES];
    unsigned char sk[crypto_sign_SECRETKEYBYTES];

    crypto_sign_keypair(pk, sk);

    // 3. Mensaje a firmar
    const char *mensaje = "hola mundo";
    unsigned long long mensaje_len = strlen(mensaje);

    // 4. Firmar
    unsigned char firma[crypto_sign_BYTES];
    unsigned long long firma_len;

    crypto_sign_detached(
        firma,
        &firma_len,
        (const unsigned char *)mensaje,
        mensaje_len,
        sk
    );

    // 5. Verificar
    if (crypto_sign_verify_detached(
            firma,
            (const unsigned char *)mensaje,
            mensaje_len,
            pk) == 0) {
        printf(" Firma válida\n");
    } else {
        printf("Firma inválida\n");
    }

    return 0;
}
