#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "code.h"

void *debut_workspace_m;
void *fin_workspace_m;


int main(int argc, char *argv[])
{
	unsigned int capacity=atoi(argv[1]);
	debut_workspace_m = sbrk(capacity);
	
//printf("%d",atoi(argv[1]));
	fin_workspace_m = sbrk(0);
	struct block_header *header=(struct block_header*)debut_workspace_m;
	header->size=capacity;
	header->zero=0;
	header->alloc=0;
	//mini tests
	void* a=my_malloc(8);
	void* b=my_calloc(16);
	void* c=my_calloc(10);
	void* d=my_calloc(14);
	printf("prend 4: %d \n",&a[0]-&debut_workspace_m[0]);
	printf("prend 12: %d \n",&b[0]-&a[0]);
	printf("prend 20: %d \n",&c[0]-&b[0]);
	printf("prend 16: %d \n",&d[0]-&c[0]);
	return 0;
}


