//this program uses fork() to print Fibonacci.

#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>
#include <sys/types.h>// using wait()
#include <sys/wait.h>

int main(int argc, char* argv[])
{  
  pid_t pid;         
  int i;          
  int f0,f1,f2;         
  f0=0;         
  f1=1;
  int num = atoi(argv[1]);
  
//check illegal input  
  if( num < 0)   
{               
  fprintf(stderr,"Error!!! Please input a positive integer!\n");
  return 0;   
}

//create son process
  pid=fork();  
          
  if(pid<0)           //check if created correctly  
{   
  fprintf(stderr,"fork failed");   
  exit(-1);  
}  

  else if(pid==0)     //print in the son process
{               
       switch(num)
       {
        case 1:printf("0 \n");    break;    //first  number
        case 2:printf("0 1 \n");  break;    //first two numbers
        default:{
                  printf("0 1 ");    
                  for(i=3; i <= num;i++)          //following number    note:atoi() means ASCII to integer     
                       {                    
                          f2=f0+f1;                   
                          f0=f1;                   
                          f1=f2;                    
                          printf("%d ",f2);              
                       }
                  printf("\n");
               }
       }
        
       //printf("\nchild process completed\n");  
}
// in the parent process
else  
    {   
      wait(NULL);   
      //printf("parent process exited");     
    } 


return 0; 
} 
