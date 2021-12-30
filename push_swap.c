/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 18:37:06 by daalmeid          #+#    #+#             */
/*   Updated: 2021/12/30 16:26:23 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdio.h>

int	find_index_lowest(int *arr_a, int nulnum, int arrlen)
{
	int	index;
	int nbr;
	int	i;

	index = 0;
	nbr = arr_a[0];
	i = 0;
	while (i < arrlen && arr_a[i] != nulnum)
	{
		if (arr_a[i] < nbr)
		{
			nbr = arr_a[i];
			index = i;
		}
		i++;
	}
	return (index);
}

void	organize_quarter_by_lstmed(int *arr_a, int med, int arg, int nulnum)
{
	int	ind_med;

	arg = ft_arrlen(arr_a, nulnum, arg);
	ind_med = 0;
	while (arr_a[ind_med] != med)
		ind_med++;
	if (arg - 1 - ind_med < ind_med)
	{
		while (ind_med++ < arg - 1)
			ft_revrot_a(arr_a, arg, nulnum);
	}
	else if (arg - 1 - ind_med >= ind_med)
	{
		while (arr_a[arg - 1] != med)
			ft_rot_a(arr_a, arg, nulnum);
	}
}

void	organize_quarter(int *arr_a, int med, int arg, int nulnum)
{
	int	ind_lowest;
	int	ind_med;

	arg = ft_arrlen(arr_a, nulnum, arg);
	ind_med = 0;
	ind_lowest = find_index_lowest(arr_a, nulnum, arg);
	while (arr_a[ind_med] != med)
		ind_med++;
	if (ind_med < ind_lowest)
	{
		if (arg - 1 - ind_lowest < ind_med)
		{
			while (ind_lowest++ != arg)
				ft_revrot_a(arr_a, arg, nulnum);
		}
		else if (arg - 1 - ind_lowest >= ind_med)
		{
			while (arr_a[arg - 1] != med)
				ft_rot_a(arr_a, arg, nulnum);
		}
	}
}

void	ft_print(int *arr_a, int *arr_b, int arg)
{
	int	i;

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
}

int	ft_arrlen(int *arr, int nulnum, int arg)
{
	int	size;
	
	size = 0;
	while (arr[size] != nulnum && size < arg)
		size++;
	return (size);
}

int	find_quarter_median(int *arr_a, int nulnum, int arg)
{
	int	size = ft_arrlen(arr_a, nulnum, arg);
	static int	med = 2147483647;
	int	tmp_arr[(size / 2) + (size % 2)];
	int	i;
	int	j;

	i = find_median(arr_a, size);
	if (med < i)
	{
		med = i;
		return (med);
	}
	else if (med == i)
	{
		i = 0;
		j = 0;
		while (i < size)
		{
			if (arr_a[i] > med)
				tmp_arr[j++] = arr_a[i];
			i++;
		}
		med = find_median(tmp_arr, size / 2);
		return (med);
	}
	else if (med > i && med != 2147483647)	
	{
		i = 0;
		j = 0;
		med = arr_a[0];
		while (i < size)
		{
			if (arr_a[i] > med)
				med = arr_a[i];
			i++;
		}
		return (med);
	}
	med = i;
	i = 0;
	j = 0;
	while (i < size)
	{
		if (arr_a[i] <= med)
			tmp_arr[j++] = arr_a[i];
		i++;
	}
	med = find_median(tmp_arr, size / 2 + size % 2);
	return (med);
}

int	get_next_num_test(int *arr_a, int nulnum, int size, int med)
{
	static int	previous_med = -2147483648;
	int	top;
	int	bottom;

	top = 0;
	while (arr_a[top] != nulnum && (arr_a[top] > med || arr_a[top] <= previous_med))
		top++;
	bottom = size - 1;
	while (bottom >= 0 && (arr_a[bottom] > med || arr_a[bottom] <= previous_med))
		bottom--;
	if (top < size - 1 - bottom)
		return (top);
	else if (top >= size - 1 - bottom && bottom != -1)
		return (bottom);
	previous_med = med;
	return (-1);
}

int	send_quarter_b(int *arr_a, int *arr_b, int arg, int nulnum)
{
	int	size;
	int	med;
	int	i;

	med = find_quarter_median(arr_a, nulnum, arg);
	size = ft_arrlen(arr_a, nulnum, arg);
	i = get_next_num_test(arr_a, nulnum, size, med);
	while (i != -1)
	{
		if (size - i <= i)
		{
			while (i++ < size)
				ft_revrot_a(arr_a, arg, nulnum);
		}
		else if (size - i > i)
		{
			while (i-- > 0)
				ft_rot_a(arr_a, arg, nulnum);
		}
		ft_push_b(arr_a, arr_b, arg, nulnum);
		i = get_next_num_test(arr_a, nulnum, --size, med);
		//ft_print(arr_a, arr_b, arg);
	}
	return (med);
}

int	main(int ac, char **av)
{
	int		*arr_a = NULL;
	int		*arr_b = NULL;
	int		nulnum;
	int		arg;
	int		med1;
	int		med2;

	if (ac <= 1)
		return (0);
	arg = prep_arr_a(&arr_a, &arr_b, ac, av);
	nulnum = ft_get_nullnum(arr_a, arg);
	ft_prep_arr_b(arr_b, arg, nulnum);
	if (!arg)
	{
		ft_putstr_fd("Error\n", 2);
		free (arr_a);
		free (arr_b);
		return (0);
	}
	med1 = send_quarter_b(arr_a, arr_b, arg, nulnum);
	rec_organize_b(arr_a, arr_b, arg, nulnum);
	med2 = send_quarter_b(arr_a, arr_b, arg, nulnum);
	organize_quarter_by_lstmed(arr_a, med1, arg, nulnum);
	rec_organize_b(arr_a, arr_b, arg, nulnum);
	med1 = send_quarter_b(arr_a, arr_b, arg, nulnum);
	organize_quarter_by_lstmed(arr_a, med2, arg, nulnum);
	rec_organize_b(arr_a, arr_b, arg, nulnum);
	med2 = send_quarter_b(arr_a, arr_b, arg, nulnum);
	rec_organize_b(arr_a, arr_b, arg, nulnum);
	organize_quarter_by_lstmed(arr_a, med2, arg, nulnum);
	/*i = 0;
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
	printf("\n");*/
	free (arr_a);
	free (arr_b);
	return (0);
}
