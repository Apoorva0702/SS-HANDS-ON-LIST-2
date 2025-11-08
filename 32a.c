/*
======================================================================================================================================================================================
name : 32a.c
author : Apoorva Kharya 
description : use semaphore and implement ticket reservation system
date: 20 sept 2025
======================================================================================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <unistd.h>
#include <string.h>

#define SHM_SIZE 1024

union semun {
       int val;
       struct semid_ds *buf;
       unsigned short *array;
 };

void sem_wait(int semid){
 
    struct sembuf sb = {0, -1, 0};
    semop(semid, &sb, 1); 
}

void sem_signal(int semid) {

    struct sembuf sb = {0, 1, 0}; 
    semop(semid, &sb, 1); 
}

int main() 
{
    key_t key = ftok("sfile", 65);
    int semid = semget(key, 1, 0666 | IPC_CREAT);
    union semun a;
    a.val =1;
    semctl(semid, 0, SETVAL, a);
    int shmid = shmget(key, sizeof(int), 0666 | IPC_CREAT);
    int *ticket = (int *)shmat(shmid, NULL, 0);
    for (int i = 0; i < 3; i++) {
            sem_wait(semid);
            (*ticket)++;
            printf("Process %d got ticket #%d\n", getpid(), *ticket);
            sem_signal(semid);
            sleep(1);
        }
        shmdt(ticket);
return 0;
}

/*
======================================================================================================================================================================================
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ gcc 32a.c -o 32a
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ ./32a
Process 15901 got ticket #1
Process 15901 got ticket #2
Process 15901 got ticket #3
======================================================================================================================================================================================
*/

