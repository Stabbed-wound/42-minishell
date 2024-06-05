/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:17:30 by gcrisp            #+#    #+#             */
/*   Updated: 2024/02/01 14:46:22 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tokeniser.h>

t_token	*new_token(t_token_type type, char *data)
{
	t_token	*out;

	out = malloc(sizeof(t_token));
	out->type = type;
	out->data = data;
	return (out);
}

void	free_token(void *token)
{
	t_token	*t;

	t = (t_token *)token;
	free(t->data);
	free(t);
}