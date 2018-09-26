/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 17:24:29 by agama             #+#    #+#             */
/*   Updated: 2018/06/13 13:13:25 by agama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_count_wrds(char const *s, char c)
{
	unsigned int	index;
	int				counter;

	index = 0;
	counter = 0;
	while (s[index])
	{
		while (s[index] == c)
			index++;
		if (s[index] != '\0')
			counter++;
		while (s[index] && s[index] != c)
			index++;
	}
	return (counter);
}

static char			*ft_strndup(char const *s, size_t n)
{
	char			*dup;

	dup = (char *)malloc(sizeof(char) * (n + 1));
	if (dup == NULL)
		return (NULL);
	dup = ft_strncpy(dup, s, n);
	dup[n] = '\0';
	return (dup);
}

char				**ft_strsplit(char const *s, char c)
{
	int				x;
	int				y;
	int				z;
	char			**table;

	x = 0;
	z = 0;
	if (!s)
		return (0);
	if (!(table = (char **)malloc(sizeof(char *) * (ft_count_wrds(s, c)) + 1)))
		return (NULL);
	while (s[x])
	{
		while (s[x] == c)
			x++;
		y = x;
		while (s[x] && s[x] != c)
			x++;
		if (x > y)
			table[z++] = ft_strndup(s + y, x - y);
	}
	table[z] = NULL;
	return (table);
}
