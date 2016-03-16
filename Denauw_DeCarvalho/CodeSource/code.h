struct block_header
{
	unsigned int size : 29,
		     zero : 2,
		     alloc : 1;
};

unsigned int SIZE;


void* my_malloc(int size);
void* my_calloc(int size);
void my_free(void *ptr);
