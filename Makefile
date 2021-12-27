# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/20 15:18:15 by daalmeid          #+#    #+#              #
#    Updated: 2021/12/27 17:42:27 by daalmeid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	= push_swap

SRCS	= push_swap.c push_swap_utils.c push_swap_utils2.c test_quicksort.c\

RM = rm -f

LIBFT = libft.a

$(NAME): $(LIBFT)
	gcc -Wextra -Wall -Werror $(SRCS) -L. -lft -o $(NAME)

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
