/*
======================================================================================================================================================================================
name : 26.c
author : Apoorva Kharya 
description : Write a program to send messages to the message queue. Check $ipcs -q
date: 20 sept 2025
======================================================================================================================================================================================
*/


#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>

struct msg_buffer{
      long mtype;
      char mtext[100];
   };
   
  int main(void){
       key_t key;
       int msgid;
       struct msg_buffer message;
       key = ftok(".", 'A');
       msgid = msgget(key,0666|IPC_CREAT);
       message.mtype = 1;
       strcpy(message.mtext,"HELLO ,this is a test message");
       msgsnd(msgid,&message,sizeof(message.mtext),0);
       printf("message sent to queue(ID=%d).\n",msgid);
       return 0;
}

/*
======================================================================================================================================================================================
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ gcc 26.c -o 26
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ ./26
message sent to queue(ID=1).
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x42050002 0          apoorva-kh 666        0            0           
0x41050002 1          apoorva-kh 666        100          1   
======================================================================================================================================================================================
*/

