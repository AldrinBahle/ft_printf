/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 12:05:44 by agama             #+#    #+#             */
/*   Updated: 2018/06/04 10:45:08 by agama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
		str[counter] = f(counter, s[counter]);
		counter++;
	}
	str[counter] = '\0';
	return (str);
}
