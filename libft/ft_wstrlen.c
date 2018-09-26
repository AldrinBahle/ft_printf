/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 14:56:23 by agama             #+#    #+#             */
/*   Updated: 2018/07/28 15:02:33 by agama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t				ft_wstrlen(const wchar_t *source)
{
	const wchar_t	*end;

	end = source;
	while (*end != L'\0')
		end++;
	return (end - source);
}
