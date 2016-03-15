
struct block_header;

/*METHODE ALIGN
    @pre: prend un int (size_to_align)
    @post: retourne un int aligné en multiple de 4
*/
int align(int size_to_align);


/*METHODE MY_MALLOC
    @pre size est la taille dont on veut disposer dans le heap créé
    @post retourne un pointeur vers une zone memoire de taille size alligné
*/
void *my_malloc(size_t size);


/*METHODE MY_FREE
    @pre Prend un pointeur à partir duquel nous voulons libérer de la mémoire
    @post Ne retourne rien permet juste de libérer la mémoire associée au pointeur ptr
*/
void my_free(void *ptr)
{

}


/*METHODE MY_CALLOC
    @pre size est la taille dont on veut disposer dans le heap créé
    @post retourne un pointeur vers une zone memoire initialisée à zéro de taille size alligné
*/
void *my_calloc(size_t size);


int main(int argc, char const *argv[]);
