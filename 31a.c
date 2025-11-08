/*
======================================================================================================================================================================================
name : 31a.c
author : Apoorva Kharya 
description : Write a program to create a semaphore and initialize value to the semaphore.
              a. create a binary semaphore
date: 20 sept 2025
======================================================================================================================================================================================
*/

#include<stdio.h>
#include<sys/ipc.h>
#include<sys/sem.h>

union semun{
     int val;
     struct semid_ds *buf;
     unsigned short *array;
};

int main(){
    key_t key;
    int semid;
    union semun arg;
    key = ftok(".", 'S');
    semid = semget(key , 1 , IPC_CREAT | 0666);
    arg.val = 1;
    semctl(semid , 0 , SETVAL , arg);
    printf("binary semaphore created with ID = %d\n" , semid);
    printf("semaphore initialized to value 1 (unlocked state).\n");
    return 0;
}

/*
======================================================================================================================================================================================
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ gcc 31a.c -o 31a
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ ./31a
binary semaphore created with ID = 0
semaphore initialized to value 1 (unlocked state).
======================================================================================================================================================================================
*/

