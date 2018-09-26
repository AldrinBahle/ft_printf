/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrn_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 12:53:41 by agama             #+#    #+#             */
/*   Updated: 2018/07/23 12:57:52 by agama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putstrn_fd(char const *source, size_t max_length
					, int file_descriptor)
{
	size_t	length;

	length = ft_strlen(source);
	if (max_length < length)
		length = max_length;
	write(file_descriptor, source, length);
}
