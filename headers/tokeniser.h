/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokeniser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:54:38 by gcrisp            #+#    #+#             */
/*   Updated: 2024/02/05 16:54:37 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENISER_H
# define TOKENISER_H
# include "libft.h"

typedef enum e_token_type
{
	STRING,
	VARIABLE,
	LESSER,
	DLESSER,
	GREATER,
	DGREATER,
	PIPE,
	AND,
	OR,
	LPAREN,
	RPAREN,
	SPACE,
}	t_token_type;

typedef struct s_token
{
	t_token_type	type;
	char			*data;
}	t_token;

char	*get_word(const char *line, size_t *i);
t_list	*handle_dquote(const char *line, size_t *i);

t_token	*new_token(t_token_type type, char *data);
void	free_token(void *token);

// list is of t_token
t_list	*get_tokens(const char *line);

#endif
