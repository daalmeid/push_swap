/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:09:59 by daalmeid          #+#    #+#             */
/*   Updated: 2022/01/07 14:52:55 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdio.h>

void	ft_revrot_a(int *arr_a, int arg, int nulnum)
{
	int	tmp;
	int	i;

	i = arg - 1;
	while (i > 0 && arr_a[i] == nulnum)
		i--;
	tmp = arr_a[i];
	while (i > 0)
	{
		arr_a[i] = arr_a[i - 1];
		i--;
	}
	arr_a[i] = tmp;
	ft_putstr_fd("rra\n", 1);
}

void	ft_revrot_b(int *arr_b, int arg, int nulnum)
{
	int	tmp;
	int	i;

	i = arg - 1;
	while (i > 0 && arr_b[i] == nulnum)
		i--;
	tmp = arr_b[i];
	while (i > 0)
	{
		arr_b[i] = arr_b[i - 1];
		i--;
	}
	arr_b[i] = tmp;
	ft_putstr_fd("rrb\n", 1);
}

void	ft_revrot_ab(int *arr_a, int *arr_b, int arg, int nulnum)
{
	int	tmp;
	int	i;

	i = arg - 1;
	while (i > 0 && arr_a[i] == nulnum)
		i--;
	tmp = arr_a[i];
	while (i > 0)
	{
		arr_a[i] = arr_a[i - 1];
		i--;
	}
	arr_a[i] = tmp;
	i = arg - 1;
	while (i > 0 && arr_b[i] == nulnum)
		i--;
	tmp = arr_b[i];
	while (i > 0)
	{
		arr_b[i] = arr_b[i - 1];
		i--;
	}
	arr_b[i] = tmp;
	ft_putstr_fd("rrr\n", 1);
}
