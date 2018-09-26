/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 08:57:08 by agama             #+#    #+#             */
/*   Updated: 2018/05/31 09:09:32 by agama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *str1, const void *str2, size_t n)
{
	char	*ptr1;
	char	*ptr2;
	size_t	index;

	index = 0;
	ptr1 = (char *)str1;
	ptr2 = (char *)str2;
	while (index < n)
	{
		if (ptr1[index] != ptr2[index])
			return ((unsigned char)ptr1[index] - (unsigned char)ptr2[index]);
		index++;
	}
	return (0);
}
