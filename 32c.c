/*
======================================================================================================================================================================================
name : 32c.c
author : Apoorva Kharya 
description : Write a program to implement semaphore to protect any critical section.
              c. protect multiple pseudo resources ( may be two) using counting semaphore
date: 20 sept 2025
======================================================================================================================================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/sem.h>

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
   struct sembuf sb = {0 , 1, 0};
   semop(semid , &sb , 1);
}

int main(){
   key_t key = ftok("." , 'R');
   int semid = semget(key , 1 , 0);
   union semun arg;
   arg.val = 2;
   semctl(semid , 0 , SETVAL , arg);
   printf("process %d trying to access resource\n" , getpid());
   sem_wait(semid);
   printf("process %d got a resource , now it's using it\n" , getpid());
   sleep(5);
   printf("process %d releasing resource \n" , getpid());
   sem_signal(semid);
   return 0;

}

/*
======================================================================================================================================================================================
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ gcc 32c.c -o 32c
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ ./32c
process 8370 trying to access resource
process 8370 got a resource , now it's using it
process 8370 releasing resource 
======================================================================================================================================================================================
*/

