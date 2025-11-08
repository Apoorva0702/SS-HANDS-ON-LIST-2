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
    int sock = 0;
    struct sockaddr_in serv_addr;
    char *message = "Hello from client";
    char buffer[1024] = {0};
    sock = socket(AF_INET, SOCK_STREAM, 0);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "172.16.145.104 ", &serv_addr.sin_addr);
    connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    send(sock, message, strlen(message), 0);
    printf("Message sent to server.\n");
    read(sock, buffer, sizeof(buffer));
    printf("Message from server: %s\n", buffer);

    close(sock);
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
