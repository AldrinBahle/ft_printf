# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agama <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/31 11:10:21 by agama             #+#    #+#              #
#    Updated: 2018/08/04 12:43:10 by agama            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 				= libftprintf.a
CC	 				= gcc
FLAGS				= -Wall -Werror -Wextra -c
FT_SRC_DIR			= ./libft
PRINTF_SRC_DIR		= ./printf
HEADER				= $(FT_SRC_DIR)libft.h
PRINTF_SRC_HEADER	= $(PRINTF_SRC_DIR)ft_printf.h

FT_OBJ = ft_memset.o ft_bzero.o ft_memcpy.o ft_memccpy.o ft_memmove.o ft_memchr.o \
		 ft_memcmp.o ft_strlen.o ft_strdup.o ft_strcpy.o ft_strcat.o ft_strncat.o \
		 ft_strlcat.o ft_strchr.o ft_strrchr.o ft_strstr.o ft_strnstr.o \
		 ft_strcmp.o ft_strncmp.o ft_atoi.o ft_isalpha.o ft_isdigit.o ft_isalnum.o \
		 ft_isascii.o ft_isprint.o ft_toupper.o ft_tolower.o ft_memalloc.o \
		 ft_memdel.o ft_strnew.o ft_strdel.o ft_strclr.o ft_striter.o ft_striteri.o \
		 ft_strmap.o ft_strmapi.o ft_strequ.o ft_strnequ.o ft_strsub.o ft_strjoin.o \
		 ft_strtrim.o ft_strsplit.o ft_itoa.o ft_putchar.o ft_putstr.o ft_putendl.o \
		 ft_putnbr.o ft_putchar_fd.o ft_putstr_fd.o ft_putendl_fd.o ft_putnbr_fd.o \
		 ft_lstnew.o ft_lstdelone.o ft_lstdel.o ft_lstadd.o ft_lstiter.o \
		 ft_lstmap.o ft_atoi_add_digit_u.o ft_putnbr_large_fd.o \
		 ft_count_digits_ularge.o ft_abs_large.o ft_itoa_write.o ft_putstrn_fd.o \
		 ft_wstrlen.o ft_putcharn.o ft_putcharn_fd.o ft_putstr_lateral_fd.o \
		 ft_count_chars.o ft_itoa_large.o ft_itoa_ularge.o ft_base_itoa.o \
		 ft_strncpy.o ft_strtolower.o 

PRINTF_OBJ = ft_printf.o handle_format.o analyze_conversion.o analyze_flags.o \
			 analyze_width.o analyze_precision.o analyze_length.o \
			 analyze_specifier.o validate_conversion.o validate_flags.o \
			 validate_flags_ignored.o print_conversion.o print_normal.o \
			 print_char.o print_wide_chars.o print_format_error.o \
			 get_current.o get_string_decimal.o get_string_string.o \
			 get_string_pointer.o get_string_hex.o get_string_octal.o \
			 add_final_padding.o add_precision_padding.o get_number_argument.o \
			 get_unsigned_number_argument.o

COMPILED = $(FT_OBJ) $(PRINTF_OBJ)

all: $(NAME)

$(NAME): $(COMPILED)
	@ar rc $(NAME) $(COMPILED)
	@ranlib $(NAME)

$(FT_OBJ): %.o: $(FT_SRC_DIR)/%.c
	@$(CC) $(FLAGS) -I $(FT_SRC_DIR) $< -o $@

$(PRINTF_OBJ): %.o: $(PRINTF_SRC_DIR)/%.c
	@$(CC) $(FLAGS) -I $(FT_SRC_DIR) -I $(PRINTF_SRC_DIR) $< -o $@

clean:
	rm -f $(COMPILED)

fclean:clean
	rm -f $(NAME)

re: fclean all
