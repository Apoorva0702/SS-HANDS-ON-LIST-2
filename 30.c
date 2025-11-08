/*
======================================================================================================================================================================================
name : 30.c
author : Apoorva Kharya 
description : Write a program to create a shared memory.
              a. write some data to the shared memory
              b. attach with O_RDONLY and check whether you are able to overwrite.
              c. detach the shared memory
              d. remove the shared memory
date: 20 sept 2025
======================================================================================================================================================================================
*/

#include<stdio.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/shm.h>

#define SHM_SIZE 1024

int main(){
    key_t key = ftok(".", 'S');
    int shmid = shmget(key , SHM_SIZE , IPC_CREAT | 0666);
    char *data = (char *)shmat(shmid , NULL ,0);
    strcpy(data , "this message is from shared memory");
    printf("data written: %s\n" , data);
    shmdt(data);
    data = (char*)shmat(shmid , NULL , SHM_RDONLY);
    printf("data read in read-only attach : %s\n" , data);
    // strcpy(data , "trying to overwrite")
    shmdt(data);
    printf("shared memory detached successfully\n");
    shmctl(shmid , IPC_RMID , NULL);
    printf("removed the shared memory successfully\n");
    return 0;
}

/*
======================================================================================================================================================================================
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ gcc 30.c -o 30
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ ./30
data written: this message is from shared memory
data read in read-only attach) : this message is from shared memory
shared memory detached successfully
removed the shared memory successfully
======================================================================================================================================================================================
*/
