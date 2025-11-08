/*
======================================================================================================================================================================================
name : 28.c
author : Apoorva Kharya 
description : Write a program to change the exiting message queue permission. (use msqid_ds structure)
date: 20 sept 2025
======================================================================================================================================================================================
*/

#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>

int main(void){
   key_t key;
   int msgid;
   struct msqid_ds buf;

   key = ftok("." , 'B');
   msgid = msgget(key , 0666 | IPC_CREAT);
   msgctl(msgid , IPC_STAT , &buf);
   printf("old permission: %o\n" , buf.msg_perm.mode);
   buf.msg_perm.mode = 0777;
   msgctl(msgid , IPC_SET , &buf);
   msgctl(msgid , IPC_STAT , &buf);
   printf("new permission : %o\n" , buf.msg_perm.mode);
   return 0;
}

/*
======================================================================================================================================================================================
before changing the permission 
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x42050002 0          apoorva-kh 666        0            0           
0x41050002 1          apoorva-kh 666        0            0     


after changing the premissions 
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ gcc 28.c -o 28
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ ./28
old permission: 666
new permission : 777
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x42050002 0          apoorva-kh 777        0            0           
0x41050002 1          apoorva-kh 666        0            0       
======================================================================================================================================================================================
*/

