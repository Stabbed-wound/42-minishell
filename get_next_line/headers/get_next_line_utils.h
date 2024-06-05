/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:19:57 by gcrisp            #+#    #+#             */
/*   Updated: 2023/05/10 11:58:58 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_UTILS_H
# define GET_NEXT_LINE_UTILS_H
# include <stdlib.h>
# include <unistd.h>
# include "get_next_line_constants.h"

int		checkfd(int fd);
int		hasnewline(char *s);
char	*reallocstr(char *s, size_t size);
char	*assignbuf(void);

#endif
