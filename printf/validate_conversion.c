/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_conversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 14:35:11 by agama             #+#    #+#             */
/*   Updated: 2018/08/07 11:42:54 by agama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	put_length_string(t_length length)
{
	if (length == HH)
		ft_putstr_fd("hh", 2);
	else if (length == H)
		ft_putstr_fd("hh", 2);
	else if (length == L)
		ft_putstr_fd("l", 2);
	else if (length == LL)
		ft_putstr_fd("ll", 2);
	else if (length == J)
		ft_putstr_fd("j", 2);
	else if (length == Z)
		ft_putstr_fd("z", 2);
	else
		ft_putstr_fd("default", 2);
}

static int	pointer_has_specified_size(t_conversion *conversion
									, t_format *format)
{
	if (conversion->specifier == POINTER
			&& conversion->length != DEFAULT_LENGTH)
	{
		ft_putstr_fd("ft_printf: length modifier '", 2);
		put_length_string(conversion->length);
		ft_putstr_fd("' results in undefined behavior or no effect ", 2);
		ft_putendl_fd("with 'p' conversion specifier", 2);
		print_format_error(format);
		return (ERROR);
	}
	return (OKAY);
}

static int	precision_settable(t_conversion *conversion, t_format *format)
{
	char	specifier;

	if (conversion->precision_set
			&& ((conversion->specifier == CHAR && conversion->length >= L)
			|| conversion->specifier == POINTER))
	{
		specifier = *get_current(format);
		ft_putstr_fd("ft_printf: precision used with %", 2);
		ft_putchar_fd(specifier, 2);
		if (specifier == 2)
		{
			ft_putstr_fd(" and length modifier '", 2);
			put_length_string(conversion->length);
			ft_putstr_fd("'", 2);
		}
		ft_putchar_fd('\n', 2);
		print_format_error(format);
		return (ERROR);
	}
	return (OKAY);
}

static int	is_it_okay(t_conversion *conversion, t_format *format)
{
	if (pointer_has_specified_size(conversion, format) == OKAY
			&& validate_flags(conversion, format) == OKAY
			&& precision_settable(conversion, format) == OKAY)
		return (OKAY);
	return (ERROR);
}

int			validate_conversion(t_conversion *conversion, t_format *format)
{
	int		returned;

	format->location--;
	returned = is_it_okay(conversion, format);
	format->location++;
	return (returned);
}
