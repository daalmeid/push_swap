/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_quicksort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 13:24:57 by daalmeid          #+#    #+#             */
/*   Updated: 2021/12/30 14:18:34 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdio.h>

int	find_median(int *arr_a, int size)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (j < size)
	{
		k = 0;
		i = 0;
		while (i < size)
		{
			if (arr_a[i] > arr_a[j])
				k++;
			else if (arr_a[i] < arr_a[j])
				k--;
			i++;
		}
		if (size % 2 == 0 && k == 1)
			break ;
		else if (size % 2 != 0 && k == 0)
			break ;  
		j++;
	}
	return (arr_a[j]);
}

int	get_next_num(int *arr_b, int nulnum, int size, int *next_num)
{
	int	i;
	int	big_index;
	int	small_index;
	int	num;

	i = 0;
	num = arr_b[0];
	big_index = 0;
	while (arr_b[i] != nulnum)
	{
		if (arr_b[i] > num)
		{
			num = arr_b[i];
			big_index = i;
		}
		i++;
	}
	i = 0;
	num = arr_b[0];
	small_index = 0;
	while (arr_b[i] != nulnum)
	{
		if (arr_b[i] < num)
		{
			num = arr_b[i];
			small_index = i;
		}
		i++;
	}
	if (big_index < small_index && big_index <= size - 1 - small_index)
	{
		*next_num = big_index;
		i = 0;
	}
	else if (big_index > small_index && small_index >= size - 1 - big_index)
	{
		*next_num = big_index;
		i = 1;
	}
	else if (small_index < big_index && small_index <= size - 1 - big_index)
	{
		*next_num = small_index;
		i = 2;
	}
	else if (small_index > big_index && big_index >= size - 1 - small_index)
	{
		*next_num = small_index;
		i = 3;
	}
	return (i);
}

void	rec_organize_b(int *arr_a, int *arr_b, int arg, int nulnum)
{
	int	size;
	int	j;
	int	big_or_small;
	int index_next_num;

	if (arr_b[0] == nulnum)
		return ;
	j = 0;
	size = 0;
	while (arr_b[size] != nulnum && size < arg)
		size++;
	while (j < size)
	{
		big_or_small = get_next_num(arr_b, nulnum, size, &index_next_num);
		if (index_next_num <= size / 2)
		{	
			while (index_next_num > 0)
			{
				ft_rot_b(arr_b, arg, nulnum);
				index_next_num--;
			}
		}
		else if (index_next_num > size /2)
		{
			while (index_next_num < size)
			{	
				ft_revrot_b(arr_b, arg, nulnum);
				index_next_num++;
			}
		}
		ft_push_a(arr_a, arr_b, arg, nulnum);
		size--;
		if (big_or_small == 2 || big_or_small == 3)
			ft_rot_a(arr_a, arg, nulnum);
		/*i = 0;
		while (i < arg)
		{
			printf("%d ", arr_a[i]);
			i++;
		}
		printf("\n");
		i = 0;
		while (i < arg)
		{
			printf("%d ", arr_b[i]);
			i++;
		}
		printf("\n");*/
	}
}

/*void	organize_low_nbrs(int *arr_a, int *arr_b, int arg, int nulnum)
{
	int	med;
	int	size;
	int	i;
	int	med_half;
	//int biggest;
	int	tmp = 0;

	if (arr_a[0] > arr_a[1])
		ft_swap_a(arr_a, nulnum);
	if (arr_a[0] > arr_a[size - 1])
		ft_revrot_a(arr_a, arg, nulnum);
	if (arr_a[0] < arr_a[size - 1] && arr_a[1] > arr_a[size - 1])
	{
		ft_revrot_a(arr_a, arg, nulnum);
		ft_swap_a(arr_a, nulnum);
	}
}*/

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
