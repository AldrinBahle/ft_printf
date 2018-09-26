/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 14:25:32 by agama             #+#    #+#             */
/*   Updated: 2018/08/03 08:07:36 by agama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_wide_string(t_conversion *conversion, wchar_t *string
							, size_t *written)
{
	if (string)
		print_wide_chars(conversion, string, ft_wstrlen(string), written);
	else
	{
		ft_putstr("null");
		*written += 6;
	}
}

static void	print_wide_char(t_conversion *conversion, wint_t wint
		, t_format *format)
{
	wchar_t	wchar;

	if (wint > 0x10FFFF)
	{
		ft_putstr_fd("ft_printf: invalid wide character encountered", 2);
		print_format_error(format);
	}
	else
	{
		wchar = (wchar_t)wint;
		print_wide_chars(conversion, &wchar, 1, &format->written);
	}
}

void		print_conversion(t_conversion *conversion, va_list arguments
						, t_format *format)
{
	if (conversion->length >= L && conversion->specifier == STRING)
		print_wide_string(conversion, va_arg(arguments, wchar_t*)
						, &format->written);
	else if (conversion->specifier == CHAR)
	{
		if (conversion->length >= L)
			print_wide_char(conversion, va_arg(arguments, wchar_t), format);
		else
			print_char(conversion, (char)va_arg(arguments, int), format);
	}
	else
		print_normal(conversion, arguments, format);
}
