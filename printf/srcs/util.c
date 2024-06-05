/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 09:05:43 by gcrisp            #+#    #+#             */
/*   Updated: 2023/05/25 11:55:29 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printers.h"

t_printoptions	getepo(void)
{
	t_printoptions	e;

	e = (t_printoptions){0, 0, " ", 0, 0, -1};
	return (e);
}

void	addprefix(char *pre, char **s)
{
	char	*tmp;

	tmp = ft_strjoin(pre, *s);
	free(*s);
	*s = tmp;
}

void	addsuffix(char *suf, char **s)
{
	char	*tmp;

	tmp = ft_strjoin(*s, suf);
	free(*s);
	*s = tmp;
}
