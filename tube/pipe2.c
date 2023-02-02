#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <wait.h>
#include <unistd.h>
#include <string.h>
#include "makeargv.h"

int main(int argc, char**argv){
    if(argc != 4 || strcmp(argv[2], "to") != 0){
        printf("arguments invalides\n");
        exit(EXIT_FAILURE);
    }

    else{
        
        pid_t pid;
        int fds[2];
        char **c;
        assert(pipe(fds)!=-1);
        pid = fork();
        switch(pid){
            case -1 : 
                exit(EXIT_FAILURE);
            case 0 : 
                c = makeargv(argv[1]);
                close(fds[0]);
                dup2(fds[1], 1);
                execvp(c[0],c);
                assert(0);
            default:
                close(fds[1]);
                pid = fork();
                switch(pid){
                case -1:
                    exit(EXIT_FAILURE);
                case 0:
                    dup2(fds[0], 0);
                    c = makeargv(argv[3]);
                    execvp(c[0],c);
                    assert(0);
                default:;
                }
                

                close(fds[0]);
                close(fds[1]);
                wait(NULL);
                wait(NULL);
        }

    }

}
