/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:08:19 by daalmeid          #+#    #+#             */
/*   Updated: 2022/01/05 17:37:18 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdio.h>

void	ft_rot_a(int *arr_a, int arg, int nulnum)
{
	int	tmp;
	int	i;

	tmp = arr_a[0];
	i = 0;
	while (arr_a[i] != nulnum && i < arg - 1 && arr_a[i + 1] != nulnum)
	{
		arr_a[i] = arr_a[i + 1];
		i++;
	}
	arr_a[i] = tmp;
	ft_putstr_fd("ra\n", 1);
}

void	ft_rot_b(int *arr_b, int arg, int nulnum)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = arr_b[i];
	while (arr_b[i] != nulnum && i < arg - 1 && arr_b[i + 1] != nulnum)
	{
		arr_b[i] = arr_b[i + 1];
		i++;
	}
	arr_b[i] = tmp;
	ft_putstr_fd("rb\n", 1);
}

void	ft_rot_ab(int *arr_a, int *arr_b, int arg, int nulnum)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = arr_a[i];
	while (arr_a[i] != nulnum && i < arg - 1 && arr_a[i + 1] != nulnum)
	{
		arr_a[i] = arr_a[i + 1];
		i++;
	}
	arr_a[i] = tmp;
	i = 0;
	tmp = arr_b[i];
	while (arr_b[i] != nulnum && i < arg - 1 && arr_b[i + 1] != nulnum)
	{
		arr_b[i] = arr_b[i + 1];
		i++;
	}
	arr_b[i] = tmp;
	ft_putstr_fd("rr\n", 1);
}
