#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>



int comptage(int n){

    for(int i=0; i<100000000; i++){
    }
    printf("je suis le fils num : %d\n",n);
    for(int i=0; i<100000000; i++){
    }
    return n;
}


int tab[10];

int course(){

    pid_t pid;
    
    for(int i =0; i<10; i++){
        pid=fork();
        switch(pid){
            case -1:
                perror("error fork");
                exit(EXIT_FAILURE);
            case 0: 
                exit(comptage(i)); 
        }
    }

    
    int status;
    for (int i = 0; i < 10; i++)
    {
        wait(&status);
        tab[i]=WEXITSTATUS(status);
    }
    return 0;
}

int main(){
    printf("\n");
    printf("===============depart=============\n");
    course();
    
    printf("\n");
    printf("===============arrive=============\n");
    for(int i =0 ; i<10; i++){
    printf("je suis le fils num : %d\n", tab[i]);
    }
}