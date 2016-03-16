#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "code.h"
#include <string.h>


/*METHODE ALIGN
    @pre: prend un int (size_to_align)
    @post: retourne un int aligné en multiple de 4
*/
int align(int size_to_align)
{
    if (size_to_align % 4 !=0)
	{
		return size_to_align+(4-(size_to_align%4));
	}
    else return size_to_align;
}

void my_fragmentation()
{
	void* position=debut_workspace_m;
	void* next=debut_workspace_m;
    while(position<fin_workspace_m)
    {
        struct block_header* block_position=(struct block_header*)position;
        next+=block_position->size;
        if(next<fin_workspace_m)
        {
        	struct block_header* block_next=(struct block_header*)next;
        	if(block_position->alloc==0 && block_next->alloc==0)//pas alloué on regarde si le suivant l'est
        	{
			printf("ok\n");
        	    block_position->size+=block_next->size;//On fusionne la taille des deux
        	    //comment faire disparaitre un header?
        	}
        	else
        	{
printf("okelse\n");
        	    position=next;
        	}
        }
        else
        {
            position=fin_workspace_m;
        }
    }
}

/*METHODE MY_MALLOC
    @pre size est la taille dont on veut disposer dans le heap créé
    @post retourne un pointeur vers une zone memoire de taille size alligné
*/
void* my_malloc(int size)
{
	size=align(size);
	int notFound=0;
	void *position=debut_workspace_m;
	while(notFound==0)
	{	if(position==fin_workspace_m)
		{
			notFound=1;
			return NULL;
		}
		struct block_header* block_position=(struct block_header*)position;
		if(block_position->alloc==0 && (block_position->size) >= (size+4)) //si on peut allouer et assez grand
		{
			unsigned int block_size=(block_position->size)-size-4;
			block_position->size=size+4;	//on donne la taille au block
			block_position->alloc=1;	//on dit que le block est alloue
			void* final_position=position;	//on stocke la position du bloc libéré voulu
			struct block_header* header= (struct block_header*) position;
			position+=header->size;		//on va a la fin du block que l'on vient d'allouer
			if(position!=fin_workspace_m)
			{
				struct block_header* new_header=(struct block_header*)position;
				new_header->size=block_size;
				new_header->zero=0;
				new_header->alloc=0;	//on met le block header contenant les info sur ce qu'il reste du block initial
			}
			notFound=1;	//inutile mais pour faire propre
			return final_position+4;	//retourne la position du block voulu
		}
		else
		{
			struct block_header* header= (struct block_header*) position;
			position+=header->size;
		}
	}

}


/*METHODE MY_CALLOC
    @pre size est la taille dont on veut disposer dans le heap créé
    @post retourne un pointeur vers une zone memoire initialisée à zéro de taille size alligné
*/
void* my_calloc(int size)
{
    void* block=my_malloc(size);
    return memset(block,0,align(size)); //Rempli la mémoire de constantes 0 à partir du pointeur block

}


/*METHODE MY_FREE
    @pre Prend un pointeur à partir duquel nous voulons libérer de la mémoire
    @post Ne retourne rien permet juste de libérer la mémoire associée au pointeur ptr et appelle fragmentation
*/
void my_free(void *ptr)
{
	ptr-=4;
	struct block_header *header_to_free=(struct block_header*) ptr;
	header_to_free->alloc=0;    //on dit que c'est free
	my_fragmentation();     //on fragmente
}



