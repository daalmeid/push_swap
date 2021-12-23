/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 17:04:26 by daalmeid          #+#    #+#             */
/*   Updated: 2021/12/21 13:48:27 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdio.h>

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
			if (i == 0 && (split_arg[arg][i] == '-' || split_arg[arg][i] == '+'))
			{
				i++;
				continue ;
			}
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
		if (ft_strncmp(split_arg[i], "2147483647", 10) > 0 && ft_strlen(split_arg[i]) == 10)
			return (0);
		else if (ft_strncmp(split_arg[i], "-2147483648", 11) > 0
			&& split_arg[i][0] == '-' && ft_strlen(split_arg[i]) == 11)
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

void	ft_prep_arr_b(int *arr_b, int arg, int nulnum)
{
	int	i;

	i = 0;
	while (i < arg)
	{
		arr_b[i] = nulnum;
		i++;
	}
}

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
	while (!ft_check_order(arr_a, j, i) || arr_b[0] != i)
	{
		while (arr_a[0] != i)
		{
			if (arr_a[1] != i)
				ft_organize(arr_a, arr_b, i, j);
			if (ft_check_order(arr_a, j, i) && arr_b[0] == i)
				break;
			ft_push_b(arr_a, arr_b, j, i);
		}
		while (arr_b[0] != i)
		{
			if (arr_b[1] != i)
				ft_organize(arr_a, arr_b, i, j);
			ft_push_a(arr_a, arr_b, j, i);
		}
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
}*/