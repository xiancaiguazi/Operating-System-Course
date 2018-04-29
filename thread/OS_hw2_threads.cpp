#include <pthread.h>
#include <stdio.h>

int primes[1000];
void *f(void *x)

{

	int *n=(int *)x;
	printf("%d\n",n);
 }

int main()

{

pthread_t tid[2];
int i;

for(i=0;i<2;i++)

pthread_create(tid+i,NULL,f,(void *)i);

printf("%d\n",4);

for(i=0;i<2;i++)

{

	pthread_join(tid[i],NULL);
	printf("%d\n",i+2);

}

pthread_join(tid[0],NULL);
return 0;
}