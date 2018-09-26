/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 15:31:01 by agama             #+#    #+#             */
/*   Updated: 2018/05/19 16:18:51 by agama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t num_bts)
{
	char	*ptr;
	size_t	i;

	ptr = str;
	i = 0;
	while (i < num_bts)
		*(ptr + i++) = (unsigned char)c;
	return (str);
}
