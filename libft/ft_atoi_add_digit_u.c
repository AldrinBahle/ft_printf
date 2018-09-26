/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_add_digit_u.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 07:51:19 by agama             #+#    #+#             */
/*   Updated: 2018/08/02 15:02:05 by agama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_atoi_add_digit_u(const char c, unsigned int *number)
{
	if (*number)
		*number *= 10;
	*number += c - '0';
}