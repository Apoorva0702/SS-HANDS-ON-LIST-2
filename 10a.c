/*
======================================================================================================================================================================================
name : 10a.c
author : Apoorva Kharya 
description : Write a separate program using sigaction system call to catch the following signals.
            a. SIGSEGV
            b. SIGINT
            c. SIGFPE
date: 20 sept 2025
======================================================================================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>


void segfaulthandle(int sig, siginfo_t *info, void *context) {
	printf("\nSegmentation fault\n");
	printf("signal number: %d\n", sig);
	printf("faulty memory address: %p\n", info->si_addr);
	exit(sig);
}
int main (){
	struct sigaction s;
	s.sa_sigaction = segfaulthandle;
	s.sa_flags = SA_SIGINFO;

	sigaction(SIGSEGV, &s, NULL);
	
	int *ptr = NULL;
	*ptr = 42;
	return 0;
}

/*
======================================================================================================================================================================================
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ gcc 10a.c -o 10a
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ ./10a

Segmentation fault
signal number: 11
faulty memory address: (nil)
======================================================================================================================================================================================
*/
