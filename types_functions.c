/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:01:17 by jazevedo          #+#    #+#             */
/*   Updated: 2024/09/09 18:01:42 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memorycard.h"

char	*type_str(char *s, int tofree, size_t memsize)
{
	size_t	i;
	char	*new;

	if (tofree)
		return (search_node(s), NULL);
	new = malloc(sizeof(char) * (memsize + 1));
	if (!new)
		return (NULL);
	add_node(list_holder(NULL, 0), (void *)new);
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
		ft_bzero(new, memsize);
	return (new);
}

int	*type_ints(int *arr, int tofree, size_t memsize)
{
	int	*new;
	size_t	i;

	if (tofree)
		return (search_node(arr), NULL);
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
	else
		ft_bzero(new, memsize);
	return (new);
}

char	**fill_vector(char **vector, size_t memsize)
{
	size_t	i;

	i = 0;
	while (i < memsize)
	{
		vector[i] = type_string(NULL, MALLOC, 1);
		i++;
	}
	vector[memsize] = NULL;
	return (vector);
}

char	**type_vector(char **vector, int tofree, size_t memsize)
{
	size_t	i;
	char	**new;

	if (tofree)
		return (clear_vector(vector), NULL);
	new = (char **)malloc(sizeof(char *) * (memsize + 1));
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
		new[memsize] = NULL;
	}
	else
		new = fill_vector(new, memsize);
	return (new);
}
