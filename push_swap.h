/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:20:31 by daalmeid          #+#    #+#             */
/*   Updated: 2022/01/05 17:44:12 by daalmeid         ###   ########.fr       */
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
int		ft_prep_arr_b(int **arr_b, int *arr_a, int arg, int nulnum);
void	ft_organize(int *arr_a, int *arr_b, int nulnum, int arg);
int		prep_arr_a(int **arr_a, int ac, char **av);
int		num_in_arr_a(int *arr_a, char *arg);
int		word_count(const char *s, char c);
int		choose_organize_a(int *arr_a, int *arr_b, int arg, int nulnum);
int		order_bottom_or_top(int *arr_a, int med_half, int size);
int		find_median(int *arr_a, int size);
void	order_push_b_to_a(int *arr_a, int *arr_b, int arg, int nulnum);
int		ft_arrlen(int *arr, int nulnum, int arg);
void	organize_quarter_by_lstmed(int *arr_a, int med, int arg, int nulnum);
void	organize_low_nbrs(int *arr_a, int *arr_b, int arg, int nulnum);
int		find_quarter_median(int *arr_a, int size);
void	organize_low_nbrs(int *arr_a, int *arr_b, int arg, int nulnum);

#endif