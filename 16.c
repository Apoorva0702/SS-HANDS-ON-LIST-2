/*
======================================================================================================================================================================================
name : 16.c
author : Apoorva Kharya 
description : Write a program to send and receive data from parent to child vice versa. Use two way
             communication.
date: 20 sept 2025
======================================================================================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(){
  int fd_1[2];
  int fd_2[2];
  char buf_1[50], buf_2[50];
  pipe(fd_1);
  pipe(fd_2); 

  if(!fork()){
     close(fd_1[0]);
     close(fd_2[1]);
     printf("Enter message to send to parent:");
     scanf("%[^\n]",buf_1);
     write(fd_1[1], buf_1, sizeof(buf_1));
     read(fd_2[0], buf_2, sizeof(buf_2));
     printf("Message from parent: %s\n", buf_2);
     
  }
  else{
    close(fd_1[1]);
    close(fd_2[0]);
    read(fd_1[0], buf_1, sizeof(buf_1));
    printf("Message from child:%s\n", buf_1);
    printf("Enter message to send to child:\n");
    scanf("%[^\n]", buf_2);
    write(fd_2[1], buf_2, sizeof(buf_2));
  }
 
  return 0;
}

/*
======================================================================================================================================================================================
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ gcc 16.c -o 16
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ ./16
Enter message to send to parent: hello parent
Message from child: hello parent
Enter message to send to child:
hello child
Message from parent: hello child
======================================================================================================================================================================================
*/

