#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int server_fd, client_fd;
    struct sockaddr_in server_addr;
    char buffer[1024];

    // 1. Crear socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("socket");
        exit(1);
    }

    // 2. Configurar dirección
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(4444);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // 3. Asociar socket a IP:PUERTO
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    // 4. Escuchar conexiones
    listen(server_fd, 1);
    printf("Servidor escuchando en el puerto 4444...\n");

    // 5. Aceptar cliente
    client_fd = accept(server_fd, NULL, NULL);
    printf("Cliente conectado\n");

    // 6. Recibir datos
    read(client_fd, buffer, sizeof(buffer));
    printf("Mensaje recibido: %s\n", buffer);

    // 7. Enviar respuesta
    write(client_fd, "Hola desde el servidor\n", 24);

    close(client_fd);
    close(server_fd);

    return 0;
}
