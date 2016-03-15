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
	void* a=my_malloc(8);
	//void* b=my_malloc(160);
	//void* c=my_malloc(10);
	//void* d=my_malloc(100000);
	printf("a: %p \n",a);
	//printf("16+4: %d \n",&b[0]- &a[0]);
	//printf("160+4: %d \n",&c[0]-&b[0]);
	//printf("null: %d",d!=NULL);
	return 0;
}

