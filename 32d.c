/*
======================================================================================================================================================================================
name : 32d.c
author : Apoorva Kharya 
description : Write a program to implement semaphore to protect any critical section.
              d. remove the created semaphore
date: 20 sept 2025
======================================================================================================================================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int main() {
    key_t key = ftok(".", 'R');               
    int semid = semget(key, 1, 0);  

    if (semid != -1) {
        semctl(semid, 0, IPC_RMID);
        printf("Semaphore with ID %d removed successfully.\n", semid);
    } else {
        printf("Semaphore does not exist.\n");
    }

    return 0;
}

/*
======================================================================================================================================================================================
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ gcc 32d.c -o 32d
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ ./32d
Semaphore with ID 2 removed successfully.
======================================================================================================================================================================================
*/
