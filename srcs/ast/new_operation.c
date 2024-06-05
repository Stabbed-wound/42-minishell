/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:38:08 by gcrisp            #+#    #+#             */
/*   Updated: 2024/01/29 15:16:01 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

t_operation	*new_command_operation(t_command *command)
{
	t_operation	*out;

	out = malloc(sizeof(t_operation));
	out->is_com = true;
	out->data.command = command;
	return (out);
}

t_operation	*new_sub_shell_operation(t_sub_shell *sub_shell)
{
	t_operation	*out;

	out = malloc(sizeof(t_operation));
	out->is_com = false;
	out->data.sub_shell = sub_shell;
	return (out);
}
