#include <CUnit/CUnit.h> 
#include "code.h"
#include <stdio.h>
#include <unistd.h>

/* TEST ALIGN */
void test_align(void)
{
	CU_ASSERT_EQUAL(align(150),152);
	CU_ASSERT_EQUAL(align(1),4);
	CU_ASSERT_EQUAL(align(9),12);
	CU_ASSERT_EQUAL(align(4),4);
	CU_ASSERT_EQUAL(align(15),16);
}


/* TEST MY_MALLOC */
void test_my_malloc(void)
{
	void* allouer=my_malloc(-10);
	CU_ASSERT_PTR_NULL(allouer);

	void * allou=mymalloc(0);
	struct block_header *allou = (struct block_header *)(allou-4);
}

/* TEST MY_CALLOC */
void test_my_calloc(void)
{
	void* allouer=my_calloc(16);
	int *i;
	int v;
	for (v = 0; v < 16; i++)
	{
		i=(int *) (allouer+v);	//Verif si les autres valeurs non-allouées sont mises à zero
		if (*i!=0)
		{
			CU_FAIL("Différent de zéro");	//Une des valeur n'a pas été mise à zéro
			break;
		}
	}

    CU_PASS("Les tests passent");	//Les valeurs sont bonnes
}


/* TEST MY_FREE */
void test_my_free(void)
{
	int *i
	i=(int*)malloc(sizeof(int));

	my_free(i);
	CU_ASSERT_PTR_NOT_NULL(i);
}


/* TESTS DE PERFORMANCES */

//my_malloc face au true_malloc
void temps_my_malloc()
{
	int a = gettimeofday();
	my_malloc(100);
	int b = gettimeofday();
	printf("Temps pour my_malloc: %d\n", b-a);
}

void temps_true_malloc()
{
	int a = gettimeofday();
	malloc(100);
	int b = gettimeofday();
	printf("Temps pour true_malloc: %d\n", b-a);
}

//my_calloc face au true_calloc
void temps_my_calloc()
{
	int a = gettimeofday();
	my_calloc(100);
	int b = gettimeofday();
	printf("Temps pour my_calloc: %d\n", b-a);
}

void temps_true_calloc()
{
	int a = gettimeofday();
	calloc(100);
	int b = gettimeofday();
	printf("Temps pour true_calloc: %d\n", b-a);
}

//my_free face au true_free
void temps_my_free()
{
	int *i
	i=(int*)malloc(sizeof(int));

	int a = gettimeofday();
	my_free(i);
	int b = gettimeofday();
	printf("Temps pour my_free: %d\n", b-a);
}

void temps_true_free()
{
	int *i
	i=(int*)malloc(sizeof(int));

	int a = gettimeofday();
	free(i);
	int b = gettimeofday();
	printf("Temps pour true_free: %d\n", b-a);
}

int main(int argc, char const *argv[])
{
	SIZE=atoi(argv[1]); //La taille est stockée dans une variable globale

	if (CUE_SUCCESS != CU_initialize_registry())
	{
		return CU_get_error();
	}
	CU_pSuite pSuiteProjet = NULL;
	pSuiteProjet = CU_add_suite("Test des fonctions du projet",NULL,NULL);
	if (pSuiteProjet == NULL)
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	CU_TestFunc testMyMalloc = &test_my_malloc;
	CU_add_test(pSuiteProjet,"Test my_malloc()", testMyMalloc);
	if (testMyMalloc == NULL)
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	CU_TestFunc testMyCalloc = &test_my_calloc;
	CU_add_test(pSuiteProjet,"Test my_calloc()", testMyCalloc);
	if (testMyCalloc == NULL)
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	CU_TestFunc testAlign = &test_align;
	CU_add_test(pSuiteProjet,"Test align()", testAlign);
	if (testAlign == NULL)
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	//On lance les tests et on les affiche

	CU_basic_run_tests();
	CU_basic_show_failures(CU_get_failure_list());

	return EXIT_SUCCESS;
}
