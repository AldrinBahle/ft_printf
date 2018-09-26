/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_flags_ignored.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 13:51:14 by agama             #+#    #+#             */
/*   Updated: 2018/08/03 08:06:41 by agama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	begin_blank_show_sign(t_conversion *conversion, t_format *format)
{
	if (conversion->flags.positive_vals_begin_blank
			&& conversion->flags.show_sign)
	{
		ft_putendl_fd("flag ' ' is ignored when '+' is present", 2);
		print_format_error(format);
		conversion->flags.positive_vals_begin_blank = 0;
	}
}

void	pad_zeros_general(t_conversion *conversion, t_format *format)
{
	if (conversion->flags.pad_with_zeros)
	{
		if (conversion->flags.left_justify)
		{
			ft_putendl_fd("flag '0' is ignored when flag '-' is present", 2);
			print_format_error(format);
			conversion->flags.pad_with_zeros = 0;
		}
		else if (conversion->precision_set)
		{
			ft_putstr_fd("flag '0' is ignored with precision and %", 2);
			ft_putchar_fd(*get_current(format), 2);
			ft_putchar_fd('\n', 2);
			print_format_error(format);
			conversion->flags.pad_with_zeros = 0;
		}
	}
}

void	validate_flags_ignored(t_conversion *conversion, t_format *format)
{
	begin_blank_show_sign(conversion, format);
	pad_zeros_general(conversion, format);
}
