/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memorycard.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:02:40 by jazevedo          #+#    #+#             */
/*   Updated: 2024/09/09 18:02:43 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memorycard.h"

void	*memorycard(void *content, int type, int mallocfree, size_t memsize)
{
	if (type == STRING)
		return (type_string((char *)content, mallocfree, memsize));
	else if (type == VECTOR)
		return (type_vector((char **)content, mallocfree, memsize));
	else if (type == INTS)
		return (type_ints((int *)content, mallocfree, memsize));
	else if (type == STATUS)
		return (status_node(content), NULL);
	else if (type == PRINT)
		return (print_list(), NULL);
	else if (type == FREEALL)
		return (list_holder(NULL, FREE), NULL);
	return (NULL);
}
