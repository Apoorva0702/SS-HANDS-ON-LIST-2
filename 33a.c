/*
======================================================================================================================================================================================
name : 33.c
author : Apoorva Kharya 
description : Write a program to communicate between two machines using socket.
date: 20 sept 2025
======================================================================================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[1024];
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    listen(server_fd, 5);
    printf("Server listening on port %d...\n", PORT);
    new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
    printf("Client connected\n");
    read(new_socket, buffer, sizeof(buffer));
    printf("Message from client: %s\n", buffer);
    char *msg = "Hello from server";
    send(new_socket, msg, strlen(msg), 0);

    close(new_socket);
    close(server_fd);

    return 0;
}

/*
======================================================================================================================================================================================
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ gcc 33b.c -o 33b
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ ./33b
Message sent to server.
Message from server: Hello from server

apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ gcc 33a.c -o 33a
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ ./33a
Server listening on port 8080...
Client connected
Message from client: Hello from client
======================================================================================================================================================================================
*/
