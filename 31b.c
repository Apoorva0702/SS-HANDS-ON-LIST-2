/*
======================================================================================================================================================================================
name : 31b.c
author : Apoorva Kharya 
description : Write a program to create a semaphore and initialize value to the semaphore.
              b. create a counting semaphore
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
    key = ftok("." , 'C');
    semid = semget(key , 1 , IPC_CREAT | 0666);
    arg.val = 3;
    semctl(semid , 0 , SETVAL, arg);
    printf("counting semaphore created with ID = %d\n" ,semid);
    printf("semaphore initialized to valuse 3\n");
    return 0;
}

/*
======================================================================================================================================================================================
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ gcc 31b.c -o 31b
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ ./31b
counting semaphore created with ID = 1
semaphore initialized to valuse 3

======================================================================================================================================================================================
*/

