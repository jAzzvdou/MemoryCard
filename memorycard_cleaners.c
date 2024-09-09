/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memorycard_cleaners.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:54:35 by jazevedo          #+#    #+#             */
/*   Updated: 2024/09/09 17:55:12 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memorycard.h"

void	clear(void **content)
{
	if (content && *content)
	{
		free(*content);
		*content = NULL;
	}
}

void	clear_vector(char **vector)
{
	size_t	i;

	i = 0;
	while (vector[i])
	{
		search_node(vector[i]);
		i++;
	}
	search_node(vector);
}

void	free_memlist(t_memlist *list)
{
	t_memnode	*current;
	t_memnode	*next_node;

	current = list->first;
	while (current)
	{
		next_node = current->next;
		clear((void **)&current->addr);
		clear((void **)&current);
		current = next_node;
	}
	clear((void **)&list);
}
