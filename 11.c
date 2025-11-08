/*
======================================================================================================================================================================================
name : 11.c
author : Apoorva Kharya 
description : Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal - use sigaction system call.
date: 20 sept 2025
======================================================================================================================================================================================
*/
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() {
    struct sigaction sa;

    sa.sa_handler = SIG_IGN;
    sa.sa_flags = 0;
    sigaction(SIGINT, &sa, NULL);

    printf("CTRL+C will not terminate the code for the next 5 seconds.\n");
    sleep(5);

    sa.sa_handler = SIG_DFL;
    sigaction(SIGINT, &sa, NULL);

    printf("\nTry Pressing CTRL+C now.\n");
    sleep(5);

    return 0;
}

/*
======================================================================================================================================================================================
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ gcc 11.c -o 11
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ ./11
CTRL+C will not terminate the code for the next 5 seconds.
^C^C
Try Pressing CTRL+C now.
^C
======================================================================================================================================================================================
*/
