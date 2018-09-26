/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 13:40:22 by agama             #+#    #+#             */
/*   Updated: 2018/08/07 11:37:50 by agama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t			count_special_char(const char *haystack, size_t length)
{
	size_t		sp_char;

	sp_char = ft_count_chars(haystack, '\t', length)
			+ ft_count_chars(haystack, '\n', length);
	return (sp_char);
}

void			print_format_error(t_format *format)
{
	intmax_t	tildes_before;
	intmax_t	tildes_after;

	ft_putstr_fd(PROGRAM_NAME, 2);
	ft_putstr_fd("(\"", 2);
	ft_putstr_lateral_fd(format->string, 2);
	ft_putstr_fd("\")\n", 2);
	ft_putcharn_fd(' ', ft_strlen(PROGRAM_NAME) + 2, 2);
	tildes_before = format->location
			+ count_special_char(format->string, format->location);
	if (tildes_before > 0)
		ft_putcharn_fd('~', tildes_before, 2);
	ft_putchar_fd('^', 2);
	tildes_after = ft_strlen(format->string) - tildes_before - 1;
	tildes_after += count_special_char(format->string + format->location
									, tildes_after + 1);
	if (tildes_after > 0)
		ft_putcharn_fd('~', tildes_after, 2);
	ft_putchar_fd('\n', 2);
}
