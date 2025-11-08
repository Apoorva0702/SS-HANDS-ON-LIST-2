/*
======================================================================================================================================================================================
name : 34.c
author : Apoorva Kharya 
description : Write a program to create a concurrent server.
              a. use fork
date: 20 sept 2025
======================================================================================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>

#define PORT 3558

int main() {
    struct sockaddr_in sr;
    int sd;
    char buf[100];
    
    sd = socket(AF_INET, SOCK_STREAM, 0);

    sr.sin_family = AF_INET;
    sr.sin_port = htons(PORT); 
    connect(sd, (struct sockaddr *) (&sr), sizeof(sr));
    write(sd,"Hello Server\n", 13);
    ssize_t wrd = read(sd, buf, sizeof(buf) - 1);
    
    if (wrd > 0) {
        buf[wrd] = '\0';
        printf("Message from server: %s", buf);
    }
    
    close(sd);
    return 0;
}

/*
======================================================================================================================================================================================
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ ./34a1

Concurrent server with Parent-7773
New socket-4
Msg from client with pid - 7775: Hello Server

apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ ./34a2
Message from server: 
ACK from Serverapoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ 

======================================================================================================================================================================================
*/
