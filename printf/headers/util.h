/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 09:04:38 by gcrisp            #+#    #+#             */
/*   Updated: 2023/04/26 10:24:08 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H
# include <stdlib.h>
# include "printers.h"

typedef struct op	t_printoptions;

t_printoptions	getepo(void);
void			addprefix(char *pre, char **s);
void			addsuffix(char *suf, char **s);
#endif
