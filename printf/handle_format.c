/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 11:11:57 by agama             #+#    #+#             */
/*   Updated: 2018/08/07 11:21:14 by agama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int			check_percent_percent(t_format *format)
{
	if (*get_current(format) == '%')
	{
		ft_putchar('%');
		format->location++;
		format->written++;
		return (1);
	}
	else
		return (0);
}

static void			handle_conversion(t_format *format, va_list arguments)
{
	t_conversion	conversion;

	if (check_percent_percent(format))
		return ;
	ft_bzero(&conversion, sizeof(t_conversion));
	if (analyze_conversion(&conversion, arguments, format) == OKAY &&
			validate_conversion(&conversion, format) == OKAY)
		print_conversion(&conversion, arguments, format);
	else if (*get_current(format) == '%')
	{
		ft_putchar('%');
		format->location++;
		format->written++;
	}
}

void				handle_format(t_format *format, va_list arguments)
{
	char			current;

	while ((current = *get_current(format)))
	{
		if (current == '%')
		{
			format->location++;
			handle_conversion(format, arguments);
		}
		else
		{
			ft_putchar(current);
			format->written++;
			format->location++;
		}
	}
}
