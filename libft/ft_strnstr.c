/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 11:31:24 by agama             #+#    #+#             */
/*   Updated: 2018/05/23 13:48:43 by agama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < n && str1[i] != '\0')
	{
		j = 0;
		while ((i + j) < n && str1[i + j] == str2[j] && str2[j] != '\0')
			j++;
		if (str2[j] == '\0')
			return ((char *)str1 + i);
		i++;
	}
	return (NULL);
}
