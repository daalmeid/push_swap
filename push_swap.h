/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:20:31 by daalmeid          #+#    #+#             */
/*   Updated: 2021/12/21 14:12:09 by daalmeid         ###   ########.fr       */
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
int		ft_get_nullnum(int *arr, int arg);
void	ft_prep_arr_b(int *arr_b, int arg, int nulnum);
void	ft_organize(int *arr_a, int *arr_b, int nulnum, int arg);
int		prep_arr_a(int **arr_a, int **arr_b, int ac, char **av);
int		num_in_arr_a(int *arr_a, char *arg);
int		word_count(const char *s, char c);

#endif