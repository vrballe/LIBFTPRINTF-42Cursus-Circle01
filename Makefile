# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vballe <vballe@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/28 12:36:11 by vballe            #+#    #+#              #
#    Updated: 2022/11/28 13:35:38 by vballe           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
AR	= ar -rcs
RM		= rm -f


FILES	=	ft_printf\
			print_character\
			print_hexadecimal\
			print_number\
			print_pointer_address\
			print_string\
			print_unsigned_integer\


SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

.c.o:	$(SRCS)
	$(CC)	$(CFLAGS) -c -o $@ $<
	
$(NAME):	$(OBJS)
	$(AR) $@ $^

all:	$(NAME)

clean:
	$(RM)	$(OBJS)	$(OBJS_B)

fclean:	clean
	$(RM)	$(NAME)

re:	clean all

.PHONY:	bonus all clean fclean re