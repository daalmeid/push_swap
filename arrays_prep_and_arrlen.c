/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrays_prep_and_arrlen.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:29:54 by daalmeid          #+#    #+#             */
/*   Updated: 2022/01/07 14:53:48 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdio.h>

static int	word_count(const char *s, char c)
{
	int	i;
	int	nb_words;

	i = 0;
	nb_words = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		while (s[i] != c && s[i] != '\0')
			i++;
		nb_words++;
	}
	return (nb_words);
}

static int	num_in_arr_a(int *arr_a, char *arg)
{
	static int	pos = 0;
	int			i;
	char		**split_arg;

	split_arg = ft_split(arg, ' ');
	i = 0;
	if (!split_arg)
		return (0);
	if (!ft_error_check(split_arg) || !ft_val_check(split_arg))
	{
		while (split_arg[i] != NULL)
			free (split_arg[i++]);
		free (split_arg);
		return (-1);
	}
	while (split_arg[i] != NULL)
		arr_a[pos++] = ft_atoi(split_arg[i++]);
	i = 0;
	while (split_arg[i] != NULL)
		free (split_arg[i++]);
	free (split_arg);
	return (1);
}

int	ft_prep_arr_a(int **arr_a, int ac, char **av)
{
	int	i;
	int	size;

	i = 1;
	size = 0;
	while (i < ac)
		size += word_count(av[i++], ' ');
	*arr_a = malloc(sizeof(int) * size);
	if (!*arr_a)
		return (0);
	i = 1;
	while (i < ac)
	{	
		if (num_in_arr_a(*arr_a, av[i++]) <= 0)
		{	
			free (*arr_a);
			return (num_in_arr_a(*arr_a, av[--i]));
		}
	}
	if (!ft_dup_check(size, *arr_a))
	{	
		free (*arr_a);
		return (-1);
	}
	return (size);
}

int	ft_prep_arr_b(int **arr_b, int **arr_a, int arg, int nulnum)
{
	int	i;
	int	*ptr;

	*arr_b = malloc(sizeof(int) * ft_arrlen(*arr_a, nulnum, arg));
	if (!*arr_b)
	{	
		free(*arr_a);
		return (0);
	}
	i = 0;
	ptr = *arr_b;
	while (i < arg)
	{
		ptr[i] = nulnum;
		i++;
	}
	return (1);
}

int	ft_arrlen(int *arr, int nulnum, int arg)
{
	int	size;

	size = 0;
	while (size < arg && arr[size] != nulnum)
		size++;
	return (size);
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
	i = 0;
	while (i < 18)
	{
		printf("%d ", arr_a[i]);
		i++;
	}
	printf("\n");
	i = 0;
	while (i < 18)
	{
		printf("%d ", arr_b[i]);
		i++;
	}
	printf("\n");
	free (arr_a);
	free (arr_b);
}*/