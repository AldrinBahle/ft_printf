/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 17:01:22 by agama             #+#    #+#             */
/*   Updated: 2018/06/13 13:07:39 by agama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strtrim(char const *s)
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	z;
	char			*str;

	x = 0;
	z = 0;
	if (!s)
		return (NULL);
	while (s[x] == ' ' || s[x] == '\n' || s[x] == '\t')
		x++;
	if (s[x] == '\0')
		return (ft_strcpy(ft_memalloc(sizeof(char) * 2), ""));
	y = ft_strlen(s) - 1;
	while (s[y] == ' ' || s[y] == '\n' || s[y] == '\t')
		y--;
	if (!(str = (char *)malloc(sizeof(char) * (y - x + 2))))
		return (NULL);
	while (z < y - x + 1)
	{
		str[z] = s[x + z];
		z++;
	}
	str[z] = '\0';
	return (str);
}
