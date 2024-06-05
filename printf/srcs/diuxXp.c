/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diuxXp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:18:39 by gcrisp            #+#    #+#             */
/*   Updated: 2023/05/25 11:21:59 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printers.h"

static void	linesaver(char *pre, char *s, char **out, t_printoptions o)
{
	char	*tmp;

	if (*o.padding == '0' || o.leftalign)
	{
		o.width -= ft_strlen(pre);
		*out = prints(s, o);
		tmp = prints(pre, getepo());
	}
	if (*o.padding == ' ' && !o.leftalign)
	{
		o.width -= ft_strlen(s);
		*out = prints(s, getepo());
		tmp = prints(pre, o);
	}
	addprefix(tmp, out);
}

char	*printdi(int n, t_printoptions o)
{
	char	*s;
	char	*pre;
	char	*out;

	s = ft_itoa(n);
	pre = "";
	if (n < 0)
		pre = "-";
	else if (o.addedsign > 0)
		pre = "+";
	else if (o.addedsign < 0)
		pre = " ";
	if (n != 0 && o.precision == 0)
		o.precision = -1;
	linesaver(pre, s, &out, o);
	free(s);
	return (out);
}

char	*printu(unsigned int n, t_printoptions o)
{
	char	*s;
	char	*out;
	char	*tmp;

	s = ft_uitoa(n);
	if (n != 0 && o.precision == 0)
		o.precision = -1;
	out = prints(s, o);
	if (!o.addedsign)
	{
		free(s);
		return (out);
	}
	o.width -= 1;
	if (o.addedsign > 0)
		tmp = printc('+', getepo());
	else
		tmp = printc(' ', getepo());
	addprefix(tmp, &out);
	free(tmp);
	free(s);
	return (out);
}

char	*printhex(unsigned int n, int capital, t_printoptions o)
{
	char	*s;
	char	*out;
	char	*pre;

	pre = "";
	if (o.alt)
		pre = "0x";
	s = ft_uitoa_base(n, "0123456789abcdef");
	linesaver(pre, s, &out, o);
	free(s);
	if (capital)
		ft_strtoupper(out);
	return (out);
}

char	*printp(unsigned long n, t_printoptions o)
{
	char	*s;
	char	*out;
	char	*pre;

	s = ft_ultoa_base(n, "0123456789abcdef");
	if (o.leftalign || *o.padding == '0')
	{
		o.width -= 2;
		out = prints(s, o);
		pre = prints("0x", getepo());
	}
	else
	{
		o.width -= ft_strlen(s);
		out = prints(s, getepo());
		pre = prints(s, o);
	}
	addprefix(pre, &out);
	free(pre);
	free(s);
	return (out);
}
