# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/20 15:18:15 by daalmeid          #+#    #+#              #
#    Updated: 2022/01/07 17:16:39 by daalmeid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	= push_swap

SRCS	= push_swap.c push_swap_moves1.c push_swap_moves2.c push_swap_moves3.c\
		  push_b_to_a.c get_median.c arrays_prep_and_arrlen.c sort_under5.c\
		  error_checks_and_nulnum.c\

RM = rm -f

LIBFT = libft.a

$(NAME): $(LIBFT)
	gcc -Wextra -Wall -Werror $(SRCS) -L. -lft -o $(NAME) -g

$(OBJS):
	gcc -Wall -Wextra -Werror -c $(SRCS)

$(LIBFT):
	cd libft/ && make && mv libft.a ../ && cp libft.h ../
	
all:	$(NAME)

clean:
	$(RM) $(LIBFT) libft.h

fclean:	clean
	$(RM) $(NAME)

re:		fclean all

bonus: clean
	gcc -Wall -Wextra -Werror -c $(SRCS_BONUS)
	ar rc $(NAME) $(OBJS)
