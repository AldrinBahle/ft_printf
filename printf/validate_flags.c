/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 12:54:02 by agama             #+#    #+#             */
/*   Updated: 2018/08/03 08:00:10 by agama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	show_positive_flags(t_conversion *conversion, t_format *format)
{
	if (conversion->flags.positive_vals_begin_blank
			|| conversion->flags.show_sign)
	{
		if (conversion->specifier != S_DECIMAL)
		{
			ft_putstr_fd("ft_printf: flag '", 2);
			ft_putchar_fd(conversion->flags.show_sign ? '+' : ' ', 2);
			ft_putstr_fd("' results in an undefined behaviour with '", 2);
			ft_putchar_fd(*get_current(format), 2);
			ft_putendl_fd("' conversion specifier", 2);
			print_format_error(format);
			return (ERROR);
		}
	}
	return (OKAY);
}

static int	zero_flag(t_conversion *conversion, t_format *format)
{
	if (conversion->flags.pad_with_zeros)
	{
		if (conversion->specifier == CHAR
				|| conversion->specifier == STRING
				|| conversion->specifier == POINTER)
		{
			ft_putstr_fd("ft_printf: flag '0' results in an undefined ", 2);
			ft_putstr_fd("behaviour with '", 2);
			ft_putchar_fd(*get_current(format), 2);
			ft_putendl_fd("' conversion specifier", 2);
			print_format_error(format);
			return (ERROR);
		}
	}
	return (OKAY);
}

static int	hashtag_flag(t_conversion *conversion, t_format *format)
{
	if (conversion->flags.hashtag)
	{
		if (!(conversion->specifier == HEX_LOWER
					|| conversion->specifier == HEX_UPPER
					|| conversion->specifier == OCTAL))
		{
			ft_putstr_fd("ft_printf: flag '#' results in an undefined ", 2);
			ft_putstr_fd("behaviour with '", 2);
			ft_putchar_fd(*get_current(format), 2);
			ft_putendl_fd("' conversion specifier", 2);
			print_format_error(format);
			return (ERROR);
		}
	}
	return (OKAY);
}

int			validate_flags(t_conversion *conversion, t_format *format)
{
	if (show_positive_flags(conversion, format) == OKAY
			&& zero_flag(conversion, format) == OKAY
			&& hashtag_flag(conversion, format) == OKAY)
	{
		validate_flags_ignored(conversion, format);
		return (OKAY);
	}
	return (ERROR);
}
