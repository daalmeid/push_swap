/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 17:04:32 by daalmeid          #+#    #+#             */
/*   Updated: 2022/01/07 14:53:14 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include "push_swap.h"

void	ft_swap_a(int *arr, int nulnum)
{
	int	tmp;

	if (arr[0] == nulnum || arr[1] == nulnum)
		return ;
	tmp = arr[0];
	arr[0] = arr[1];
	arr[1] = tmp;
	ft_putstr_fd("sa\n", 1);
}

void	ft_swap_b(int *arr, int nulnum)
{
	int	tmp;

	if (arr[0] == nulnum || arr[1] == nulnum)
		return ;
	tmp = arr[0];
	arr[0] = arr[1];
	arr[1] = tmp;
	ft_putstr_fd("sb\n", 1);
}

void	ft_swap_ab(int *arr_a, int *arr_b, int nulnum)
{
	int	tmp;

	if (arr_a[0] == nulnum || arr_a[1] == nulnum)
		return ;
	if (arr_b[0] == nulnum || arr_b[1] == nulnum)
		return ;
	tmp = arr_a[0];
	arr_a[0] = arr_a[1];
	arr_a[1] = tmp;
	tmp = arr_b[0];
	arr_b[0] = arr_b[1];
	arr_b[1] = tmp;
	ft_putstr_fd("ss\n", 1);
}

void	ft_push_a(int *arr_a, int *arr_b, int arg, int nulnum)
{
	int	i;

	i = 0;
	if (*arr_b == nulnum)
		return ;
	while (i < arg - 1)
		i++;
	while (i > 0)
	{
		arr_a[i] = arr_a[i - 1];
		i--;
	}
	arr_a[0] = arr_b[0];
	while (arr_b[i] != nulnum && i < arg - 1)
	{
		arr_b[i] = arr_b[i + 1];
		i++;
	}
	arr_b[i] = nulnum;
	ft_putstr_fd("pa\n", 1);
}

void	ft_push_b(int *arr_a, int *arr_b, int arg, int nulnum)
{
	int	i;

	i = 0;
	if (*arr_a == nulnum)
		return ;
	while (i < arg - 1)
		i++;
	while (i > 0)
	{
		arr_b[i] = arr_b[i - 1];
		i--;
	}
	arr_b[0] = arr_a[0];
	while (arr_a[i] != nulnum && i < arg - 1)
	{
		arr_a[i] = arr_a[i + 1];
		i++;
	}
	arr_a[i] = nulnum;
	ft_putstr_fd("pb\n", 1);
}
