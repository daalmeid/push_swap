/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 17:04:26 by daalmeid          #+#    #+#             */
/*   Updated: 2021/12/17 15:18:09 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdio.h>

int	ft_error_check(int ac, char **av)
{
	int	arg;
	int	i;

	arg = 1;
	while (arg < ac)
	{
		i = 0;
		while (av[arg][i] != '\0')
		{
			if (i == 0 && av[arg][i] == '-')
			{
				i++;
				continue ;
			}
			if (!ft_isdigit(av[arg][i]))
				return (0);
			i++;
		}
		arg++;
	}
	return (1);
}

int	ft_val_check(int ac, char **av, int *arr)
{
	int	j;
	int	i;

	j = 0;
	while (j < ac - 1)
	{
		i = j + 1;
		while (i < ac - 1)
		{
			if (arr[j] == arr[i++])
			{
				free (arr);
				return (0);
			}
		}
		j++;
	}
	i = 1;
	while (i < ac - 1)
	{
		if (ft_strncmp(av[i], "2147483647", 10) > 0 && ft_strlen(av[i]) == 10)
		{
			free (arr);
			return (0);
		}
		else if (ft_strncmp(av[i], "-2147483648", 11) > 0
			&& av[i][0] == '-' && ft_strlen(av[i]) == 11)
		{
			free (arr);
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_get_nullnum(int *arr, int ac)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < ac - 1)
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

void	ft_prep_arr_b(int *arr_b, int ac, int nulnum)
{
	int	i;

	i = 0;
	while (i < ac - 1)
	{
		arr_b[i] = nulnum;
		i++;
	}
}

int	main(int ac, char **av)
{
	int	*arr_a;
	int	*arr_b;
	int	arg;
	int	i;
	int	j;

	arr_a = malloc(sizeof(int) * (ac - 1));
	arr_b = malloc(sizeof(int) * (ac - 1));
	if (!arr_a || !arr_b)
		return(0);
	arg = 1;
	while (arg < ac)
	{
		i = ft_atoi(av[arg]);
		arr_a[arg - 1] = i;
		arg++;
	}
	i = ft_get_nullnum(arr_a, ac);
	ft_prep_arr_b(arr_b, ac, i);
	if (!ft_error_check(ac, av) || !ft_val_check(ac, av, arr_a))
	{
		ft_putstr_fd("Error\n", 1);
		free (arr_b);
		return (0);
	}
	arg = ac - 2;
	j = 0;
	while (!ft_check_order(arr_a, ac, i) || arr_b[0] != i)
	{
		while (arr_a[0] != i)
		{
			ft_organize(arr_a, arr_b, i, ac);
			ft_push_b(arr_a, arr_b, ac, i);
		}
		while (arr_b[0] != i)
		{
			ft_organize(arr_a, arr_b, i, ac);
			ft_push_a(arr_a, arr_b, ac, i);
		}
	}
	i = 0;
	while (i < ac - 1)
	{
		printf("%d ", arr_a[i]);
		i++;
	}
	printf("\n");
	i = 0;
	while (i < ac - 1)
	{
		printf("%d ", arr_b[i]);
		i++;
	}
	printf("\n");
	free (arr_a);
	free (arr_b);
}