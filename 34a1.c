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
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <netinet/in.h>

#define PORT 3558
void client(int cid){
    char buf[100];
    ssize_t let = read(cid, buf, 99);
    if(let > 0){
       buf[let] = '\0';
       printf("\nMsg from client with pid - %d: %s",getpid(),buf);
    }
    write(cid, "\nACK from Server\n",16);
    close(cid);
}

int main(){
   struct sockaddr_in sr, cn;
   int sd, nsd;
   socklen_t sl;
   sd = socket(AF_INET, SOCK_STREAM, 0);
   sr.sin_family = AF_INET;
   sr.sin_addr.s_addr = INADDR_ANY;
   sr.sin_port = htons(PORT);
   bind (sd, (struct sockaddr *) (&sr), sizeof(sr));
   listen(sd,5);
   printf("\nConcurrent server with Parent-%d", getpid());
   while(1){
      sl = sizeof(cn);
      nsd = accept(sd, (struct sockaddr *) (&cn), &sl);
      printf("\nNew socket-%d",nsd);
      pid_t id = fork();
      if(id == 0){
         close(sd);
	 client(nsd);
	 exit(0);
      }
      else{
         close(nsd);
	 waitpid(-1, NULL, WNOHANG);
      }
   
   }
   close(sd);

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
