/*
======================================================================================================================================================================================
name : 15.c
author : Apoorva Kharya 
description : Write a simple program to send some data from parent to the child process.
date: 20 sept 2025
======================================================================================================================================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int main() {
  char buff[50];
  int fd_1[2];
  pipe(fd_1);
  if (fork()) {
    close(fd_1[0]);
    printf("give  message to the child: ");
    scanf(" %[^\n]", buff);
    write(fd_1[1], buff, sizeof(buff));
  }
  else {
     close(fd_1[1]);
     read(fd_1[0], buff, sizeof(buff));
     printf("message from parent: %s\n", buff);
  }
  wait(0);
}

/*
======================================================================================================================================================================================
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ ./15
give  message to the child: hello child
message from parent: hello child
======================================================================================================================================================================================
*/


