/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:29:54 by daalmeid          #+#    #+#             */
/*   Updated: 2021/12/20 20:24:50 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdio.h>

int	word_count(const char *s, char c)
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

int	num_in_arr_a(int *arr_a, char *arg)
{
	static int pos = 0;
	int	i;
	int val_atoi;
	char **split_arg;
	
	split_arg = ft_split(arg, ' ');
	if (!split_arg)
		return (0);
	if (!ft_error_check(split_arg) || !ft_val_check(split_arg))
	{
		free (split_arg);
		return (0);
	}
	i = 0;
	while (split_arg[i] != NULL)
	{
		val_atoi = ft_atoi(split_arg[i]);
		arr_a[pos++] = val_atoi;
		i++;
	}
	i = 0;
	while (split_arg[i] != NULL)
	{
		free (split_arg[i]);
		i++;
	}
	free (split_arg);
	return (1);
}

int	prep_arr_a(int **arr_a, int **arr_b, int ac, char **av)
{
	int	i;
	int	j;
	int	size;

	i = 1;
	j = 0;
	size = 0;
	while (i < ac)
		size += word_count(av[i++], ' ');
	i = 1;
	*arr_a = malloc(sizeof(int) * size);
	*arr_b = malloc(sizeof(int) * size);
	if (!*arr_a || !*arr_b)
		return (0);
	while (i < ac)
	{	
		j = num_in_arr_a(*arr_a, av[i++]);
		if (j == 0)
			return (0);
	}
	if (!ft_dup_check(size, *arr_a))
		return (0);
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