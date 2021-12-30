# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/20 15:18:15 by daalmeid          #+#    #+#              #
#    Updated: 2021/12/30 15:47:11 by daalmeid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	= push_swap

SRCS	= push_swap.c push_swap_utils.c push_swap_utils2.c push_swap_utils3.c\
		  push_swap_utils4.c

RM = rm -f

LIBFT = libft.a

$(NAME): $(LIBFT)
	gcc -Wextra -Wall -Werror $(SRCS) -L. -lft -o $(NAME) -g

$(OBJS):
	gcc -Wall -Wextra -Werror -c $(SRCS)

$(LIBFT):
	cd libft/ && make && mv libft.a ../
	
all:	$(NAME)

clean:
	$(RM) $(LIBFT)

fclean:	clean
	$(RM) $(NAME)

re:		fclean all

bonus: clean
	gcc -Wall -Wextra -Werror -c $(SRCS_BONUS)
	ar rc $(NAME) $(OBJS)
