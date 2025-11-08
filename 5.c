/*
======================================================================================================================================================================================
name : 5.c
author : Apoorva Kharya 
description : Write a program to print the system limitation of
a. maximum length of the arguments to the exec family of functions.
b. maximum number of simultaneous process per user id.
c. number of clock ticks (jiffy) per second.
d. maximum number of open files
e. size of a page
f. total number of pages in the physical memory
g. number of currently available pages in the physical memory.
date: 20 sept 2025
======================================================================================================================================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Maximum length of arguments to exec: %ld\n", sysconf(_SC_ARG_MAX));
    printf("Maximum number of processes per user id: %ld\n", sysconf(_SC_CHILD_MAX));
    printf("Number of clock ticks per second: %ld\n", sysconf(_SC_CLK_TCK));
    printf("Maximum number of open files: %ld\n", sysconf(_SC_OPEN_MAX));
    printf("Page size: %ld\n", sysconf(_SC_PAGESIZE));
    printf("Total number of pages in physical memory: %ld\n", sysconf(_SC_PHYS_PAGES));
    printf("Available number of pages in physical memory: %ld\n", sysconf(_SC_AVPHYS_PAGES));
    return 0;
}


/*
======================================================================================================================================================================================
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ gcc 5.c -o 5
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ ./5
Maximum length of arguments to exec: 2097152
Maximum number of processes per user id: 62317
Number of clock ticks per second: 100
Maximum number of open files: 1024
Page size: 4096
Total number of pages in physical memory: 4034950
Available number of pages in physical memory: 2398421
======================================================================================================================================================================================
*/
