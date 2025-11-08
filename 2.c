/*
======================================================================================================================================================================================
name : 2.c
author : Apoorva Kharya 
description : Write a program to print the system resource limits. Use getrlimit system call.
date: 20 sept 2025
======================================================================================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <unistd.h>

void print_limit(int resource, const char *name) {
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
    print_limit(RLIMIT_CPU, "CPU time");
    print_limit(RLIMIT_FSIZE, "File size");
    print_limit(RLIMIT_DATA, "Data seg size");
    print_limit(RLIMIT_STACK, "Stack size");
    print_limit(RLIMIT_CORE, "Core file size");
    print_limit(RLIMIT_NOFILE, "Open files");
#ifdef RLIMIT_AS
    print_limit(RLIMIT_AS, "Virtual memory");
#endif
    return 0;
}
/*
======================================================================================================================================================================================
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ gcc 2.c -o 2
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ ./2
CPU time soft limit: unlimited, hard limit: unlimited
File size soft limit: unlimited, hard limit: unlimited
Data seg size soft limit: unlimited, hard limit: unlimited
Stack size soft limit: 8388608, hard limit: unlimited
Core file size soft limit: 0, hard limit: unlimited
Open files soft limit: 1024, hard limit: 1048576
Virtual memory soft limit: unlimited, hard limit: unlimited
======================================================================================================================================================================================
*/
