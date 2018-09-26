/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 13:54:01 by agama             #+#    #+#             */
/*   Updated: 2018/08/07 09:56:27 by agama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*get_string_hex(t_conversion *conversion, va_list arguments)
{
	char		*string;
	char		*final;
	uintmax_t	value;
	t_bool		is_zero;

	value = get_unsigned_number_argument(conversion->length, arguments);
	if (!value && conversion->precision_set)
		string = ft_strdup("");
	else
		string = ft_base_itoa(value, 16);
	if (conversion->specifier == HEX_LOWER)
		ft_strtolower(string);
	is_zero = string[0] == '0' || string[0] == '\0';
	add_precision_padding(conversion, &string);
	if ((conversion->flags.hashtag && !is_zero)
			&& !(conversion->precision_set && conversion->precision == 0))
	{
		final = ft_strjoin(conversion->specifier == HEX_LOWER ? "0x" : "0X"
						, string);
		free(string);
	}
	else
		final = string;
	return (final);
}
