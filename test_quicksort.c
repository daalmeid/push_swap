/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_quicksort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 13:24:57 by daalmeid          #+#    #+#             */
/*   Updated: 2021/12/23 14:41:42 by daalmeid         ###   ########.fr       */
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

int	get_next_num(int *arr_b, int nulnum)
{
	int	i;
	int	num;

	i = 0;
	num = arr_b[0];
	while (arr_b[i] != nulnum)
	{
		if (arr_b[i] > num)
			num = arr_b[i];
		i++;
	}
	return (num);
}

void	rec_organize_b(int *arr_a, int *arr_b, int arg, int nulnum, int size)
{
	int	i;
	int	j;
	int next_num;

	j = 0;
	while (j < size)
	{
		next_num = get_next_num(arr_b, nulnum);
		i = 0;
		while (arr_b[i] != next_num)
			i++;
		if (i <= size)
		{	
			while (arr_b[0] != next_num && arr_b[1] != next_num)
				ft_rot_b(arr_b, arg, nulnum);
			if (arr_b[1] == next_num)
				ft_swap_b(arr_b, nulnum);
			ft_push_a(arr_a, arr_b, arg, nulnum);
		}
		else if (i > size)
		{
			while (arr_b[0] != next_num)
				ft_revrot_b(arr_b, arg, nulnum);
			ft_push_a(arr_a, arr_b, arg, nulnum);
		}
		j++;
	}
}

void	rec_organize_a(int *arr_a, int *arr_b, int arg, int nulnum)
{
	int	med;
	int	size;
	int	i;
	
	size = 0;
	i = 0;
	while (arr_a[size] != nulnum && size < arg)
		size++;
	med = find_median(arr_a, size);
	printf("median a: %d\n\n", med);
	while ((i <= size / 2 && size % 2 != 0) || (i < size / 2 && size % 2 == 0))
	{
		if (arr_a[0] <= med)
		{
			ft_push_b(arr_a, arr_b, arg, nulnum);
			i++;
		}
		else if (arr_a[0] > med)
			ft_rot_a(arr_a, arg, nulnum);
	}
	i = 0;
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
	printf("\n");
	if (size >= 5)
		rec_organize_a(arr_a, arr_b, arg, nulnum);
	if (size < 5 && arr_a[0] > arr_a[1])
		ft_swap_a(arr_a, nulnum);
	if (size < 5 && arr_b[0] < arr_b[1])
		ft_swap_b(arr_b, nulnum);
	rec_organize_b(arr_a, arr_b, arg, nulnum, size / 2 + (size % 2));
}

int	main(int ac, char **av)
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
	rec_organize_a(arr_a, arr_b, j, i);
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
}
