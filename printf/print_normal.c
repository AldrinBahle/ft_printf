/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_normal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 15:04:45 by agama             #+#    #+#             */
/*   Updated: 2018/07/28 15:19:20 by agama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*(*get_string_getter(t_specifier specifier))()
{
	if (specifier == STRING)
		return (get_string_string);
	else if (specifier == POINTER)
		return (get_string_pointer);
	else if (specifier == OCTAL)
		return (get_string_octal);
	else if (specifier == HEX_UPPER || specifier == HEX_LOWER)
		return (get_string_hex);
	else
		return (get_string_decimal);
}

void		print_normal(t_conversion *conversion, va_list arguments
					, t_format *format)
{
	char	*string;
	char	*(*getter)();

	getter = get_string_getter(conversion->specifier);
	string = getter(conversion, arguments, format);
	add_final_padding(conversion, &string);
	ft_putstr(string);
	format->written += ft_strlen(string);
	free(string);
}
