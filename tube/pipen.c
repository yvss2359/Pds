#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <wait.h>
#include <unistd.h>
#include <string.h>
#include "makeargv.h"


int main(int argc, char**argv){

    if(argc < 4 || strcmp(argv[2], "to") != 0){
        printf("invalid arguments\n");
        exit(EXIT_FAILURE);
    }

    int fds[2], i=1;
    int old_fd;
    pid_t pid;
    char **c;

    old_fd = 0;

    while(i < argc-2 && argv[i]!=NULL){
        assert(pipe(fds)!=-1);
        pid = fork();
        switch(pid){
            case -1:
                exit(EXIT_FAILURE);
        case 0:
            c = makeargv(argv[i]);
            dup2(fds[1], 1);
            dup2(old_fd, 0);
            execvp(c[0],c);
            assert(0);

        default:
            close(fds[1]);
            close(old_fd);
            old_fd = fds[0];
            wait(NULL);
        }
        i+=2;
    }

    
    pid = fork();
    switch(pid){
        case -1:
            exit(EXIT_FAILURE);
        case 0:
            c = makeargv(argv[i]);
            dup2(old_fd, 0);

            execvp(c[0], c);
            assert(0);

        default:
            close(old_fd);
            close(0);
            wait(NULL);
    }
    
    exit(EXIT_SUCCESS);
}


