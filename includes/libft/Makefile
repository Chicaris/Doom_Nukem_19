# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bruno <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/03 19:17:25 by bruno             #+#    #+#              #
#    Updated: 2019/03/04 16:28:20 by cbruno           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC =	ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c
SRC +=	ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c
SRC +=	ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c
SRC +=	ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c
SRC +=	ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c
SRC +=	ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c
SRC +=	ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c
SRC +=	ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c
SRC +=	ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c
SRC +=	ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c
SRC +=	ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c
SRC +=	ft_strnstr.c ft_strrchr.c ft_strsplit.c
SRC +=	ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c
SRC +=	ft_toupper.c ft_lstnew.c ft_lstnew.c ft_lstdelone.c
SRC +=  ft_lstadd.c ft_lstdel.c ft_lstiter.c ft_lstmap.c
SRC +=	ft_realloc.c ft_strtolow.c ft_capitalize.c ft_digitnb.c
SRC +=	ft_countwords.c ft_lst_reverse.c get_next_line.c
SRC +=	ft_lst_addback.c ft_nbofwords.c ft_split_whitespace.c
SRC +=	get_vector.c vector_cpy.c vector_normalize.c vector_div.c
SRC +=	vector_scale.c vector_cross.c vector_transform.c vector_diff.c
SRC +=  vector_add.c matrix_unit.c matrix_transpose.c matrix_multi.c
SRC +=  matrix_rotation_x.c matrix_rotation_y.c matrix_rotation_z.c
SRC +=  vector_init.c ft_printtab.c

OBJ = $(SRC:.c=.o)

DEL = rm -f

FLAG = -Wall -Werror -Wextra

.SILENT:

all: $(NAME)

$(NAME):
	gcc -c $(FLAG) $(SRC) -Iincludes
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	$(DEL) $(OBJ)

fclean: clean
	$(DEL) $(NAME)

re: fclean all
