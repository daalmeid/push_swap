/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 13:24:57 by daalmeid          #+#    #+#             */
/*   Updated: 2022/01/05 17:38:16 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdio.h>

static void	get_indx(int *arr_b, int *small_index, int *big_index, int nulnum)
{
	int	i;
	int	num;

	i = 0;
	num = arr_b[0];
	while (arr_b[i] != nulnum)
	{
		if (arr_b[i] > num)
		{
			num = arr_b[i];
			*big_index = i;
		}
		i++;
	}
	i = 0;
	num = arr_b[0];
	while (arr_b[i] != nulnum)
	{
		if (arr_b[i] < num)
		{
			num = arr_b[i];
			*small_index = i;
		}
		i++;
	}
}

static int	get_next_num(int *arr_b, int nulnum, int size, int *next_num)
{
	int	big_index;
	int	small_index;

	big_index = 0;
	small_index = 0;
	get_indx(arr_b, &small_index, &big_index, nulnum);
	if ((big_index <= small_index && big_index <= size - 1 - small_index)
		|| (big_index > small_index && small_index > size - 1 - big_index))
	{
		*next_num = big_index;
		return (0);
	}
	else if ((small_index < big_index && small_index <= size - 1 - big_index)
		|| (small_index > big_index && big_index > size - 1 - small_index))
		*next_num = small_index;
	return (1);
}

void	order_push_b_to_a(int *arr_a, int *arr_b, int arg, int nulnum)
{
	int	size;
	int	big_or_small;
	int	index_next_num;

	size = ft_arrlen(arr_b, nulnum, arg);
	while (size > 0)
	{
		big_or_small = get_next_num(arr_b, nulnum, size, &index_next_num);
		if (index_next_num <= size / 2)
		{	
			while (index_next_num-- > 0)
				ft_rot_b(arr_b, arg, nulnum);
		}
		else if (index_next_num > size / 2)
		{
			while (index_next_num++ < size)
				ft_revrot_b(arr_b, arg, nulnum);
		}
		ft_push_a(arr_a, arr_b, arg, nulnum);
		size--;
		if (big_or_small == 1)
			ft_rot_a(arr_a, arg, nulnum);
	}
}

/*int	main(int ac, char **av)
{
	int		*arr_a = NULL;
	int		*arr_b = NULL;
	int		i;
	int		j;

	if (ac <= 1)
		return (0);
	j = prep_arr_a(&arr_a, &arr_b, ac, av);
	i = ft_get_nullnum(arr_a, j);
	ft_prep_arr_b(arr_b, j, i);
	if (!j)
	{
		ft_putstr_fd("Error\n", 2);
		free (arr_a);
		free (arr_b);
		return (0);
	}
	if (!(ft_check_order(arr_a, j, i) && arr_b[0] == i))
	{	
		while (choose_organize_a(arr_a, arr_b, j, i) != 3)
			continue ;
	}
	i = 0;
	while (i < j)
	{
		printf("%d ", arr_a[i]);
		i++;
	}
	printf("\n");
	i = 0;
	while (i < j)
	{
		printf("%d ", arr_b[i]);
		i++;
	}
	printf("\n");
	free (arr_a);
	free (arr_b);
	return (0);
}*/
