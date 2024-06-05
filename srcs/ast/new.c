/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:23:04 by gcrisp            #+#    #+#             */
/*   Updated: 2024/02/02 13:45:03 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

t_redirect	*new_redirect(t_redir_type type, char *from, char *to)
{
	t_redirect	*out;

	out = malloc(sizeof(t_redirect));
	out->from = from;
	out->to = to;
	out->type = type;
	return (out);
}

t_command	*new_command(char **args, t_redirect *redirects, size_t num_redirs)
{
	t_command	*out;

	out = malloc(sizeof(t_command));
	out->args = args;
	out->redirects = redirects;
	out->num_redirs = num_redirs;
	return (out);
}

t_and_or	*new_and_or(bool is_and, t_operation *ops, size_t num_ops)
{
	t_and_or	*out;

	out = malloc(sizeof(t_and_or));
	out->is_and = is_and;
	out->ops = ops;
	out->num_ops = num_ops;
	return (out);
}

t_sub_shell	*new_sub_shell(t_operation *initial, t_and_or *conditionals,
		size_t num_conditions)
{
	t_sub_shell	*out;

	out = malloc(sizeof(t_sub_shell));
	out->initial = initial;
	out->conditionals = conditionals;
	out->num_conditions = num_conditions;
	return (out);
}
