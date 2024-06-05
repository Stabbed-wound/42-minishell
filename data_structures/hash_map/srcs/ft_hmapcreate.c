/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmapcreate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:17:07 by gcrisp            #+#    #+#             */
/*   Updated: 2024/03/15 11:17:08 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_hmap  *hmapcreate(void)
{
    t_hmap  *out;

    out = malloc(sizeof(t_hmap));
    ft_bzero(out->buckets, sizeof(struct s_bucket *) * HASH_MAP_SIZE);
    return (out);
}