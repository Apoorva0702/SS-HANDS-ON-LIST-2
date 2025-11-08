/*
======================================================================================================================================================================================
name : 21.c
author : Apoorva Kharya 
description : Write two programs so that both can communicate by FIFO -Use two way communications.
date: 20 sept 2025
======================================================================================================================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main(){
   int fd, fd1;
   char buf[100], buf1[100];
   fd = open("/home/apoorva-kharya/hands on list 2/myfifo4", O_RDONLY);
   fd1 = open("/home/apoorva-kharya/hands on list 2/myfifo3", O_WRONLY);
   read(fd, buf, sizeof(buf));
   close(fd);
   printf("\nThe message received is: %s\n", buf);
   printf("\nEnter the message for sending: ");
   scanf("%[^\n]", buf1);
   write(fd1, buf1, sizeof(buf1));
   close(fd1);
   return 0;
}

/*
======================================================================================================================================================================================
poorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ gcc 20a.c -o 20a
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ ./20a
Enter message: hello I am APoorva

apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ gcc 20b.c -o 20b
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ ./20b
Reading from the FIFO File: hello I am APoorva
======================================================================================================================================================================================
*/
