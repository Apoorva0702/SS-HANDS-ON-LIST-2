/*
======================================================================================================================================================================================
name : 27a.c
author : Apoorva Kharya 
description : Write a program to receive messages from the message queue.
              a. with 0 as a flag
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
    msgrcv(msgid , &message , sizeof(message.mtext) , 1 , 0);
    printf("received message:%s\n" , message.mtext);
    return 0;
}

/*
======================================================================================================================================================================================
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ gcc 27a.c -o 27a
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ ./27a
received message:HELLO ,this is a test message
======================================================================================================================================================================================
*/

