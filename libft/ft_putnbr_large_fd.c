/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_large_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 09:56:29 by agama             #+#    #+#             */
/*   Updated: 2018/07/23 10:05:41 by agama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_large_fd(intmax_t number, int file_descriptor)
{
	char	*string;

	string = ft_itoa_large(number);
	ft_putstr_fd(string, file_descriptor);
	free(string);
}
