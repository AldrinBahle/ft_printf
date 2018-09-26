/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcharn_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 13:08:12 by agama             #+#    #+#             */
/*   Updated: 2018/07/29 13:12:50 by agama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putcharn_fd(char c, size_t number, int file_descriptor)
{
	size_t	i;

	i = 0;
	while (i < number)
	{
		ft_putchar_fd(c, file_descriptor);
		i++;
	}
}
