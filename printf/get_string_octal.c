/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string_octal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 14:33:07 by agama             #+#    #+#             */
/*   Updated: 2018/08/03 08:24:41 by agama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*get_string_octal(t_conversion *conversion, va_list arguments)
{
	char		*string;
	char		*final;
	uintmax_t	value;

	value = get_unsigned_number_argument(conversion->length, arguments);
	if (!value && conversion->precision_set)
		string = ft_strdup("");
	else
		string = ft_base_itoa(value, 8);
	add_precision_padding(conversion, &string);
	if (conversion->flags.hashtag && string[0] != '0')
	{
		final = ft_strjoin("0", string);
		free(string);
	}
	else
		final = string;
	return (final);
}
