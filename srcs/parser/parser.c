/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:02:36 by gcrisp            #+#    #+#             */
/*   Updated: 2024/02/02 13:47:06 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	resolve_variables(t_list **tokens, t_list **variables)
{
	t_list	*current;

	current = *tokens;
	while (current)
	{
		current = current->next;
	}
}

t_sub_shell	*parse(const char *line, t_list **variables)
{
	t_sub_shell	*out;
	t_list		*tokens;

	out = new_sub_shell(0, 0, 0);
	tokens = get_tokens(line);
	resolve_variables(&tokens, variables);
	ft_lstclear(&tokens, free_token);
	return (out);
}
