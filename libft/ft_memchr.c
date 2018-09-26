/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 07:45:42 by agama             #+#    #+#             */
/*   Updated: 2018/05/21 17:16:47 by agama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	const char	*ptr;
	size_t		index;

	ptr = (const char *)str;
	index = 0;
	while (index < n)
	{
		if ((unsigned char)ptr[index] == (unsigned char)c)
			return ((char *)str + index);
		index++;
	}
	return (NULL);
}
