/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 09:40:42 by agama             #+#    #+#             */
/*   Updated: 2018/06/04 15:11:10 by agama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dest_size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dest[i] && i < dest_size)
		i++;
	while (src[j] && (i + j + 1) < dest_size)
	{
		dest[i + j] = src[j];
		j++;
	}
	if (i != dest_size)
		dest[i + j] = '\0';
	return (i + ft_strlen(src));
}
