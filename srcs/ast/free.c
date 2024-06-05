/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:13:17 by gcrisp            #+#    #+#             */
/*   Updated: 2024/01/16 15:27:28 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

void	free_redirect(t_redirect *redir)
{
	clear_redirect(redir);
	free(redir);
}

void	free_command(t_command *command)
{
	clear_command(command);
	free(command);
}

void	free_and_or(t_and_or *ao)
{
	clear_and_or(ao);
	free(ao);
}

void	free_sub_shell(t_sub_shell *ss)
{
	clear_sub_shell(ss);
	free(ss);
}

void	free_operation(t_operation *op)
{
	clear_operation(op);
	free(op);
}
