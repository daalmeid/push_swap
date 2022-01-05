/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_median.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 16:52:12 by daalmeid          #+#    #+#             */
/*   Updated: 2022/01/05 17:20:09 by daalmeid         ###   ########.fr       */
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

static int	check_quarter_size(int size, int k)
{
	static int	counter = 0;

	if ((((size / 2 + size % 2) % 2 == 0 && k == 1)
			|| ((size / 2 + size % 2) % 2 != 0 && k == 0)) && counter == 0)
	{
		counter++;
		return (1);
	}
	else if ((((size / 2) % 2 == 0 && k == 1)
			|| ((size / 2) % 2 != 0 && k == 0)) && counter == 1)
		return (1);
	return (0);
}

static int	median_of_half(int *arr_a, int size, int med)
{
	static int	prev_med = -2147483648;
	int			i;
	int			j;
	int			k;

	j = 0;
	while (j < size)
	{
		k = 0;
		i = 0;
		while (i < size)
		{
			if (arr_a[i] > arr_a[j] && arr_a[i] <= med && arr_a[i] > prev_med)
				k++;
			else if (arr_a[i] < arr_a[j] && arr_a[i] <= med
				&& (arr_a[i] > prev_med || (arr_a[i] == -2147483648
						&& arr_a[i] == prev_med)))
				k--;
			i++;
		}
		if (check_quarter_size(size, k))
			break ;
		j++;
	}
	prev_med = med;
	return (arr_a[j]);
}

static int	get_largest_nbr(int *arr_a, int size)
{
	int	lrg_nbr;
	int	j;

	j = 0;
	lrg_nbr = arr_a[0];
	while (j < size)
	{
		if (arr_a[j] > lrg_nbr)
			lrg_nbr = arr_a[j];
		j++;
	}
	return (lrg_nbr);
}

int	find_quarter_median(int *arr_a, int size)
{
	static int	med = 2147483647;
	int			i;
	int			j;

	i = find_median(arr_a, size);
	j = 0;
	if (med < i)
		med = i;
	else if (med == i)
	{
		med = get_largest_nbr(arr_a, size);
		med = median_of_half(arr_a, size, med);
	}
	else if (med > i && med != 2147483647)
		med = get_largest_nbr(arr_a, size);
	else
		med = median_of_half(arr_a, size, i);
	return (med);
}
