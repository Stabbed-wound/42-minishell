/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_map.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:46:31 by gcrisp            #+#    #+#             */
/*   Updated: 2024/03/14 10:46:32 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_MAP_H
# define HASH_MAP_H
# ifndef HASH_MAP_SIZE
#  define HASH_MAP_SIZE 1024
# endif
# ifndef FNV_OFFSET
#  define FNV_OFFSET 14695981039346656037UL
# endif
# ifndef FNV_PRIME
#  define FNV_PRIME 1099511628211UL
# endif
# include "libft.h"

struct s_bucket
{
	char			*key;
	void			*value;
	struct s_bucket	*next;
};

typedef struct s_hmap
{
	struct s_bucket	*buckets[HASH_MAP_SIZE];
}	t_hmap;

t_hmap	*ft_hmapcreate(void);
void	ft_hmapdestroy(t_hmap *hmap, void (*del)(void *));
void	*ft_hmapget(t_hmap *hmap, char *key);
void	ft_hmapset(t_hmap *hmap, char *key, void *value);

#endif