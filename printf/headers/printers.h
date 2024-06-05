/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 09:04:22 by gcrisp            #+#    #+#             */
/*   Updated: 2024/01/09 12:17:16 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTERS_H
# define PRINTERS_H
# include "util.h"
# include "libft.h"

typedef struct op
{
	int		alt;
	int		width;
	char	*padding;
	int		addedsign;
	int		leftalign;
	int		precision;
}	t_printoptions;

char	*printc(char c, t_printoptions options);
char	*prints(char *s, t_printoptions options);
char	*printdi(int n, t_printoptions options);
char	*printu(unsigned int n, t_printoptions options);
char	*printhex(unsigned int n, int capital, t_printoptions options);
char	*printp(unsigned long n, t_printoptions options);
#endif
