/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmapdestroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:17:20 by gcrisp            #+#    #+#             */
/*   Updated: 2024/03/15 11:17:21 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	clear_bucket(struct s_bucket *bucket, void (*del)(void *))
{
	if (!bucket)
		return ;
	clear_bucket(bucket->next, del);
	free(bucket->key);
	del(bucket->value);
	free(bucket);
}

void	ft_hmapdestroy(t_hmap *hmap, void (*del)(void *))
{
	size_t  i;

	i = -1;
	while (++i < HASH_MAP_SIZE)
	{
		if (hmap->buckets[i])
			clear_bucket(hmap->buckets[i], del);
	}
}