#include <stdlib.h>
#include <stdio.h>
#include <unistd.h> //Pour sbrk

struct block_header
{
	unsigned int size : 29,
				 zero : 2,
				 alloc : 1;
}




void *debut_workspace_m=NULL;	//variable globale pour l'initialisation du workspace
void *fin_workspace_m;		//variable globale de fin du workspace

void* my_malloc(int size)
{
	/*Initialisation*/
    if (debut_workspace_m==NULL) 	//si c'est le premier appel de my_malloc, on crée un workspace
    {
        debut_workspace_m = sbrk(size);	//on stocke l'adresse du début du workspace en l'incrémentant de 'size'
        fin_workspace_m=sbrk(0);		//on stocke l'adresse de fin du workspace
    }
    void *position_debut_m = debut_workspace_m; //curseur début pour la recherche
	void *position_fin_m = debut_workspace_m; //curseur fin pour la recherche

	/*Questions: j'ai une adresse, comment savoir si il y a un block?
			j'ai une adresse comment mettre un block?*/

    /*Allocation d'un bloc entre 'debut_workspace_m' et 'fin_workspace_m'*/

}


void myfree(void *ptr)
{

}

