/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmapget.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:17:28 by gcrisp            #+#    #+#             */
/*   Updated: 2024/03/15 11:17:29 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

static uint64_t hash_key(const char *key)
{
	uint64_t hash;

	hash = FNV_OFFSET;
	while (*key)
	{
		hash ^= (uint64_t)(unsigned char)(*key);
        hash *= FNV_PRIME;
		key++;
	}
	return (hash);
}

void	*ft_hmapget(t_hmap *hmap, char *key)
{
	struct s_bucket	*bucket;

	bucket = hmap->buckets[hash_key(key) % HASH_MAP_SIZE];
	while (ft_strcmp(bucket->key, key) && bucket)
		bucket = bucket->next;
	if (!bucket)
		return (0);
	return (bucket->value);
}