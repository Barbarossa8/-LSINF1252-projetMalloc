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

	fin_workspace_m = sbrk(0);
	struct block_header *header=(struct block_header*)debut_workspace_m;
	header->size=capacity;
	header->zero=0;
	header->alloc=0;
	
	//mini tests
	void* a=my_malloc(8);
	void* b=my_malloc(10);
	void* c=my_malloc(4);
	
	printf("\nadresse malloc(8): %p \n",a);
	a-=4;
	struct block_header *headera=(struct block_header*) a;
	printf("alloué: %d \n",headera->alloc);
	printf("size: %d \n",headera->size);
	
	printf("\nadresse malloc(10): %p \n",b);
	b-=4;
	struct block_header *headerb=(struct block_header*) b;
	printf("alloué: %d \n",headerb->alloc);
	printf("size: %d \n",headerb->size);

	printf("\nadresse malloc(4): %p \n",c);
	c-=4;
	struct block_header *headerc=(struct block_header*) c;
	printf("alloué: %d \n",headerc->alloc);
	printf("size: %d \n",headerc->size);
	c+=headerc->size;
	printf("\nadresse fin malloc(4): %p ",c);
	printf("\nadresse fin : %p \n",fin_workspace_m);

	my_free(a+4);

	//Après le free de a
	printf("\nadresse malloc(8): %p \n",a+4);
	//a-=4;
	headera=(struct block_header*) a;
	printf("alloué: %d \n",headera->alloc);
	printf("size: %d \n",headera->size);
	
	my_free(b+4);
	//Après le free de b
	printf("\nadresse malloc(10): %p \n",b+4);
	//b-=4;
	headerb=(struct block_header*) b;
	printf("alloué: %d \n",headerb->alloc);
	printf("size: %d \n",headerb->size);

	//Ici on a donc a qui s'est mis avec b 
	printf("\nadresse malloc(8): %p \n",a+4);
	//a-=4;
	headera=(struct block_header*) a;
	printf("alloué: %d \n",headera->alloc);
	printf("size: %d \n",headera->size);
	return 0;
}


