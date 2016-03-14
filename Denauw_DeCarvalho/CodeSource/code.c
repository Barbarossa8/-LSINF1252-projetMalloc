#include <stdlib.h>
#include <stdio.h>


struct block_header
{
	unsigned int size : 29,
				 zero : 2,
				 alloc : 1;
}



void *mymalloc(size_t size)
{

}


void myfree(void *ptr)
{

}













int main(int argc, char const *argv[])
{
	
	return 0;
}
