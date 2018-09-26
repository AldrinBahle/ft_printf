/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_large.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 10:06:13 by agama             #+#    #+#             */
/*   Updated: 2018/07/23 10:25:24 by agama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa_large(intmax_t number)
{
	char	*new;
	int		length;

	if (number == LLONG_MIN)
		return (ft_strdup("-9223372036854775807"));
	if (number == 0)
		return (ft_strdup("0"));
	length = ft_count_digits_ularge(ft_abs_large(number));
	new = malloc(sizeof(char) * (length + (number < 0) +1));
	if (number < 0)
	{
		new[0] = '-';
		ft_itoa_write(new + length, (uintmax_t) - number);
		new[length + 1] = '\0';
	}
	else
	{
		ft_itoa_write(new + length - 1, number);
		new[length + 1] = '\0';
	}
	return (new);
}
