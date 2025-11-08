/*
======================================================================================================================================================================================
name : 18.c
author : Apoorva Kharya 
description : Write a program to find out total number of directories on the pwd.
              execute ls -l | grep ^d | wc ? Use only dup2. 
date: 20 sept 2025
======================================================================================================================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
  int fd1[2], fd2[2];
  pipe(fd1);
  pipe(fd2);
  pid_t l, g;
  if((l==fork())==0){
     close(fd1[0]);
     close(fd2[0]);
     close(fd2[1]);
     dup2(fd1[1],1);
     close(fd1[1]);
     execlp("ls", "ls", "-l", (char*) NULL);

 }
  else if((g==fork())==0){
         close(fd1[1]);
         close(fd2[0]);
	 dup2(fd2[1],1);
	 close(fd2[1]);
	 dup2(fd1[0],0);
	 close(fd1[0]);
	 execlp("grep","grep","^d", (char*) NULL);
 }
 else{
         close(fd2[1]);
         close(fd1[0]);
         close(fd1[1]);
	 dup2(fd2[0],0);
	 close(fd2[0]);
	// close(fd2[1]);
	waitpid(l, NULL, 0);
        waitpid(g, NULL, 0);
	 execlp("wc","wc",(char*) NULL);


}
}

/*
======================================================================================================================================================================================
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ gcc 18.c -o 18
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ ./18
     11     102     780
======================================================================================================================================================================================
*/
