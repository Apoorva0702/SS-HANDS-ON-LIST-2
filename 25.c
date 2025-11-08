/*
======================================================================================================================================================================================
name : 25.c
author : Apoorva Kharya 
description : print message queue details using msqid_ds and ipc_perm
date: 20 sept 2025
======================================================================================================================================================================================
*/

#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<time.h>

int main(void){
  key_t key;
  int msgid;
  struct msqid_ds buf;
  key = ftok("." , 'B');
  msgid = msgget(key, 0666 | IPC_CREAT);
  printf("access permissions: %o\n", buf.msg_perm.mode);
  printf("UID : %d\n", buf.msg_perm.uid);
  printf("GID : %d\n", buf.msg_perm.gid);
  printf("last msg sent time : %s\n",ctime(&buf.msg_stime));
  printf("last msg recv time : %s\n",ctime(&buf.msg_rtime));
  printf("last change time : %s\n",ctime(&buf.msg_ctime));
  printf("current queue size : %lubytes\n",buf.__msg_cbytes);
  printf("number of messages : %lu\n",buf.msg_qnum);
  printf("max bytes allowed : %lu\n",buf.msg_qbytes);
  printf("PID of last msgsnd : %d\n",buf.msg_lspid);
  printf("PID of last msgrcv : %d\n",buf.msg_lrpid);
  return 0;
}

/*
======================================================================================================================================================================================
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ gcc 25.c -o 25
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ ./25
access permissions: 0
UID : 0
GID : 262144
last msg sent time : Thu Jan  1 05:30:00 1970

last msg recv time : Thu Jan  1 05:30:00 1970

last change time : Thu Jan  1 05:30:00 1970

current queue size : 0bytes
number of messages : 0
max bytes allowed : 0
PID of last msgsnd : 0
PID of last msgrcv : 0

======================================================================================================================================================================================
*/
