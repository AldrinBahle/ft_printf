/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 08:56:29 by agama             #+#    #+#             */
/*   Updated: 2018/06/04 14:58:34 by agama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t index;

	index = 0;
	if (n == 0)
		return (0);
	if (!str1 && !str2)
		return (0);
	while (str1[index] != '\0' && str1[index] == str2[index] && index < (n - 1))
		index++;
	if (index == n)
	{
		return ((unsigned char)str1[index - 1] - \
				(unsigned char)str2[index - 1]);
	}
	return ((unsigned char)str1[index] - (unsigned char)str2[index]);
}
