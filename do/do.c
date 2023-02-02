#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<assert.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include<assert.h>
#include <stdlib.h>
#include <signal.h>
#include "makeargv.h"
#include "truefalse.h"

int main(int argc, char const *argv[])
{
    assert(argc > 2);
    int i=1;
    int cut = 0, kil = 0, size = 0;

    char op = '&';

    char **cmds;
    if (strcmp(argv[1], "-o") == 0){
        op = '|';
        i++;
    }
    else if (strcmp(argv[1], "-a") == 0){
        i++;
    }
    if (strcmp(argv[1], "-c") == 0 || strcmp(argv[2], "-c") == 0){
        cut=1;
        i++;
        if (strcmp(argv[3], "-k") == 0 || strcmp(argv[2], "-k") == 0){
            kil=1;
            i++;
        }
    }

    size = argc-i;
    pid_t pid[size];
    int status[size];
    int j=0;

  while(i<argc){
    cmds = makeargv(argv[i]);
    pid[j]=fork();
              switch(pid[j]){
              case -1:
              perror("erreur dans  fork\n");
              exit(EXIT_FAILURE);
              break;
              case 0:
              printf("Lancement de l'execution de: %s\n", argv[i]);
              execvp(cmds[0], cmds);
              perror("erreur d'excution (exec)\n");
              exit(EXIT_FAILURE);
            }
      i++;
      j++;
    }
  int res= EXIT_FAILURE;
    if (op == '|'){
        res = EXIT_SUCCESS;
        for(i=0; i<argc-size; i++){
            wait(&status[i]);
            if (cut && !WEXITSTATUS(status[i])){
                printf("%d\n", kil);
                if (kil){
                    while (++i < argc-size){
                        kill(pid[i], SIGKILL);
                    }
                    printf("Process killed!\n");
                }
                exit(EXIT_SUCCESS);
            }
            res= res || WEXITSTATUS(status[i]);
        }
    }
    else{
        res = EXIT_SUCCESS;
        for(i=0; i<argc-size; i++){
            wait(&status[i]);
            if (cut && WEXITSTATUS(status[i])){
                if (kil){
                    while(++i < argc-size){
                        kill(pid[i], SIGKILL);
                    }
                    printf("Process killed!\n");
                }
                exit(EXIT_FAILURE);
            }
            res+= WEXITSTATUS(status[i]);
        }
        if(res!=0)
            res = EXIT_FAILURE;
    }
    freeargv(cmds);
    exit(res);
}
