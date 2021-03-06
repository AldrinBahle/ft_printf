/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string_decimal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 15:18:59 by agama             #+#    #+#             */
/*   Updated: 2018/08/07 09:54:33 by agama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		add_prefix(t_conversion *conversion, char **string)
{
	char		*prefix;
	char		*new;

	if (ft_isdigit((*string)[0]))
	{
		prefix = NULL;
		if (conversion->flags.positive_vals_begin_blank)
			prefix = ft_strdup(" ");
		else if (conversion->flags.show_sign)
			prefix = ft_strdup("+");
		if (prefix)
		{
			new = ft_strjoin(prefix, *string);
			free(prefix);
			free(*string);
			*string = new;
		}
	}
}

char			*get_string_decimal(t_conversion *conversion, va_list arguments)
{
	char		*string;
	intmax_t	value;
	uintmax_t	unsigned_value;

	if (conversion->specifier == U_DECIMAL)
		unsigned_value = get_unsigned_number_argument(conversion->length
													, arguments);
	else
		value = get_number_argument(conversion->length, arguments);
	if ((conversion->specifier == U_DECIMAL ? unsigned_value == 0 : value == 0)
			&& conversion->precision_set && conversion->precision == 0)
		string = ft_strdup("");
	else if (conversion->specifier == S_DECIMAL)
		string = ft_itoa_large(value);
	else
		string = ft_itoa_ularge(unsigned_value);
	add_prefix(conversion, &string);
	add_precision_padding(conversion, &string);
	return (string);
}
