/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 11:24:43 by agama             #+#    #+#             */
/*   Updated: 2018/06/13 13:57:23 by agama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	unsigned int	counter;

	if (!s || !f)
		return ;
	counter = 0;
	while (s[counter] != '\0')
	{
		f(s + counter);
		counter++;
	}
}
