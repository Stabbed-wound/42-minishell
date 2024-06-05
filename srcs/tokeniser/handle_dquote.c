/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dquote.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:54:53 by gcrisp            #+#    #+#             */
/*   Updated: 2024/02/27 15:12:09 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokeniser.h"

t_list	*handle_dquote(const char *line, size_t *i)
{
	t_list	*out;
	size_t	text_i;

	out = 0;
	text_i = 0;
	while (line[*i] && line[*i] != '\"')
	{
		while (line[*i] && line[*i] != '\"' && line[*i] != '$')
			(*i)++;
		if (line[*i] != '$')
			break ;
		ft_lstadd_back(&out, ft_lstnew(new_token(STRING, ft_strndup(&line[text_i], (*i)++))));
		ft_lstadd_back(&out, ft_lstnew(new_token(VARIABLE, get_word(line, i))));
		text_i = *i;
	}
	if (text_i != *i)
		ft_lstadd_back(&out, ft_lstnew(new_token(STRING, ft_strndup(&line[text_i], *i - text_i))));
	*i = *i + 2;
	return (out);
}
