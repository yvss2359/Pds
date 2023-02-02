#include<unistd.h>
#include<stdio.h>
#include<assert.h>
#include<wait.h>
#include<assert.h>
#include <stdlib.h>
#include <string.h>
#include"makeargv.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>



int main(int argc,char *argv[]){
     if(argc != 6 || strcmp(argv[2], "to") != 0 || strcmp(argv[4],"to") != 0){
        printf("arguments invalides\n");
        exit(EXIT_FAILURE);
    }

    else{
			pid_t pid;
			int fds[2],fds2[2];
			int fd,f;
			char** c;
			assert(pipe(fds) != -1);
			assert(pipe(fds2) != -1);
			pid= fork();

		switch(pid){
			case -1:
				perror("erreur dans le fork");
				exit(EXIT_FAILURE);
			break;

			case 0:
				fd=dup2(fds[1],STDOUT_FILENO);
				assert(fd!=-1);
				close(fds[1]);
				close(fds[0]);
				close(fds2[1]);
				close(fds2[0]);
				c=makeargv(argv[1]);
				execvp(c[0],c);
				assert(0); 
			default:;
			}

			pid=fork();
			switch(pid) {
				case -1:
					perror("erreur dans le fork");
					exit(EXIT_FAILURE);
				break;
				case 0:
					fd=dup2(fds[0],STDIN_FILENO);
					f=dup2(fds2[1],STDOUT_FILENO);
					assert(fd!=-1);
					assert(f!=-1);
						close(fds[1]);
						close(fds2[0]);
						close(fds[0]);
						close(fds2[1]);
					c=makeargv(argv[3]);
					execvp((c[0]),c);   
					assert(0); 
				break;
				default:;
			}
			

			pid=fork();
			switch(pid) {
				case -1:
					perror("erreur dans le fork");
					exit(EXIT_FAILURE);
				break;
				case 0:
					fd=dup2(fds2[0],STDIN_FILENO);
					close(fds2[1]);
					close(fds2[0]);
					close(fds[0]);
					close(fds[1]);
					assert(fd!=-1);
					c=makeargv(argv[5]);
					execvp((c[0]),c);   
					assert(0); 
				break;
				default:;
        	}      
         close(fds[0]);
         close(fds[1]);
         close(fds2[0]);
         close(fds2[1]);
         wait(NULL);
         wait(NULL);
         wait(NULL);
         exit(EXIT_SUCCESS);
    }
    
}

    

