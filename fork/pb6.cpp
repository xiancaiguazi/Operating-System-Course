#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>
using namespace std;


void foo(int n)
{
  int i;
  for(i = 0;i < n;i++)
  	fork();
  printf("hello\n");
  exit(0);
}

int main()
{
	foo(4);
	return 0;
}
