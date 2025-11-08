/*
======================================================================================================================================================================================
name : 3.c
author : Apoorva Kharya 
description : 3. Write a program to set (any one) system resource limit. Use setrlimit system call.
date: 20 sept 2025
======================================================================================================================================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <unistd.h>

void printlimit(int resource, const char *name) {
    struct rlimit rl;
    if (getrlimit(resource, &rl) == 0) {
        if (rl.rlim_cur == RLIM_INFINITY)
            printf("%s soft limit: unlimited, ", name);
        else
            printf("%s soft limit: %ld, ", name, (long)rl.rlim_cur);
        if (rl.rlim_max == RLIM_INFINITY)
            printf("hard limit: unlimited\n");
        else
            printf("hard limit: %ld\n", (long)rl.rlim_max);
    }
}

int main() {
    struct rlimit l;
    printf("Before: ");
    printlimit(RLIMIT_FSIZE, "File size");
    
    l.rlim_cur = 1024 * 1024;
    l.rlim_max = 2 * 1024 * 1024;
    setrlimit(RLIMIT_FSIZE, &l);
    printf("\nAfter: ");
    printlimit(RLIMIT_FSIZE, "File size");

    return 0;
}

/*
======================================================================================================================================================================================
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ gcc 3.c -o 3
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ ./3
Before: File size soft limit: unlimited, hard limit: unlimited

After: File size soft limit: 1048576, hard limit: 2097152
======================================================================================================================================================================================
*/
