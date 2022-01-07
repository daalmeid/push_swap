/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:20:31 by daalmeid          #+#    #+#             */
/*   Updated: 2022/01/07 17:17:05 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

void	ft_swap_a(int *arr, int nulnum);
void	ft_swap_b(int *arr, int nulnum);
void	ft_swap_ab(int *arr_a, int *arr_b, int nulnum);
void	ft_push_a(int *arr_a, int *arr_b, int arg, int nulnum);
void	ft_push_b(int *arr_a, int *arr_b, int arg, int nulnum);
void	ft_rot_a(int *arr_a, int arg, int nulnum);
void	ft_rot_b(int *arr_b, int arg, int nulnum);
void	ft_rot_ab(int *arr_a, int *arr_b, int arg, int nulnum);
void	ft_revrot_a(int *arr_a, int arg, int nulnum);
void	ft_revrot_b(int *arr_b, int arg, int nulnum);
void	ft_revrot_ab(int *arr_a, int *arr_b, int arg, int nulnum);
int		ft_check_order(int	*arr, int arg, int nulnum);
int		ft_error_check(char **split_arg);
int		ft_val_check(char **split_arg);
int		ft_dup_check(int size, int *arr_a);
int		ft_get_nullnum(int *arr, int arg);
int		ft_prep_arr_a(int **arr_a, int ac, char **av);
int		ft_prep_arr_b(int **arr_b, int **arr_a, int arg, int nulnum);
int		ft_find_median(int *arr_a, int size);
void	ft_order_push_b_to_a(int *arr_a, int *arr_b, int arg, int nulnum);
int		ft_arrlen(int *arr, int nulnum, int arg);
void	ft_organize_low_nbrs(int *arr_a, int *arr_b, int arg, int nulnum);
int		ft_find_quarter_median(int *arr_a, int size);

#endif