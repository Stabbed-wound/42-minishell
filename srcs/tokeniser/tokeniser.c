/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokeniser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:05:40 by gcrisp            #+#    #+#             */
/*   Updated: 2024/02/27 14:30:09 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokeniser.h"

char	*get_word(const char *line, size_t *i)
{
	size_t	pre;

	pre = *i;
	while (!((line[*i] == '&' && line[*i + 1] == '&') || line[*i] == '$'
		|| line[*i] == '<' || line[*i] == '>' || line[*i] == '|'
		|| line[*i] == '(' || line[*i] == ')' || line[*i] == ' '
		|| line[*i] == '\'' || line[*i] == '\"' || line[*i] == '\n'
		|| line[*i] == '\v'|| line[*i] == '\f' || line[*i] == '\r'
		|| line[*i] == '\t') && line[*i])
		(*i)++;
	return (ft_strndup(&line[pre], *i - pre));
}

static t_token	*handle_special(const char *line, size_t *i)
{
	*i = 1;
	if (line[0] == '(')
		return (new_token(LPAREN, 0));
	if (line[0] == ')')
		return (new_token(RPAREN, 0));
	if (line[0] == '$')
		return (new_token(VARIABLE, get_word(line, i)));
	if (line[0] == '<' && line[1] != '<')
		return (new_token(LESSER, 0));
	if (line[0] == '>' && line[1] != '>')
		return (new_token(GREATER, 0));
	if (line[0] == '|' && line[1] != '|')
		return (new_token(PIPE, 0));
	(*i)++;
	if (line[1] == '<')
		return (new_token(DLESSER, 0));
	if (line[1] == '>')
		return (new_token(DGREATER, 0));
	if (line[1] == '&')
		return (new_token(AND, 0));
	return (new_token(OR, 0));
}

static char	*handle_squote(const char *line, size_t *i)
{
	(*i)++;
	while (line[*i] != '\'' && line[*i])
		(*i)++;
	if (!line[*i])
		return (ft_strndup(line + 1, *i - 1));
	(*i)++;
	return (ft_strndup(line + 1, *i - 2));
}

static t_list	*get_token(const char *line, size_t *i)
{
	if (line[*i] == '\'')
		return (ft_lstnew(new_token(STRING, handle_squote(line, i))));
	if (line[*i] == '\"')
		return (handle_dquote(line + 1, i));
	if ((line[*i] == '&' && line[*i + 1] == '&') || line[*i] == '$'
		|| line[*i] == '<' || line[*i] == '>' || line[*i] == '|'
		|| line[*i] == '(' || line[*i] == ')')
		return (ft_lstnew(handle_special(line, i)));
	if (line[*i] == ' ' || line[*i] == '\n' || line[*i] == '\v'
		|| line[*i] == '\f' || line[*i] == '\r' || line[*i] == '\t')
	{
		*i += 1;
		while (line[*i] == ' ' || line[*i] == '\n' || line[*i] == '\v'
		|| line[*i] == '\f' || line[*i] == '\r' || line[*i] == '\t')
			*i += 1;
		return (ft_lstnew(new_token(SPACE, 0)));
	}
	return (ft_lstnew(new_token(STRING, get_word(line, i))));
}

t_list	*get_tokens(const char *line)
{
	t_list	*out;
	t_list	*end;
	size_t	i;

	i = 0;
	out = 0;
	end = 0;
	while (line[i])
	{
		if (end)
		{
			ft_lstadd_back(&end, get_token(line, &i));
			end = ft_lstlast(end);
		}
		else
		{
			ft_lstadd_back(&out, get_token(line, &i));
			end = ft_lstlast(out);
		}
		line = &line[i];
		i = 0;
	}
	return (out);
}
