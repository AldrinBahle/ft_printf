/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze_width.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 14:35:11 by agama             #+#    #+#             */
/*   Updated: 2018/08/04 12:30:54 by agama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	width_too_long(t_conversion *conversion, t_format *format)
{
	ft_putstr_fd("ft_printf: suspicious width given by * argument: ", 2);
	ft_putnbr_fd(conversion->width, 2);
	ft_putstr_fd("\n", 2);
	print_format_error(format);
	return (ERROR);
}

int			analyze_width(t_conversion *conversion, va_list arguments
						, t_format *format)
{
	size_t	i;
	char	current;

	if (*get_current(format) == '*')
	{
		conversion->width = va_arg(arguments, unsigned int);
		if (conversion->width > LARGEST_STAR_ARGUMENT)
		{
			width_too_long(conversion, format);
			conversion->width = 0;
		}
		format->location++;
	}
	else
	{
		i = 0;
		while ((current = *(get_current(format) + i)) && (ft_isdigit(current)))
		{
			ft_atoi_add_digit_u(current, &conversion->width);
			i++;
		}
		format->location += i;
	}
	return (OKAY);
}
