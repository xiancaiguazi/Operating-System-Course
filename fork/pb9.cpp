//this program uses fork() to print Fibonacci.

#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>

int main(int argc, char* argv[])
{  
  pid_t pid;         
  int i;          
  int f0,f1,f2;         
  f0=0;         
  f1=1;
  
//check illegal input  
  if(argv[1]<0)         
{               
  fprintf(stderr,"please input an integer!\n");   
}

//create son process
  pid=fork();  
          
  if(pid<0)           //check if created correctly  
{   
  fprintf(stderr,"fork failed");   exit(-1);  
}  
  else if(pid==0)     //print in the son process
{               
        
        printf("0 1 ");      //first two number
              for(i=2; i<=atoi(argv[1]);i++)          //following number    note:atoi() means ASCII to integer     
                 {                    
                    f2=f0+f1;                   
                    f0=f1;                   
                    f1=f2;                    
                    printf("%d ",f2);              
                 }
        printf("\nchild process completed\n");  
}
// in the parent process
else  
    {   
      wait(NULL);   
      printf("parent process exited");     
    } 
return 0; 
} 
