/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_under5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:29:10 by daalmeid          #+#    #+#             */
/*   Updated: 2022/01/05 17:30:43 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdio.h>

static int	get_next_num_lownbrs(int *arr_a, int nulnum, int size, int med)
{
	int			top;
	int			bottom;

	top = 0;
	while (arr_a[top] != nulnum && arr_a[top] >= med)
		top++;
	bottom = size - 1;
	while (bottom >= 0 && arr_a[bottom] >= med)
		bottom--;
	if (top <= size - 1 - bottom && bottom != -1)
		return (top);
	else if (top > size - 1 - bottom)
		return (bottom);
	return (nulnum);
}

static void	organize_under_5(int *arr_a, int *arr_b, int arg, int nulnum)
{
	int	med;
	int	i;

	med = find_median(arr_a, arg);
	while (arr_b[(arg / 2) - 1] == nulnum)
	{
		i = get_next_num_lownbrs(arr_a, nulnum, arg, med);
		if (arg - i < i)
		{
			while (i++ < arg)
				ft_revrot_a(arr_a, arg, nulnum);
		}
		else if (arg - i >= i)
		{
			while (i-- > 0)
				ft_rot_a(arr_a, arg, nulnum);
		}
		ft_push_b(arr_a, arr_b, arg--, nulnum);
	}
	if (arr_b[0] < arr_b[1])
		ft_swap_b(arr_b, nulnum);
	organize_low_nbrs(arr_a, arr_b, arg, nulnum);
}

void	organize_low_nbrs(int *arr_a, int *arr_b, int arg, int nulnum)
{
	if (arg <= 3)
	{
		if (arr_a[0] > arr_a[1])
			ft_swap_a(arr_a, nulnum);
		if (arr_a[0] > arr_a[arg - 1])
			ft_revrot_a(arr_a, arg, nulnum);
		if (arr_a[0] < arr_a[arg - 1] && arr_a[1] > arr_a[arg - 1])
		{
			ft_revrot_a(arr_a, arg, nulnum);
			ft_swap_a(arr_a, nulnum);
		}
		while (arr_b[0] != nulnum)
			ft_push_a(arr_a, arr_b, arg, nulnum);
	}
	else
		organize_under_5(arr_a, arr_b, arg, nulnum);
}
