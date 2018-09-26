/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 09:19:08 by agama             #+#    #+#             */
/*   Updated: 2018/07/21 11:01:47 by agama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf(const char *format_string, ...)
{
	va_list		arguments;
	t_format	format;

	if (!format_string)
	{
		ft_putendl_fd("ft_printf: format string is NOT valid", 2);
		exit(1);
	}
	ft_bzero(&format, sizeof(t_format));
	format.string = format_string;
	va_start(arguments, format_string);
	handle_format(&format, arguments);
	va_end(arguments);
	return (format.written);
}
