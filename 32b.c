/*
======================================================================================================================================================================================
name : 32b.c
author : Apoorva Kharya 
description : Write a program to implement semaphore to protect any critical section.
              b.protect shared memory from concurrent write access
date: 20 sept 2025
======================================================================================================================================================================================
*/


#include<stdio.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/sem.h>

#define SHM_SIZE 1024

union semun{
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};

void sem_wait(int semid){
    struct sembuf sb = {0 , -1 , 0};
    semop(semid , &sb , 1);
}

void sem_signal(int semid){
    struct sembuf sb = {0 , 1 , 0};
    semop(semid , &sb , 1);
}

int main(){
    key_t key1 = ftok("." ,'M');
    key_t key2 = ftok("." ,'S');
    int shmid = shmget(key1,SHM_SIZE , IPC_CREAT | 0666);
    char *data = (char*)shmat(shmid , NULL , 0);
    int semid = semget(key2 , 1 , IPC_CREAT | 0666);
    union semun arg;
    arg.val = 1;
    semctl(semid , 0 , SETVAL ,arg);
    printf("inside critical section\n");
    strcpy(data , "written safely with semaphore protection");
    printf("data in shared memory:%s\n" , data);
    sem_signal(semid);
    printf("exited critical section\n");
    shmdt(data);
    shmctl(shmid , IPC_RMID , NULL);
    semctl(semid,0,IPC_RMID);
    return 0;
}

/*
======================================================================================================================================================================================
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ gcc 32b.c -o 32b
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ ./32b
inside critical section
data in shared memory:written safely with semaphore protection
exited critical section
======================================================================================================================================================================================
*/

