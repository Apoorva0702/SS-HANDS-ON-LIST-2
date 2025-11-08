/*
======================================================================================================================================================================================
name : 20.c
author : Apoorva Kharya 
description : Write two programs so that both can communicate by FIFO -Use one way communication.
date: 20 sept 2025
======================================================================================================================================================================================
*/


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main(){
   char buf[100];
   int fd_1;
   fd_1 = open("/home/apoorva-kharya/hands on list 2/myfifo4", O_RDONLY);
   read(fd_1, buf, sizeof(buf));
   printf("Reading from the FIFO File: %s\n",buf);
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
