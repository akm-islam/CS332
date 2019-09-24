#include <unistd.h>
#include <stdio.h>
 /* fork returns 0 to the child process and the pid of the child process to the parent */ 
int main (void) {
    int p;
 
    printf("Before fork; my pid is %d\n",getpid());
    p=fork();
    if (p < 0 ) { /* Negative indicates failure of fork call */
       printf("Fork failed\n");
       return(1);   /* return(0) is normal termination; nonzero is abnormal */
    }
    if (  p  == 0 ) {  /*  Child */
          printf("Child  (p,pid,parentpid) = (%6d,%6d,%6d)\n",p,getpid(),getppid());
              return(0);
    }
    else {
          printf("Parent (p,pid,parentpid) = (%6d,%6d,%6d)\n",p,getpid(),getppid());
	  /* sleep(10); */
          return(0);
    }
}
