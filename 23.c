/*
======================================================================================================================================================================================
name : 23.c
author : Apoorva Kharya 
description : c program to print soft and hard limit for max open files 
date: 20 sept 2025
======================================================================================================================================================================================
*/

#include<stdio.h> 
#include<unistd.h>
#include<sys/resource.h>
#include<fcntl.h>

int main(void){
   struct rlimit rl;
   getrlimit(RLIMIT_NOFILE, &rl);
   printf("max open files(soft limit) : %llu\n" , (unsigned long long)rl.rlim_cur);
   printf("max open files(hard limit) : %llu\n" , (unsigned long long)rl.rlim_max);
   int p[2];
   pipe(p);
   int pipe_size = fcntl(p[0] , 1032);
   printf("current pipr buffer size : %d bytes\n" , pipe_size);
   close(p[0]);
   close(p[1]);
   return 0;
}

/*
======================================================================================================================================================================================
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ ^C
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ gcc 23.c -o 23
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ ./23
max open files(soft limit) : 1024
max open files(hard limit) : 1048576
current pipr buffer size : 65536 bytes
======================================================================================================================================================================================
*/


