/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 09:05:21 by gcrisp            #+#    #+#             */
/*   Updated: 2023/05/25 11:54:18 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	isflag(char c)
{
	return (c == '#' || c == ' ' || c == '+' || c == '0' || c == '-');
}

static void	parseflags(t_printoptions *options, char **format)
{
	*options = getepo();
	while (isflag(**format))
	{
		if (**format == '#')
			options->alt = 1;
		else if (**format == ' ' && !options->addedsign)
			options->addedsign = -1;
		else if (**format == '+')
			options->addedsign = 1;
		else if (**format == '0' && !options->leftalign)
			options->padding = "0";
		else if (**format == '-')
			options->leftalign = 1;
		*format = *format + 1;
	}
	options->width = ft_atoi(*format);
	while ('0' <= **format && **format <= '9')
		*format = *format + 1;
	if (**format != '.')
		return ;
	*format = *format + 1;
	options->padding = " ";
	options->precision = ft_atoi(*format);
	while ('0' <= **format && **format <= '9')
		*format = *format + 1;
}

static char	*parsearg(va_list valist, char **format)
{
	t_printoptions	options;

	*format = *format + 1;
	parseflags(&options, format);
	if (**format == 'd' || **format == 'i')
		return (printdi(va_arg(valist, int), options));
	if (**format == 'u')
		return (printu(va_arg(valist, unsigned int), options));
	if (**format == 'x')
		return (printhex(va_arg(valist, unsigned int), 0, options));
	if (**format == 'X')
		return (printhex(va_arg(valist, unsigned int), 1, options));
	if (**format == 'p')
		return (printp((unsigned long)va_arg(valist, void *), options));
	if (**format == 'c')
		return (printc((char)va_arg(valist, int), options));
	if (**format == 's')
		return (prints(va_arg(valist, char *), options));
	if (**format == '%')
		return (printc('%', options));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	valist;
	char	*out;
	char	*tmp;

	va_start(valist, format);
	out = malloc(1);
	out[0] = 0;
	while (*format)
	{
		if (*format != '%')
			tmp = ft_strndup(format, 1);
		else
			tmp = parsearg(valist, (char **)&format);
		if (!tmp)
		{
			va_end(valist);
			return (-1);
		}
		addsuffix(tmp, &out);
		free(tmp);
		format++;
	}
	va_end(valist);
	return (write(1, out, ft_strlen(out)));
}
