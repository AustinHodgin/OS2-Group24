#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <stdlib.h>


int main(void){
    long free_sp;
    long total_sp;
    float ratio;
    char * buffers[100];
    int i =0;
    time_t t;

    srand((unsigned) time(&t));

    for(i = 0; i<100; i++){
      buffers[i] = (char*) malloc (rand() + 1);
    }

    free_sp = syscall(359);
    total_sp = syscall(360);
    ratio = ((float)free_sp/(float)total_sp);
    printf("free space: %lu\n",free_sp);
    printf("total space: %lu\n\n",total_sp);

    printf("free/total: %f\n",ratio);
    return 0;
}
