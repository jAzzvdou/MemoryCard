#include "memorycard.h"

void	test_default_with_free(void)
{
	//| Teste com qualquer tipo (sem 'content').
	printf(YELLOW"| DEFAULT TYPE |\n"RESET);

	//----------| VOID * |----------//
	printf(ORANGE"_void *_\n"RESET);
	void *ptr = memcard(NULL, DEFAULT, MALLOC, 1);
	memcard(ptr, STATUS, 0, 0);
	ptr = memcard(ptr, DEFAULT, FREE, 0);
	ptr = memcard(ptr, DEFAULT, FREE, 0); //| Teste de double free.
	memcard(ptr, STATUS, 0, 0);

	//----------| CHAR * |----------//
	printf(ORANGE"_char *_\n"RESET);
	char *str = memcard(NULL, DEFAULT, MALLOC, 1);
	memcard(str, STATUS, 0, 0);
	str = memcard(str, DEFAULT, FREE, 0);
	str = memcard(str, DEFAULT, FREE, 0); //| Teste de double free.
	memcard(str, STATUS, 0, 0);

	//----------| INT * |----------//
	printf(ORANGE"_int *_\n"RESET);
	int *nbs = memcard(NULL, DEFAULT, MALLOC, 1);
	memcard(nbs, STATUS, 0, 0);
	nbs = memcard(nbs, DEFAULT, FREE, 0);
	nbs = memcard(nbs, DEFAULT, FREE, 0); //| Teste de double free.
	memcard(nbs, STATUS, 0, 0);

	//----------| DOUBLE * |----------//
	printf(ORANGE"_double *_\n"RESET);
	double *ds = memcard(NULL, DEFAULT, MALLOC, 1);
	memcard(ds, STATUS, 0, 0);
	ds = memcard(ds, DEFAULT, FREE, 0);
	ds = memcard(ds, DEFAULT, FREE, 0); //| Teste de double free.
	memcard(ds, STATUS, 0, 0);

	//----------| LIST * |----------//
	printf(ORANGE"_list *_\n"RESET);
	t_memnode *node = memcard(NULL, DEFAULT, MALLOC, sizeof(t_memnode));
	memcard(node, STATUS, 0, 0);
	node = memcard(node, DEFAULT, FREE, 0);
	node = memcard(node, DEFAULT, FREE, 0);
	memcard(node, STATUS, 0, 0);
}

void	test_string_with_free(void)
{
	//| Teste com STRING (com ou sem 'content').
	printf(YELLOW"| STRING TYPE |\n"RESET);

	printf(ORANGE"_without content_\n"RESET);
	char *s0 = memcard(NULL, STRING, MALLOC, 1);
	memcard(s0, STATUS, 0, 0);
	s0 = memcard(s0, STRING, FREE, 0);
	s0 = memcard(s0, STRING, FREE, 0); //| Teste de double free.
	memcard(s0, STATUS, 0, 0);

	printf(ORANGE"_with content_\n"RESET);
	char *s1 = memcard("Ok", STRING, MALLOC, strsize("Ok"));
	memcard(s1, STATUS, 0, 0);
	s1 = memcard(s1, STRING, FREE, 0);
	s1 = memcard(s1, STRING, FREE, 0); //| Teste de double free.
	memcard(s1, STATUS, 0, 0);
}

void	test_vector_with_free(void)
{
	//| Teste com VECTOR (com ou sem 'content').
	printf(YELLOW"| VECTOR TYPE |\n"RESET);

	printf(ORANGE"_without content_\n"RESET);
	char **vector0 = memcard(NULL, VECTOR, MALLOC, 1);
	memcard(vector0, STATUS, 0, 0);
	vector0 = memcard(vector0, VECTOR, FREE, 0);
	vector0 = memcard(vector0, VECTOR, FREE, 0); //| Teste de double free.
	memcard(vector0, STATUS, 0, 0);

	printf(ORANGE"_with content_\n"RESET);
	char *tmp[] = {"Vector1", "Vector2", "Vector3"};
	char **vector1 = memcard(tmp, VECTOR, MALLOC, 3);
	memcard(vector1, STATUS, 0, 0);
	vector1 = memcard(vector1, VECTOR, FREE, 0);
	vector1 = memcard(vector1, VECTOR, FREE, 0); //| Teste de double free.
	memcard(vector1, STATUS, 0, 0);
}

void	test_default_without_free(void)
{
	//| Teste com qualquer tipo (sem 'content').
	printf(YELLOW"| DEFAULT TYPE |\n"RESET);

	//----------| VOID |----------//
	printf(ORANGE"_void *_\n"RESET);
	void *ptr = memcard(NULL, DEFAULT, MALLOC, 1);
	memcard(ptr, STATUS, 0, 0);

	//----------| CHAR * |----------//
	printf(ORANGE"_char *_\n"RESET);
	char *str = memcard(NULL, DEFAULT, MALLOC, 1);
	memcard(str, STATUS, 0, 0);

	//----------| INT * |----------//
	printf(ORANGE"_int *_\n"RESET);
	int *nbs = memcard(NULL, DEFAULT, MALLOC, 1);
	memcard(nbs, STATUS, 0, 0);

	//----------| DOUBLE * |----------//
	printf(ORANGE"_double *_\n"RESET);
	double *ds = memcard(NULL, DEFAULT, MALLOC, 1);
	memcard(ds, STATUS, 0, 0);

	//----------| LIST * |----------//
	printf(ORANGE"_list *_\n"RESET);
	t_memnode *node = memcard(NULL, DEFAULT, MALLOC, sizeof(t_memnode));
	memcard(node, STATUS, 0, 0);
}

void	test_string_without_free(void)
{
	//| Teste com STRING (com ou sem 'content').
	printf(YELLOW"| STRING TYPE |\n"RESET);

	printf(ORANGE"_without content_\n"RESET);
	char *s0 = memcard(NULL, STRING, MALLOC, 1);
	memcard(s0, STATUS, 0, 0);

	printf(ORANGE"_with content_\n"RESET);
	char *s1 = memcard("Ok", STRING, MALLOC, strsize("Ok"));
	memcard(s1, STATUS, 0, 0);
}

void	test_vector_without_free(void)
{
	//| Teste com VECTOR (com ou sem 'content').
	printf(YELLOW"| STRING TYPE |\n"RESET);

	printf(ORANGE"_without content_\n"RESET);
	char **vector0 = memcard(NULL, VECTOR, MALLOC, 1);
	memcard(vector0, STATUS, 0, 0);

	printf(ORANGE"_with content_\n"RESET);
	char *tmp[] = {"Vector1", "Vector2", "Vector3"};
	char **vector1 = memcard(tmp, VECTOR, MALLOC, 3);
	memcard(vector1, STATUS, 0, 0);
}

int	main(void)
{
	memlist_holder(start_memlist(), 0);

	//----------| Testes COM free |----------//
	printf(YELLOW"+----------| WITH FREE |----------+\n"RESET);
	test_default_with_free();
	test_string_with_free();
	test_vector_with_free();
	//test_ints();
	//----------| Testes SEM free |----------//
	printf(YELLOW"+----------| WITHOUT FREE |----------+\n"RESET);
	test_default_without_free();
	test_string_without_free();
	test_vector_without_free();

	memcard(NULL, PRINT, 0, 0);   //| Printar a lista toda.
	memcard(NULL, 0, FREEALL, 0); //| Liberar toda a memória do programa.
	return (0);
}
