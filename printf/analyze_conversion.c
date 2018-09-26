/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze_conversion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 12:07:24 by agama             #+#    #+#             */
/*   Updated: 2018/08/07 09:39:06 by agama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	analyze_conversion(t_conversion *conversion, va_list arguments
					, t_format *format)
{
	if (analyze_flags(conversion, format) == OKAY
			&& analyze_width(conversion, arguments, format) == OKAY
			&& analyze_precision(conversion, arguments, format) == OKAY
			&& analyze_length(conversion, format) == OKAY
			&& analyze_specifier(conversion, format) == OKAY)
		return (OKAY);
	return (ERROR);
}
