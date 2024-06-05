/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:01:14 by gcrisp            #+#    #+#             */
/*   Updated: 2024/02/02 13:44:37 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H
# include <stdbool.h>
# include <stdlib.h>

typedef enum e_redir_type	t_redir_type;
typedef struct s_redirect	t_redirect;
typedef struct s_command	t_command;
typedef struct s_and_or		t_and_or;
typedef struct s_sub_shell	t_sub_shell;
typedef struct s_operation	t_operation;

typedef enum e_redir_type
{
	IN,
	OUT,
	DELIM,
	APP_OUT,
}	t_redir_type;

typedef struct s_redirect
{
	char			*from;
	char			*to;
	t_redir_type	type;
}	t_redirect;

typedef struct s_command
{
	char		**args;
	t_redirect	*redirects;
	size_t		num_redirs;
}	t_command;

typedef struct s_and_or
{
	t_operation	*ops;
	size_t		num_ops;
	bool		is_and;
}	t_and_or;

typedef struct s_sub_shell
{
	t_operation	*initial;
	t_and_or	*conditionals;
	size_t		num_conditions;
}	t_sub_shell;

typedef struct s_operation
{
	union u_sub_or_com
	{
		t_command	*command;
		t_sub_shell	*sub_shell;
	} data;
	bool			is_com;
}	t_operation;

t_redirect	*new_redirect(t_redir_type type, char *from, char *to);
t_command	*new_command(char **args, t_redirect *redirects, size_t num_redirs);
t_and_or	*new_and_or(bool is_and, t_operation *ops, size_t num_ops);
t_sub_shell	*new_sub_shell(t_operation *initial, t_and_or *conditionals,
				size_t num_conditions);
t_operation	*new_command_operation(t_command *command);
t_operation	*new_sub_shell_operation(t_sub_shell *ss);

void		clear_redirect(t_redirect *redir);
void		clear_command(t_command *command);
void		clear_and_or(t_and_or *ao);
void		clear_sub_shell(t_sub_shell *ss);
void		clear_operation(t_operation *op);

void		free_redirect(t_redirect *redir);
void		free_command(t_command *command);
void		free_and_or(t_and_or *ao);
void		free_sub_shell(t_sub_shell *ss);
void		free_operation(t_operation *op);

void		free_redirect_array(t_redirect *redirs, size_t num_redirs);
void		free_command_array(t_command *commands, size_t num_commands);
void		free_and_or_array(t_and_or *aos, size_t num_aos);
void		free_sub_shell_array(t_sub_shell *subs, size_t num_subs);
void		free_operation_array(t_operation *ops, size_t num_ops);

#endif
