#include <stdlib.h>

//----------| DEFINES |----------//
# define FREEALL	0
# define FREE		1
# define MALLOC		2
# define STATUS		3 //| Adicionar.
# define PRINT		4 //| Adicionar.

# define STRING		5
# define VECTOR		6
# define INTS		7
# define MATRIX		8 //| Adicionar.

//----------| STRUCTS |----------//
typedef struct s_memnode
{
	void			*addr;
	struct s_memnode	*next;
	struct s_memnode	*prev;
}	t_memnode;

typedef struct s_memlist
{
	t_memnode	*first;
	t_memnode	*last;
	size_t		size;
}	t_memlist;

//----------| UTILS |----------//
size_t	ft_strlen(const char *s)
{
	size_t	i;
	
	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

//----------| CLEANERS |----------//
void	safe_free(void *content)
{
	if (content)
	{
		free(content);
		content = NULL;
	}
}

void	free_vector(char **vector)
{
	size_t	i;

	i = 0;
	while (vector[i])
	{
		safe_free(vector[i]);
		i++;
	}
	safe_free(vector);
}

void	free_list(t_memlist *list)
{
	t_memnode	*current;
	t_memnode	*next_node;

	current = list->first;
	while (current)
	{
		next_node = current->next;
		safe_free(current->addr);
		safe_free(current);
		current = next_node;
	}
	safe_free(list);
}

//----------| MEMLIST |----------//
t_memlist	*start_list(void)
{
	t_memlist	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->first = NULL;
	list->last = NULL;
	list->size = 0;
	return (list);
}

t_memnode	*create_node(void *addr)
{
	t_memnode	*new_node;

	new_node = (t_node *)malloc(sizeof(t_memnode));
	if (!new_node)
		return (NULL);
	new_node->addr = addr;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	add_node(t_memlist *list, void *addr)
{
	t_memnode	*new_node;

	new_node = create_node(addr);
	if (!new_node)
		return ;
	if (!list->first)
	{
		list->first = new_node;
		list->last = new_node;
	}
	else
	{
		list->last->next = new_node;
		new_node->prev = list->last;
		list->last = new_node;
	}
	list->size++;
}

void	remove_node(t_memlist *list, t_memnode *node)
{
	if (!node)
		return ;
	if (node->prev)
		node->prev->next = node->next;
	if (node->next)
		node->next->prev = node->prev
	if (list->first == node)
		list->first = node->next;
	if (list->last == node)
		list->last = node->prev;
	list->size--;
	safe_free(node->addr);
	safe_free(node);
}

t_memlist	*list_holder(t_memlist *new_list, int tofree)
{
	static t_memlist	*list;

	if (new_list)
	{
		if (list)
			free_list(list);
		list = new_list;
	}
	if (tofree && list)
	{
		free_list(list);
		list = NULL;
	}
	return (list);
}

//----------| TYPES FUNCTIONS |----------//
char	*type_string(char *s, int tofree, size_t memsize)
{
	size_t	i;
	char	*new;

	if (!s)
		return (NULL);
	if (tofree)
		return (safe_free(string), NULL); //| MUDAR PARA REMOVE_NODE().
	new = malloc(sizeof(char) * (memsize + 1));
	if (!new)
		return (NULL);
	add_node(list_holder(NULL, 0), (void *)new);
	i = 0;
	while (s[i] && i < memsize)
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

int	type_ints(int *arr, int tofree, size_t memsize)
{
	int	new;
	size_t	i;

	if (tofree)
		return (safe_free(arr), NULL); //| MUDAR PARA REMOVE_NODE().
	new = (int *)malloc(sizeof(int) * memsize);
	if (!new)
		return (NULL);
	add_node(list_holder(NULL, 0), (void *)new);
	if (arr)
	{
		i = 0;
		while (i < memsize)
		{
			new[i] = arr[i];
			i++;
		}
	}
	return (new);
}

char	**type_vector(char **vector, int tofree, size_t memsize)
{
	size_t	i;
	char	**new;

	if (tofree)
		return (free_vector(vector), NULL); //| MUDAR PARA REMOVE_NODE().
	new = (char **)malloc(sizeof(char *) * (size + 1));
	if (!new)
		return (NULL);
	add_node(list_holder(NULL, 0), (void *)new);
	if (vector)
	{
		i = 0;
		while (vector[i] && i < memsize)
		{
			new[i] = type_string(vector[i], MALLOC, ft_strlen(vector[i]));
			i++;
		}
	}
	new[memsize] = NULL;
	return (new);
}

//----------| MEMORYCARD |----------//
void	*memorycard(void *content, int type, int mallocfree, size_t memsize)
{
	if (type == STRING)
		return (type_string((char *)content, mallocfree, memsize);
	else if (type == VECTOR)
		return (type_string((char **)content, mallocfree, memsize);
	else if (type == INTS)
		return (type_string((int *)content, mallocfree, memsize);
	//| Adicionar type == MATRIX (int **).
	else if (type == FREEALL)
		return (list_holder(NULL, FREE), NULL);
	return (NULL);
}

//| Adicionar uma Main para testes.
