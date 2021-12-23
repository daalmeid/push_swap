/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 17:04:32 by daalmeid          #+#    #+#             */
/*   Updated: 2021/12/21 14:11:49 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

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

void	ft_rot_a(int *arr_a, int arg, int nulnum)
{
	int	tmp;
	int	i;
	
	tmp = arr_a[0];
	i = 0;
	while (arr_a[i] != nulnum && i < arg - 1)
	{
		arr_a[i] = arr_a[i + 1];
		i++;
	}
	arr_a[--i] = tmp;
	ft_putstr_fd("ra\n", 1);
}

void	ft_rot_b(int *arr_b, int arg, int nulnum)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = arr_b[i];
	while (arr_b[i] != nulnum && i < arg - 1)
	{
		arr_b[i] = arr_b[i + 1];
		i++;
	}
	arr_b[--i] = tmp;
	ft_putstr_fd("rb\n", 1);
}

void	ft_rot_ab(int *arr_a, int *arr_b, int arg, int nulnum)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = arr_a[i];
	while (arr_a[i] != nulnum && i < arg - 1)
	{
		arr_a[i] = arr_a[i + 1];
		i++;
	}
	arr_a[--i] = tmp;
	i = 0;
	tmp = arr_b[i];
	while (arr_b[i] != nulnum && i < arg - 1)
	{
		arr_b[i] = arr_b[i + 1];
		i++;
	}
	arr_b[--i] = tmp;
	ft_putstr_fd("rr\n", 1);
}

void	ft_revrot_a(int *arr_a, int arg, int nulnum)
{
	int	tmp;
	int	i;

	i = arg - 1;
	while(i > 0 && arr_a[i] == nulnum)
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
	while(i > 0 && arr_b[i] == nulnum)
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
	while(i > 0 && arr_a[i] == nulnum)
		i--;
	tmp = arr_a[i];
	while (i > 0)
	{
		arr_a[i] = arr_a[i - 1];
		i--;
	}
	arr_a[i] = tmp;
	i = arg - 1;
	while(i > 0 && arr_b[i] == nulnum)
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

int	ft_check_order(int	*arr, int arg, int nulnum)
{
	int	i;
	int size;

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

void	ft_organize(int *arr_a, int *arr_b, int nulnum, int arg)
{
	int	lst_a;
	int	lst_b;

	lst_a = arg - 1;
	lst_b = 0;
	while (lst_b <= lst_a && arr_b[lst_b] != nulnum)
		lst_b++;
	lst_b--;
	while (arr_a[lst_a] == nulnum && lst_a > 0)
		lst_a--;
	while (!(arr_b[lst_b] <= arr_b[1] && arr_b[1] < arr_b[0])
			|| !(arr_a[0] < arr_a[1] && arr_a[1] <= arr_a[lst_a]))
	{
		if (arr_a[0] > arr_a[1] && arr_b[0] < arr_b[1])
			ft_swap_ab(arr_a, arr_b, nulnum);
		else if(arr_a[0] > arr_a[1])
			ft_swap_a(arr_a, nulnum);
		else if (arr_b[0] < arr_b[1])
			ft_swap_b(arr_b, nulnum);
		if (arr_a[0] > arr_a[lst_a] && arr_b[0] < arr_b[lst_b])
			ft_revrot_ab(arr_a, arr_b, arg, nulnum);
		else if (arr_a[0] > arr_a[lst_a])
			ft_revrot_a(arr_a, arg, nulnum);
		else if (arr_b[0] < arr_b[lst_b])
			ft_revrot_b(arr_b, arg, nulnum);
		if (arr_a[0] < arr_a[lst_a] && arr_a[1] > arr_a[lst_a] && arr_b[0] > arr_b[lst_b] && arr_b[1] < arr_b[lst_b])
		{
			ft_revrot_ab(arr_a, arr_b, arg, nulnum);
			ft_swap_ab(arr_a, arr_b, nulnum);
		}
		else if (arr_a[0] < arr_a[lst_a] && arr_a[1] > arr_a[lst_a])
		{
			ft_revrot_a(arr_a, arg, nulnum);
			ft_swap_a(arr_a, nulnum);
		}
		else if (arr_b[0] > arr_b[lst_b] && arr_b[1] < arr_b[lst_b])
		{
			ft_revrot_b(arr_b, arg, nulnum);
			ft_swap_b(arr_b, nulnum);
		}
		if ((lst_a <= 1 && arr_b[lst_b] <= arr_b[1] && arr_b[1] < arr_b[0])
			|| (lst_b <= 1 && arr_a[0] < arr_a[1] && arr_a[1] <= arr_a[lst_a]))
			break ;
	}
}

/*int	main(void)
{
	int	arr_a[5] = {1,2,3,-24,42};
	int	arr_b[5] = {5,6,7,42,-1};
	int	i;

	i = 0;
	ft_organize(arr_a, arr_b, -1, 6);
	while (i < 5)
	{
		printf("%d ", arr_a[i]);
		i++;
	}
	printf("\n");
	i = 0;
	while (i < 5)
	{
		printf("%d ", arr_b[i]);
		i++;
	}
	printf("\n");
}*/
