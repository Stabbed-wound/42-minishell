/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 08:22:16 by gcrisp            #+#    #+#             */
/*   Updated: 2023/05/09 11:30:48 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstremove(t_list **headptr, size_t index, void (*f_free)(void *))
{
	t_list	*prev;
	t_list	*elem;

	elem = ft_lstindex(*headptr, index);
	if (index)
	{
		prev = ft_lstindex(*headptr, index - 1);
		prev->next = elem->next;
	}
	else
		*headptr = elem->next;
	f_free(elem->data);
	free(elem);
}
