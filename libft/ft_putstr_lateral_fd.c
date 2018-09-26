/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_lateral_fd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 14:28:43 by agama             #+#    #+#             */
/*   Updated: 2018/08/02 15:16:50 by agama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_lateral(char c, int fd)
{
	if (c == '\n')
		ft_putstr_fd("\\n", fd);
	else if (c == '\t')
		ft_putstr_fd("\\t", fd);
	else
		ft_putchar_fd(c, fd);
}

void		ft_putstr_lateral_fd(char const *source, int file_descriptor)
{
	while (*source)
	{
		print_lateral(*source, file_descriptor);
		source++;
	}
}
