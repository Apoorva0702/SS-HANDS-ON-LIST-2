/*
======================================================================================================================================================================================
name : 22.c
author : Apoorva Kharya 
description : Write a program to wait for data to be written into FIFO within 10 seconds, use select system call with FIFO.
date: 20 sept 2025
======================================================================================================================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/select.h>
#include <sys/time.h>   
#include <sys/types.h>

int main(){
   fd_set ds;
   char buf[100];
   int fd;
   struct timeval t;
   t.tv_sec = 10;
   t.tv_usec = 0;
   mkfifo("/home/apoorva-kharya/myfifo7", 0666);
   fd = open("myfifo7", O_RDONLY| O_NONBLOCK);
   FD_ZERO(&ds);
   FD_SET(fd, &ds);
   printf("Waiting for input for 10 seconds :\n");
   int v = select(fd+1, &ds, NULL, NULL, &t);
   if(v == 0){
      printf("No input given in  10 seconds.\n");
   }
   else{
      fcntl(fd, F_SETFL, fcntl(fd, F_GETFL) & ~O_NONBLOCK);
      printf("Input given in 10 seconds.\n");
      read(fd, buf, sizeof(buf)-1);
      buf[99]='\0';
      printf("Reading data given to the FIFO file: %s\n", buf);
   }
   close(fd);
   return 0;
}

/*
======================================================================================================================================================================================
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ gcc 22.c -o 22
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ ./22
Waiting for input for 10 seconds :
Input given in 10 seconds.
Reading data given to the FIFO file: hello I am APoorva

apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ ./22
Waiting for input for 10 seconds :
No input given in  10 seconds.
======================================================================================================================================================================================
*/
