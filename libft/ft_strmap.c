/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 11:49:52 by agama             #+#    #+#             */
/*   Updated: 2018/06/04 09:38:01 by agama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int	counter;
	char			*str;

	if (!s)
		return (0);
	counter = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s)) + 1);
	if (str == NULL)
		return (NULL);
	while (s[counter] != '\0')
	{
		str[counter] = f(s[counter]);
		counter++;
	}
	str[counter] = '\0';
	return (str);
}
