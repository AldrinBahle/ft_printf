/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 16:50:36 by agama             #+#    #+#             */
/*   Updated: 2018/05/21 16:32:12 by agama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char	*ptr1;
	char	*ptr2;
	size_t	index;

	index = 0;
	ptr1 = (char *)dest;
	ptr2 = (char *)src;
	while (index < n)
	{
		ptr1[index] = ptr2[index];
		if ((unsigned char)ptr2[index] == (unsigned char)c)
			return ((char *)dest + index + 1);
		index++;
	}
	return (NULL);
}
