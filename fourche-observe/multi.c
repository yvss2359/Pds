#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>

typedef int (*func_t) (char *);

struct res
{
    int *  results;
};

int testfunc_sleep(char * c){
    if(strncmp(c ,"true",4)==0){

        sleep(5);
        return EXIT_SUCCESS;
    }
    if (strncmp(c ,"false",5)==0)
    {
;
        sleep(2);
        return EXIT_FAILURE;
    } 
    return EXIT_FAILURE;

}


int testfunc( char* c){
    if(strncmp(c ,"true",4)==0){
        //printf("success\n");
        //fflush(stdout);
        return EXIT_SUCCESS;
    }
    if (strncmp(c ,"false",5)==0)
    {
        //printf("failure\n");
        //fflush(stdout);
        return EXIT_FAILURE;
    } 
    return EXIT_FAILURE; 
}



int multif (func_t f[], char *args[], int n){
    pid_t pid;
    
    for(int i =0; i<n; i++){
        pid=fork();
        switch(pid){
            case -1:
                perror("error fork");
                exit(EXIT_FAILURE);
            case 0: 
                exit(f[i](args[i])); 
        }
    }
    int result = EXIT_SUCCESS;
    int status;
    for (int i = 0; i < n; i++)
    {
        wait(&status);
        if(WIFEXITED(status)  ){
            if(WEXITSTATUS(status)== EXIT_FAILURE){
                result = EXIT_FAILURE;
            }
        }
    }
    return result ;
}


int main(int argc, char * argv[])
{   
    assert(argc>=2);
    
    func_t* f=(func_t*)malloc(sizeof(func_t)*argc-1);
    assert(f!=NULL);
    
    for(int i = 0 ; i<argc-1; i++ ){
        f[i] = testfunc_sleep;
    }
    if(multif(f,argv+1,argc)== EXIT_SUCCESS){
        printf("SUCCESS\n");
        exit(EXIT_SUCCESS);
    }else{
        printf("FAILURE\n");
        exit(EXIT_FAILURE);
    }
    //printf("%d \n",multif(f,argv+1,argc));
}
