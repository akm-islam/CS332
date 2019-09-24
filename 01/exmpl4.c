#include <unistd.h>
#include <stdio.h>
#include <memory.h>
int main (void) {
    int p,i,iw;
    char *argv[] = { "./child1.bat",NULL};
 
    printf("Before fork; my pid is %d\n",getpid());
    p=fork();
    if (p < 0 ) { 
       printf("Fork failed\n");
       return(1);   
    }
    if (  p  == 0 ) {  
          printf("Child :(p,pid,parentpid) = (%6d,%6d,%6d)\n",p,getpid(),getppid());
          execvp(argv[0],argv);
          printf("still in original child\n");
    }
    else {
          printf("Parent:(p,pid,parentpid) = (%6d,%6d,%6d)\n",p,getpid(),getppid());
          printf("Parent: I am the parent of %d\n",p);
    }
 printf("Someone's PID is %d. Who is it?\n",getpid());
 return(0);
}
