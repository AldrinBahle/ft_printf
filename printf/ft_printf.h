/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 10:43:49 by agama             #+#    #+#             */
/*   Updated: 2018/08/07 11:47:27 by agama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** ***************************** External Header *******************************
*/

# include "../libft/libft.h"
# include <stdarg.h>
# include <wchar.h>
# include <limits.h>

/*
** ***************************** Macros Defination *****************************
*/

# define PROGRAM_NAME			"ft_printf"
# define ERROR					1
# define OKAY					0
# define LARGEST_STAR_ARGUMENT	((unsigned int)INT_MAX)

/*
** ***************************** Boolean (char)variable ************************
*/

typedef char		t_bool;

/*
** ***************************** Enumerators Defination ************************
*/

typedef enum		e_length
{
	DEFAULT_LENGTH, HH, H, L, LL, J, Z
}					t_length;

typedef enum		e_specifier
{
	S_DECIMAL, U_DECIMAL, OCTAL, HEX_LOWER, HEX_UPPER, CHAR, STRING, POINTER,
	INVALID_SPECIFIER
}					t_specifier;

/*
** ***************************** Structure Definition *************************
*/

typedef struct		s_format
{
	const char		*string;
	size_t			location;
	size_t			written;
}					t_format;

typedef struct		s_flags
{
	t_bool			left_justify;
	t_bool			pad_with_zeros;
	t_bool			show_sign;
	t_bool			positive_vals_begin_blank;
	t_bool			hashtag;
}					t_flags;

typedef struct		s_conversion
{
	unsigned int	width;
	unsigned int	precision;
	t_bool			precision_set;
	t_flags			flags;
	t_length		length;
	t_specifier		specifier;
}					t_conversion;

/*
** ***************************** Sources ***************************************
*/

int					ft_printf(const char *format, ...);
void				handle_format(t_format *format, va_list arguments);
int					analyze_conversion(t_conversion *conversion
									, va_list arguments, t_format *format);
int					analyze_flags(t_conversion *conversion, t_format *format);
int					analyze_width(t_conversion *conversion, va_list arguments
								, t_format *format);
int					analyze_precision(t_conversion *conversion
									, va_list arguments, t_format *format);
int					analyze_length(t_conversion *conversion, t_format *format);
int					analyze_specifier(t_conversion *conversion
									, t_format *format);
int					validate_conversion(t_conversion *conversion
										, t_format *format);
int					validate_flags(t_conversion *conversion, t_format *format);
void				validate_flags_ignored(t_conversion *conversion
										, t_format *format);
void				print_conversion(t_conversion *conversion, va_list arguments
										, t_format *format);
void				print_normal(t_conversion *conversion, va_list arguments
										, t_format *format);
void				print_char(t_conversion *conversion, char argument
							, t_format *format);
void				print_wide_chars(t_conversion *conversion, wchar_t *string
								, size_t length, size_t *written);
void				print_format_error(t_format *format);
const char			*get_current(t_format *format);
char				*get_string_decimal(t_conversion *conversion
									, va_list arguments);
char				*get_string_string(t_conversion *conversion
									, va_list arguments);
char				*get_string_pointer(t_conversion *conversion
									, va_list arguments);
char				*get_string_hex(t_conversion *conversion
									, va_list arguments);
char				*get_string_octal(t_conversion *conversion
									, va_list arguments);
void				add_final_padding(t_conversion *conversion, char **string);
void				add_precision_padding(t_conversion *conversion
										, char **string);
intmax_t			get_number_argument(t_length length, va_list arguments);
uintmax_t			get_unsigned_number_argument(t_length length
												, va_list arguments);

#endif
