/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_precision_padding.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 15:02:35 by agama             #+#    #+#             */
/*   Updated: 2018/08/07 09:37:51 by agama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		precision_padding_decimal(t_conversion *conversion
										, char **string)
{
	int			offset;
	char		*new;
	intmax_t	length;
	intmax_t	needed;

	length = ft_strlen(*string);
	offset = ft_isdigit(**string) ? 0 : 1;
	needed = (conversion->flags.pad_with_zeros ? conversion->width
			: conversion->precision + offset) - length;
	if (needed > 0)
	{
		new = ft_strnew(length + needed + offset);
		if (offset)
			new[0] = **string;
		ft_memset(new + offset, '0', needed);
		ft_strcpy(new + needed + offset, *string + offset);
		free(*string);
		*string = new;
	}
}

static void		precision_padding_regular(t_conversion *conversion
										, char **string)
{
	char		*new;
	intmax_t	needed;
	intmax_t	length;

	length = ft_strlen(*string);
	needed = (conversion->flags.pad_with_zeros ? conversion->width
			: conversion->precision) - length;
	if (needed > 0)
	{
		new = ft_strnew(length + needed);
		ft_memset(new, '0', needed);
		ft_strcpy(new + needed, *string);
		free(*string);
		*string = new;
	}
}

void			add_precision_padding(t_conversion *conversion
									, char **string)
{
	if (conversion->specifier == S_DECIMAL
			|| conversion->specifier == U_DECIMAL)
		precision_padding_decimal(conversion, string);
	else
		precision_padding_regular(conversion, string);
}
