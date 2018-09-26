/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze_length.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 11:25:05 by agama             #+#    #+#             */
/*   Updated: 2018/08/04 12:35:02 by agama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_length	get_length(char current, char next)
{
	if (current == 'h')
		return (next == 'h' ? HH : H);
	if (current == 'l')
		return (next == 'l' ? LL : L);
	if (current == 'j')
		return (J);
	if (current == 'z')
		return (Z);
	return (DEFAULT_LENGTH);
}

int				analyze_length(t_conversion *conversion, t_format *format)
{
	char		current;
	char		next;

	if (!(current = *get_current(format))
			|| !(next = *(get_current(format) + 1)))
		return (OKAY);
	conversion->length = get_length(current, next);
	if (conversion->length != DEFAULT_LENGTH)
		format->location++;
	if (conversion->length == HH || conversion->length == LL)
		format->location++;
	return (OKAY);
}
