/*
======================================================================================================================================================================================
name : 7.c
author : Apoorva Kharya 
description : Write a simple program to print the created thread ids.
date: 20 sept 2025
======================================================================================================================================================================================
*/


#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* thread(void*args) {
    int id = *(int*)args;
    printf("thread %d : pthread ID %lu\n", id, pthread_self());
    sleep(id);
    printf("thread %d with pthread ID %lu has completed and is exiting\n", id, pthread_self());
    return NULL;
}

int main() {
    pthread_t thread_1[3];
    int id_1[3] = {1, 2, 3};

    for (int i = 0; i < 3; i++)
        pthread_create(&thread_1[i], NULL, thread, &id_1[i]);

    for (int i = 0; i < 3; i++)
        pthread_join(thread_1[i], NULL);

    return 0;
}

/*
======================================================================================================================================================================================
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ gcc 7.c -o 7
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ ./7
thread 1 : pthread ID 123470459434688
thread 2 : pthread ID 123470451041984
thread 3 : pthread ID 123470442649280
thread 1 with pthread ID 123470459434688 has completed and is exiting
thread 2 with pthread ID 123470451041984 has completed and is exiting
thread 3 with pthread ID 123470442649280 has completed and is exiting
======================================================================================================================================================================================
*/
