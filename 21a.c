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
   fd = open("/home/apoorva-kharya/hands on list 2/myfifo4", O_WRONLY);
   fd1 = open("/home/apoorva-kharya/hands on list 2/myfifo3", O_RDONLY);
   printf("\nEnter the message for sending: ");
   scanf("%[^\n]", buf);
   write(fd, buf, sizeof(buf));
   close(fd);

   read(fd1, buf1, sizeof(buf1));
   close(fd1);
   printf("\nThe message received is: %s\n", buf1);
   return 0;
}

/*
======================================================================================================================================================================================
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ gcc 21a.c -o 21a
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ ./21a

Enter the message for sending: hello from user1 

The message received is: hello user1 received your message , from user2

apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ gcc 21b.c -o 21b
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ ./21b

The message received is: hello from user1 

Enter the message for sending: hello user1 received your message , from user2

======================================================================================================================================================================================
*/
