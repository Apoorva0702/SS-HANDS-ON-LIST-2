/*
======================================================================================================================================================================================
name : 29.c
author : Apoorva Kharya 
description :Write a program to remove the message queue.
date: 20 sept 2025
======================================================================================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include<sys/msg.h>

int main(){
    key_t key;
    int msqid;
    key = ftok("." , 'B'); 
    if (key == -1){
      printf("failed to generate key\n");
      return 1;
    }
   msqid = msgget(key, 0666);
   if (msqid == -1){
      printf("message queue do not exist\n");
      return 1;
   }
   if (msgctl(msqid , IPC_RMID, NULL)==-1){
     printf("faile to remove the message queue\n");
     return 1;
    }
    else{ 
    printf("message queue removed successfully\n");
    }
    return 0;
}

/*
======================================================================================================================================================================================
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ gcc 29.c -o 29
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ ./29
message queue removed successfully
======================================================================================================================================================================================
*/
