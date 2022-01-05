/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checks_and_nulnum.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:15:18 by daalmeid          #+#    #+#             */
/*   Updated: 2022/01/05 17:17:45 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdio.h>

int	ft_check_order(int	*arr, int arg, int nulnum)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (size < arg && arr[size] != nulnum)
		size++;
	while (arr[i] != nulnum && i < size)
	{
		if (i + 1 < size && arr[i] > arr[i + 1] && arr[i + 1] != nulnum)
			return (0);
		i++;
	}
	return (1);
}

int	ft_dup_check(int size, int *arr_a)
{
	int	j;
	int	i;

	j = 0;
	while (j < size)
	{
		i = j + 1;
		while (i < size)
		{
			if (arr_a[j] == arr_a[i++])
				return (0);
		}
		j++;
	}
	return (1);
}

int	ft_error_check(char **split_arg)
{
	int	arg;
	int	i;

	arg = 0;
	while (split_arg[arg] != NULL)
	{
		i = 0;
		while (split_arg[arg][i] != '\0')
		{
			if (i == 0 && (split_arg[arg][i] == '-'
				|| split_arg[arg][i] == '+'))
				i++;
			if (!ft_isdigit(split_arg[arg][i]))
				return (0);
			i++;
		}
		arg++;
	}
	return (1);
}

int	ft_val_check(char **split_arg)
{
	int	i;

	i = 0;
	while (split_arg[i] != NULL)
	{
		if (ft_strncmp(split_arg[i], "2147483647", 10) > 0
			&& ft_strlen(split_arg[i]) >= 10)
			return (0);
		else if (ft_strncmp(split_arg[i], "-2147483648", 11) > 0
			&& split_arg[i][0] == '-' && ft_strlen(split_arg[i]) >= 11)
			return (0);
		i++;
	}
	return (1);
}

int	ft_get_nullnum(int *arr, int arg)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < arg)
	{
		if (arr[i] == j)
		{
			j--;
			i = -1;
		}
		i++;
	}
	return (j);
}
