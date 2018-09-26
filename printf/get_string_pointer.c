/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string_pointer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 09:24:28 by agama             #+#    #+#             */
/*   Updated: 2018/07/30 10:49:31 by agama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*get_string_pointer(t_conversion *conversion, va_list arguments)
{
	char	*before;
	char	*string;
	long	value;

	value = (long)va_arg(arguments, void*);
	if (value == 0)
		return (ft_strdup("0x0"));
	before = ft_base_itoa(value, 16);
	ft_strtolower(before);
	string = ft_strjoin("0x", before);
	free(before);
	(void)conversion;
	(void)arguments;
	return (string);
}
