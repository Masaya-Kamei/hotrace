# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/23 23:37:22 by hyoshie           #+#    #+#              #
#    Updated: 2022/04/06 14:57:33 by mkamei           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

vpath   %.c srcs:srcs/dclist:srcs/gnl:srcs/utils

SRCS	=	main.c htable_utils.c htable_search.c htable_store.c
SRCS	+=	dclst_addback.c dclst_clear.c dclst_delone.c dclst_exist.c \
			dclst_first.c dclst_issentinel.c dclst_last.c dclst_link.c \
			dclst_new_size.c dclst_pop.c dclst_popdel_next.c \
			dclst_with_take_p.c dclst_new.c
SRCS	+=	get_next_line.c get_next_line_utils.c
SRCS	+=	put.c str.c

SRCSDIR	=	./srcs

OBJSDIR	=	./objs
OBJS	=	$(addprefix $(OBJSDIR)/, $(SRCS:.c=.o))
DEPS	=	$(addprefix $(OBJSDIR)/, $(SRCS:.c=.d))

INCLUDE =	-I./includes/
NAME	=	hotrace

CC		=	gcc
CFLAGS	+=	-Wall -Wextra -Werror
CFLAGS	+=	-MMD -MP
RM		=	rm -rf

all			:	$(NAME)

$(NAME)		:	$(OBJS)
				$(CC) $(CFLAGS) $(INCLUDE) -o $@ $^

$(OBJSDIR)/%.o	:	%.c
			@mkdir -p $(dir $@)
			$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<

-include $(DEPS)

clean		:
				$(RM) $(OBJS) $(DEPS)

fclean		:	clean
				$(RM) $(NAME)

re			:	fclean all

debug		:	CFLAGS	+=	-g
debug		:	re

address		:	CFLAGS	+=	-g -fsanitize=address
address		:	re

leak		:	CC		=	/usr/local/opt/llvm/bin/clang
leak		:	CFLAGS	+=	-g -fsanitize=leak
leak		:	re

thread		:	CFLAGS	+=	-g -fsanitize=thread
thread		:	re

.PHONY		:	all clean fclean re debug address leak
