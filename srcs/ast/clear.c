/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:15:11 by gcrisp            #+#    #+#             */
/*   Updated: 2024/02/02 13:29:56 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

void	clear_redirect(t_redirect *redir)
{
	free(redir->from);
	free(redir->to);
}

void	clear_command(t_command *command)
{
	size_t	i;

	i = 0;
	while (command->args[i])
		free(command->args[i]);
	free(command->args);
	i = 0;
	free_redirect_array(command->redirects, command->num_redirs);
}

void	clear_and_or(t_and_or *ao)
{
	free_operation_array(ao->ops, ao->num_ops);
}

void	clear_sub_shell(t_sub_shell *ss)
{
	free_operation(ss->initial);
	free_and_or_array(ss->conditionals, ss->num_conditions);
}

void	clear_operation(t_operation *op)
{
	if (op->is_com)
		free_command(op->data.command);
	else
		free_sub_shell(op->data.sub_shell);
}
