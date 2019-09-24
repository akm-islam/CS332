#include <unistd.h>
#include <stdio.h>
#include <memory.h>
int main (void) {
    int p,i;
    int a[10];
 
    memset((char*)a,0,10*sizeof(int));
    printf("Before fork; my pid is %d\n",getpid());
    p=fork();
    if (p < 0 ) { 
       printf("Fork failed\n");
       return(1);   /* return(0) is normal termination; nonzero is abnormal */
    }
    if (  p  == 0 ) {  /*  Child */
          printf("Child  (p,pid,parentpid) = (%6d,%6d,%6d)\n",p,getpid(),getppid());
          for(i=0;i<10;i++) a[i]= 100;
          printf("%d\n",a[5]);
    }
    else {
          printf("Parent (p,pid,parentpid) = (%6d,%6d,%6d)\n",p,getpid(),getppid());
	  sleep(5);
          for(i=0;i<10;i++) a[i]= 200;
          printf("%d\n",a[5]);
    }
 if (p==0) {
    sleep(6);
    printf("%d\n",a[5]);
 }
 else {
    printf("%d\n",a[5]);
 }
 return(0);
}
