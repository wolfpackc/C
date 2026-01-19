#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[1024];

    // 1. Crear socket
    sock = socket(AF_INET, SOCK_STREAM, 0);

    // 2. Configurar dirección del servidor
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(4444);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    // 3. Conectar
    connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));

    // 4. Enviar datos
    write(sock, "Hola servidor", 14);

    // 5. Recibir respuesta
    read(sock, buffer, sizeof(buffer));
    printf("Respuesta del servidor: %s\n", buffer);

    close(sock);
    return 0;
}
