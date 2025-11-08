/*
======================================================================================================================================================================================
name : 6.c
author : Apoorva Kharya 
description :Write a simple program to create three threads.
date: 20 sept 2025
======================================================================================================================================================================================
*/
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* thread(void* args) {
    int id = *(int*)args;
    printf("thread %d\n", id);
    sleep(id);
    printf("thread %d has completed and is exiting\n", id);
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
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ gcc 6.c -o 6
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ ./6
thread 1
thread 3
thread 2
thread 1 has completed and is exiting
thread 2 has completed and is exiting
thread 3 has completed and is exiting
======================================================================================================================================================================================
*/
