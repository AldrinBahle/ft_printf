/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 15:08:34 by agama             #+#    #+#             */
/*   Updated: 2018/08/02 15:41:25 by agama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_count_chars(const char *haystack, char needle, size_t length)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (i < length)
	{
		if (haystack[i] == needle)
			count++;
		i++;
	}
	return (count);
}
