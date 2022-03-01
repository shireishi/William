#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>

#define PORT 8080

/*
I'm learning more about how to do socket programming in C and I want to laern
about how to make custom socket connections. 

I should go through every line of this file and try to understand how it works
and then I should modify it and make it send another message while continuing to run.
*/

struct connection {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *hello = "Hello from my server";
}

void create_connection() {
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SOREUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Forcefully attaching soket to the port 8080
    if (bind(server_fd, (struct sockadd *)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
   }
   if (listen(server_fd, 3) < 0) {
       perror("listen");
       exit(EXIT_FAILURE);
    }
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socketlen_t*)&addrlen))<0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }
    valread = read( new_socket, buffer, 1024 );
    printf("%s\n", buffer);
    send(new_socket, hello, strlen(hello), 0);
    printf("Hello message sent\n");
}