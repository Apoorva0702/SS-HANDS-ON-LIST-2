/*
======================================================================================================================================================================================
name : 12.c
author : Apoorva Kharya 
description :Write a program to create an orphan process. Use kill system call to send SIGKILL signal to
             the parent process from the child process.
date: 20 sept 2025
======================================================================================================================================================================================
*/


#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>

int main(){
   pid_t id;
   id = fork();
   if(id ==0){
      printf("Child process with pid %d and parent pid %d.\n",getpid(), getppid());
      printf("Sending signal to kill the parent.\n");
      kill(getppid(), SIGKILL);
      printf("Parent killed.\n");
   }
   else{
     printf("Parent process created.\n");
     sleep(6);
     printf("Parent process terminating.\n");
   }
 
   return 0;
}

/*
======================================================================================================================================================================================
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ gcc 12.c -o 12
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ ./12
Parent process created.
Child process with pid 5247 and parent pid 5246.
Sending signal to kill the parent.
Parent killed.
Killed
======================================================================================================================================================================================
*/
