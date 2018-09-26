/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 16:17:11 by agama             #+#    #+#             */
/*   Updated: 2018/05/19 16:30:04 by agama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	index;
	char	*dst;
	char	*src1;

	dst = (char *)dest;
	src1 = (char *)src;
	index = 0;
	while (index < n)
	{
		dst[index] = src1[index];
		index++;
	}
	return (dest);
}
