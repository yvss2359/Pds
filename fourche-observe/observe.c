#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>
#include <signal.h>

#define N 3

int main(){
    pid_t pid;
    //int status;
    for(int i=0; i<N; i++){
        pid=fork();
        switch(pid){
            case -1:
                perror("error fork");
                exit(EXIT_FAILURE);
            case 0: 
                while (1){
                    printf("je suis le fils %d et je suis toujours vivant , et mon père est %d\n", getpid(), getppid());
                    fflush(stdout);
                    sleep(5);
                }
        }
    }
        
    assert(system("ps -a")!=-1);
    while (wait(NULL)!=-1){
        printf("processus terminé");
    }   
}