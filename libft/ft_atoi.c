/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 09:04:26 by agama             #+#    #+#             */
/*   Updated: 2018/06/04 15:10:26 by agama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	unsigned int	counter;
	long long int	res;
	int				sign;

	counter = 0;
	res = 0;
	sign = 1;
	while (str[counter] == ' ' || str[counter] == '\t' ||
			str[counter] == '\r' || str[counter] == '\n' ||
			str[counter] == '\v' || str[counter] == '\f')
		counter++;
	if (str[counter] == '-' || str[counter] == '+')
	{
		if (str[counter] == '-')
			sign = -1;
		counter++;
	}
	while (str[counter] >= '0' && str[counter] <= '9')
	{
		res = res * 10 + str[counter] - '0';
		counter++;
	}
	return ((int)(res * sign));
}
