/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 08:38:21 by gcrisp            #+#    #+#             */
/*   Updated: 2023/05/09 11:34:35 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*out;
	size_t	i;

	i = 0;
	while (s1[i])
		i++;
	out = malloc(i + 1);
	if (!out)
		return (0);
	out[i] = 0;
	while (i-- > 0)
		out[i] = s1[i];
	return (out);
}
