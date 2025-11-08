/*
======================================================================================================================================================================================
name : 10b.c
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


void Interrupt_handler(int sig, siginfo_t *info, void *context) {
	printf("\nInterrupt signal caught\n");
	printf("signal number: %d\n", sig);
	printf("signal code: %d\n", info->si_code);
	printf("This code will conitnue to run even after cntrl + c\npress cntrl + c to see this message again.\npress cntrl+\\ to exit (SIGQUIT)\n");
}


int main (){
	struct sigaction s;
	s.sa_sigaction = Interrupt_handler;
	s.sa_flags = SA_SIGINFO;

	sigaction(SIGINT, &s, NULL);
	
	printf("\npress cntrl + c to register the SIGINT signal\n");
	while (1) {
        	pause();
	}
}

/*
======================================================================================================================================================================================
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ gcc 10b.c -o 10b
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ ./10b

press cntrl + c to register the SIGINT signal
^C
Interrupt signal caught
signal number: 2
signal code: 128
This code will conitnue to run even after cntrl + c
press cntrl + c to see this message again.
press cntrl+\ to exit (SIGQUIT)
======================================================================================================================================================================================
*/
