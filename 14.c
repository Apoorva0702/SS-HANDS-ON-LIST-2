/*
======================================================================================================================================================================================
name : 14.c
author : Apoorva Kharya 
description : Write a simple program to create a pipe, write to the pipe, read from pipe and display on
              the monitor.
date: 20 sept 2025
======================================================================================================================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(){
  int fd_1[2];
  char buf[50];
  const char *string;
  string = "Hii to the pipe.\n";
  pipe(fd_1);
  printf("Writing to the pipe.\n");
  write(fd_1[1], string, 18);

  printf("Reading from the pipe.\n");
  read(fd_1[0], buf, 50);
  printf("Displaying  to the monitor-\n%s", buf);
  return 0;
  
}

/*
======================================================================================================================================================================================
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ gcc 14.c -o 14
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ ./14
Writing to the pipe.
Reading from the pipe.
Displaying  to the monitor-
Hii to the pipe.
======================================================================================================================================================================================
*/

