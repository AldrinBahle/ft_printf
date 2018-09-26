/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digits_ularge.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 10:29:08 by agama             #+#    #+#             */
/*   Updated: 2018/07/23 10:34:03 by agama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_digits_ularge(uintmax_t number)
{
	int	count;

	if (number == 0)
		return (1);
	count = 0;
	while (number > 0)
	{
		number /= 10;
		count++;	
	}
	return (count);
}
