/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:42:53 by gcrisp            #+#    #+#             */
/*   Updated: 2023/05/09 11:32:04 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	checkfd(int fd)
{
	char	c;

	return (read(fd, &c, 0) != -1);
}

int	hasnewline(char *s)
{
	while (*s)
	{
		if (*s == '\n')
			return (1);
		s++;
	}
	return (0);
}

char	*reallocstr(char *s, size_t size)
{
	char	*new;
	size_t	i;

	new = malloc(size);
	if (!new)
		return (0);
	i = 0;
	while (s[i] && i < size - 1)
	{
		new[i] = s[i];
		i++;
	}
	while (i < size)
		new[i++] = 0;
	free(s);
	return (new);
}

char	*assignbuf(void)
{
	char	*out;
	size_t	i;

	out = malloc(BUFFER_SIZE);
	if (!out)
		return (0);
	i = -1;
	while (++i < BUFFER_SIZE)
		out[i] = 0;
	return (out);
}
