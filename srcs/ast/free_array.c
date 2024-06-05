/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:33:56 by gcrisp            #+#    #+#             */
/*   Updated: 2024/02/02 13:43:20 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

void	free_redirect_array(t_redirect *redirs, size_t num_redirs)
{
	if (!redirs)
		return ;
	while (num_redirs--)
		clear_redirect(&redirs[num_redirs]);
	free(redirs);
}

void	free_command_array(t_command *commands, size_t num_commands)
{
	if (!commands)
		return ;
	while (num_commands--)
		clear_command(&commands[num_commands]);
	free(commands);
}

void	free_and_or_array(t_and_or *aos, size_t num_aos)
{
	if (!aos)
		return ;
	while (num_aos--)
		clear_and_or(&aos[num_aos]);
	free(aos);
}

void	free_sub_shell_array(t_sub_shell *subs, size_t num_subs)
{
	if (!subs)
		return ;
	while (num_subs--)
		clear_sub_shell(&subs[num_subs]);
	free(subs);
}

void	free_operation_array(t_operation *ops, size_t num_ops)
{
	if (!ops)
		return ;
	while (num_ops--)
		clear_operation(&ops[num_ops]);
	free(ops);
}
