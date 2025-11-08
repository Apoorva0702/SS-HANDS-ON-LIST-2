*
======================================================================================================================================================================================
name : 27b.c
author : Apoorva Kharya 
description : Write a program to receive messages from the message queue.
              b. with IPC_NOWAIT as a flag
date: 20 sept 2025
======================================================================================================================================================================================
*/

#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>

struct msg_buffer{
    long mtype;
    char mtext[100];
};

int main(void){
    key_t key;
    int msgid;
    struct msg_buffer message;
    key = ftok("." , 'A');
    msgid = msgget(key , 0666 | IPC_CREAT);
    if( msgrcv(msgid , &message , sizeof(message.mtext) , 1 , IPC_NOWAIT)== -1)
      printf("no message available in queue right now.\n");
    else 
      printf("received message:%s\n" ,  message.mtext);
    return 0;
}

/*
======================================================================================================================================================================================
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ gcc 27b.c -o 27b
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ ./27b
no message available in queue right now.

apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ gcc 26.c -o 26
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ ./26
message sent to queue(ID=1).
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ gcc 27b.c -o 27b
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ ./27b
received message:HELLO ,this is a test message
======================================================================================================================================================================================
*/
