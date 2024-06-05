/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmapset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:17:36 by gcrisp            #+#    #+#             */
/*   Updated: 2024/03/15 11:17:37 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static uint64_t hash_key(const char *key)
{
	uint64_t hash;

	hash = FNV_OFFSET;
	if (!key)
		return (0);
	while (*key)
	{
		hash ^= (uint64_t)(unsigned char)(*key);
        hash *= FNV_PRIME;
		key++;
	}
	return (hash);
}

static struct s_bucket	*new_bucket(char *key, void *value)
{
	struct s_bucket *out;

	out = malloc(sizeof(struct s_bucket));
	out->key = key;
	out->value = value;
	out->next = 0;
	return (out);
}

void	ft_hmapset(t_hmap *hmap, char *key, void *value)
{
	struct s_bucket	**bucket;

	bucket = &hmap->buckets[hash_key(key) % HASH_MAP_SIZE];
	while (*bucket)
		bucket = &(*bucket)->next;
	*bucket = new_bucket(key, value);
}