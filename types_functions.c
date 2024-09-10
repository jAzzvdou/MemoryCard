/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:01:17 by jazevedo          #+#    #+#             */
/*   Updated: 2024/09/10 10:08:18 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memorycard.h"

void	*type_default(void *ptr, int tofree, size_t memsize)
{
	void	*new;

	if (tofree == FREE)
		return (search_memnode(ptr), NULL);
	new = malloc(memsize);
	if (!new)
		return (NULL);
	add_memnode(memlist_holder(NULL, 0), new);
	fill_zero(new, memsize);
	return (new);
}

char	*type_str(char *s, int tofree, size_t memsize)
{
	size_t	i;
	char	*new;

	if (tofree == FREE)
		return (search_memnode(s), NULL);
	new = malloc(sizeof(char) * (memsize + 1));
	if (!new)
		return (NULL);
	add_memnode(memlist_holder(NULL, 0), (void *)new);
	i = 0;
	if (s)
	{
		while (s[i] && i < memsize)
		{
			new[i] = s[i];
			i++;
		}
		new[i] = '\0';
	}
	else
		fill_zero(new, memsize);
	return (new);
}

int	*type_ints(int *arr, int tofree, size_t memsize)
{
	int	*new;
	size_t	i;

	if (tofree == FREE)
		return (search_memnode(arr), NULL);
	new = (int *)malloc(sizeof(int) * memsize);
	if (!new)
		return (NULL);
	add_memnode(memlist_holder(NULL, 0), (void *)new);
	if (arr)
	{
		i = 0;
		while (i < memsize)
		{
			new[i] = arr[i];
			i++;
		}
	}
	else
		fill_zero(new, memsize);
	return (new);
}

char	**fill_vector(char **vector, size_t memsize)
{
	size_t	i;

	i = 0;
	while (i < memsize)
	{
		vector[i] = type_str(NULL, MALLOC, 0);
		i++;
	}
	vector[memsize] = NULL;
	return (vector);
}

char	**type_vector(char **vector, int tofree, size_t memsize)
{
	size_t	i;
	char	**new;

	if (tofree == FREE)
		return (clear_vector(vector), NULL);
	new = (char **)malloc(sizeof(char *) * (memsize + 1));
	if (!new)
		return (NULL);
	add_memnode(memlist_holder(NULL, 0), (void *)new);
	if (vector)
	{
		i = 0;
		while (vector[i] && i < memsize)
		{
			new[i] = type_str(vector[i], MALLOC, str_size(vector[i]));
			i++;
		}
		new[memsize] = NULL;
	}
	else
		new = fill_vector(new, memsize);
	return (new);
}
