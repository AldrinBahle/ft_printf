/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 13:42:25 by agama             #+#    #+#             */
/*   Updated: 2018/06/04 11:02:05 by agama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	counter;
	char			*str;

	if (!s)
		return (0);
	counter = 0;
	str = (char *)malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	while (counter < len)
	{
		str[counter] = s[start + counter];
		counter++;
	}
	str[counter] = '\0';
	return (str);
}
