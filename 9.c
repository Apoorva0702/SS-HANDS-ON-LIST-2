/*
======================================================================================================================================================================================
name : 9.c
author : Apoorva Kharya 
description : Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal - Use signal system call.
date: 20 sept 2025
======================================================================================================================================================================================
*/


#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() {
    signal(SIGINT, SIG_IGN);
    printf("CTRL+C will not terminate the program for the next 5 secs.\n");
    sleep(5);

    signal(SIGINT, SIG_DFL);
    printf("\ntry Pressing CTRL+C .\n");
    sleep(5);

    return 0;
}

/*
======================================================================================================================================================================================
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ gcc 9.c -o 9
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ ./9
CTRL+C will not terminate the program for the next 5 secs.
^C^C
try Pressing CTRL+C .
^C
======================================================================================================================================================================================
*/
