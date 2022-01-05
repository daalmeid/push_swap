/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 18:37:06 by daalmeid          #+#    #+#             */
/*   Updated: 2022/01/05 17:47:57 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdio.h>

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

int	ind_next_num_push_b(int *arr_a, int nulnum, int size, int med)
{
	static int	previous_med = -2147483648;
	int			top;
	int			bottom;

	top = 0;
	while (top < size && arr_a[top] != nulnum && (arr_a[top] > med
			|| arr_a[top] <= previous_med))
		top++;
	bottom = size - 1;
	while (bottom >= 0 && (arr_a[bottom] > med
			|| arr_a[bottom] <= previous_med))
		bottom--;
	if (top <= size - 1 - bottom && bottom != -1)
		return (top);
	else if (top > size - 1 - bottom)
		return (bottom);
	previous_med = med;
	return (-1);
}

int	send_quarter_b(int *arr_a, int *arr_b, int arg, int nulnum)
{
	int	size;
	int	med;
	int	i;

	size = ft_arrlen(arr_a, nulnum, arg);
	med = find_quarter_median(arr_a, size);
	i = ind_next_num_push_b(arr_a, nulnum, size, med);
	while (i != -1)
	{
		if (size - i < i)
		{
			while (i++ < size)
				ft_revrot_a(arr_a, arg, nulnum);
		}
		else if (size - i >= i)
		{
			while (i-- > 0)
				ft_rot_a(arr_a, arg, nulnum);
		}
		ft_push_b(arr_a, arr_b, arg, nulnum);
		i = ind_next_num_push_b(arr_a, nulnum, --size, med);
	}
	return (med);
}

void	applying_sort(int *arr_a, int *arr_b, int arg, int nulnum)
{
	int		med1;
	int		med2;

	if (ft_check_order(arr_a, arg, nulnum) == 1)
		return ;
	else if (arg <= 5)
		organize_low_nbrs(arr_a, arr_b, arg, nulnum);
	else
	{
		med1 = send_quarter_b(arr_a, arr_b, arg, nulnum);
		order_push_b_to_a(arr_a, arr_b, arg, nulnum);
		med2 = send_quarter_b(arr_a, arr_b, arg, nulnum);
		organize_quarter_by_lstmed(arr_a, med1, arg, nulnum);
		order_push_b_to_a(arr_a, arr_b, arg, nulnum);
		med1 = send_quarter_b(arr_a, arr_b, arg, nulnum);
		organize_quarter_by_lstmed(arr_a, med2, arg, nulnum);
		order_push_b_to_a(arr_a, arr_b, arg, nulnum);
		med2 = send_quarter_b(arr_a, arr_b, arg, nulnum);
		order_push_b_to_a(arr_a, arr_b, arg, nulnum);
		organize_quarter_by_lstmed(arr_a, med2, arg, nulnum);
	}
}

int	main(int ac, char **av)
{
	int		*arr_a;
	int		*arr_b;
	int		nulnum;
	int		arg;

	if (ac == 1)
		return (0);
	arr_a = NULL;
	arr_b = NULL;
	arg = prep_arr_a(&arr_a, ac, av);
	if (arg <= 0)
	{
		if (arr_a)
		{
			free (arr_a);
			if (arg != 0)
				ft_putstr_fd("Error\n", 2);
		}
		return (0);
	}
	nulnum = ft_get_nullnum(arr_a, arg);
	if (!ft_prep_arr_b(&arr_b, arr_a, arg, nulnum))
	{
		free(arr_a);
		return (0);
	}
	applying_sort(arr_a, arr_b, arg, nulnum);
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
	free (arr_a);
	free (arr_b);
	return (0);
}
