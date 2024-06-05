/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sc.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:18:48 by gcrisp            #+#    #+#             */
/*   Updated: 2023/04/26 10:35:03 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printers.h"

char	*printc(char c, t_printoptions o)
{
	char	*out;
	int		i;

	out = ft_strdup(" ");
	out[0] = c;
	i = 0;
	while (i < o.width - 1 && !o.leftalign)
	{
		addprefix(o.padding, &out);
		i++;
	}
	while (i < o.width - 1 && o.leftalign)
	{
		addsuffix(o.padding, &out);
		i++;
	}
	return (out);
}

char	*prints(char *s, t_printoptions o)
{
	char	*out;
	int		l;
	int		i;

	if (!s)
		return (prints("(null)", o));
	l = (int)ft_strlen(s);
	if (o.precision < l && o.precision >= 0)
		l = o.precision;
	out = ft_strndup(s, (size_t)l);
	o.width -= l;
	i = 0;
	while (i < o.width && !o.leftalign)
	{
		addprefix(o.padding, &out);
		i++;
	}
	while (i++ < o.width - l && o.leftalign)
		addsuffix(o.padding, &out);
	return (out);
}
