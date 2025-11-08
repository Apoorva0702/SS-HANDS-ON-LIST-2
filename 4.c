/*
======================================================================================================================================================================================
name : 4.c
author : Apoorva Kharya 
description : Write a program to measure how much time is taken to execute 100 getppid ( )
              system call. Use time stamp counter.
date: 20 sept 2025
======================================================================================================================================================================================
*/

#include <stdio.h>
#include <x86intrin.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

double getcpufreq() {
    int fd = open("/proc/cpuinfo", O_RDONLY);

    char buffer[8192];
    ssize_t bytes = read(fd, buffer, sizeof(buffer) - 1);
    close(fd);
    if (bytes <= 0) return -1;

    buffer[bytes] = '\0'; 
    char *pos = strstr(buffer, "cpu MHz");

    double mhz = -1.0;
    sscanf(pos, "cpu MHz\t: %lf", &mhz);

    return mhz / 1000.0; 
}

int main() {
    unsigned long long start, end, cycles;
    double time_ns;
    double cpu_freq = getcpufreq();

    start = __rdtsc();
    for(int i = 0; i < 100; i++)
    {
      getppid();
    }
    end = __rdtsc();

    cycles = end - start;
    time_ns = cycles / cpu_freq;

    printf("CPU frequency: %.2f GHz\n", cpu_freq);
    printf("System call took %llu cycles (~%.2f ns)\n", cycles, time_ns);

    return 0;
}

/*
======================================================================================================================================================================================
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ gcc 4.c -o 4
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ ./4
CPU frequency: 0.80 GHz
System call took 154616 cycles (~193227.97 ns)
======================================================================================================================================================================================
*/
