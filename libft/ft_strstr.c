/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 11:04:35 by agama             #+#    #+#             */
/*   Updated: 2018/05/23 10:05:11 by agama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str1, const char *str2)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	while (str1[i] == '\0' && str2[i] == '\0')
		return ((char *)str1);
	while (str1[i] != '\0')
	{
		j = 0;
		while (str2[j] != '\0' && str1[i + j] == str2[j])
			j++;
		if (str2[j] == '\0')
			return ((char *)str1 + i);
		i++;
	}
	return (NULL);
}
