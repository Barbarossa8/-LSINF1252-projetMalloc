#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void *debut_workspace_m;
void *fin_workspace_m;


int main(int argc, char *argv[])
{
	debut_workspace_m=sbrk((int)argv[1]);
	fin_workspace_m=sbrk(0);
	block_header header={(int)argv[1],0,0};
	debut_workspace=header;
	return 0;
}


