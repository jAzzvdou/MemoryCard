#include "memorycard.h"

void	test_default(void)
{
	//| Teste com qualquer tipo (sem 'content').
	
	//----------| VOID |----------//
	void *ptr = memcard(NULL, DEFAULT, MALLOC, 1);
	memcard(ptr, STATUS, 0, 0);
	ptr = memcard(ptr, DEFAULT, FREE, 0);
	ptr = memcard(ptr, DEFAULT, FREE, 0); //| Teste de double free.
	memcard(ptr, STATUS, 0, 0);

	//----------| CHAR |----------//
	char *str = memcard(NULL, DEFAULT, MALLOC, 1);
	memcard(str, STATUS, 0, 0);
	str = memcard(str, DEFAULT, FREE, 0);
	str = memcard(str, DEFAULT, FREE, 0); //| Teste de double free.
	memcard(str, STATUS, 0, 0);

	//----------| INT |----------//
	int *nbs = memcard(NULL, DEFAULT, MALLOC, 1);
	memcard(nbs, STATUS, 0, 0);
	nbs = memcard(nbs, DEFAULT, FREE, 0);
	nbs = memcard(nbs, DEFAULT, FREE, 0); //| Teste de double free.
	memcard(nbs, STATUS, 0, 0);

	//----------| DOUBLE |----------//
	double *ds = memcard(NULL, DEFAULT, MALLOC, 1);
	memcard(ds, STATUS, 0, 0);
	ds = memcard(ds, DEFAULT, FREE, 0);
	ds = memcard(ds, DEFAULT, FREE, 0); //| Teste de double free.
	memcard(ds, STATUS, 0, 0);
}

void	test_string(void)
{
	//| Teste com STRING (com ou sem 'content').
	char *s0 = memcard(NULL, STRING, MALLOC, 1);
	memcard(s0, STATUS, 0, 0);
	s0 = memcard(s0, STRING, FREE, 0);
	s0 = memcard(s0, STRING, FREE, 0); //| Teste de double free.
	memcard(s0, STATUS, 0, 0);

	char *s1 = memcard("Ok", STRING, MALLOC, strsize("Ok"));
	memcard(s1, STATUS, 0, 0);
	s1 = memcard(s1, STRING, FREE, 0);
	s1 = memcard(s1, STRING, FREE, 0); //| Teste de double free.
	memcard(s1, STATUS, 0, 0);
}

int	main(void)
{
	memlist_holder(start_memlist(), 0);

	test_default();
	test_string();
	//test_vector();
	//test_ints();

	clear_memlist(memlist_holder(NULL, 0));
	return (0);
}
