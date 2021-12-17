/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:20:31 by daalmeid          #+#    #+#             */
/*   Updated: 2021/12/17 14:06:22 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

void	ft_swap_a(int *arr, int nulnum);
void	ft_swap_b(int *arr, int nulnum);
void	ft_swap_ab(int *arr_a, int *arr_b, int nulnum);
void	ft_push_a(int *arr_a, int *arr_b, int ac, int nulnum);
void	ft_push_b(int *arr_a, int *arr_b, int ac, int nulnum);
void	ft_rot_a(int *arr_a, int ac, int nulnum);
void	ft_rot_b(int *arr_b, int ac, int nulnum);
void	ft_rot_ab(int *arr_a, int *arr_b, int ac, int nulnum);
void	ft_revrot_a(int *arr_a, int ac, int nulnum);
void	ft_revrot_b(int *arr_b, int ac, int nulnum);
void	ft_revrot_ab(int *arr_a, int *arr_b, int ac, int nulnum);
int		ft_check_order(int	*arr, int ac, int nulnum);
int		ft_error_check(int ac, char **av);
int		ft_val_check(int ac, char **av, int *arr);
int		ft_get_nullnum(int *arr, int ac);
void	ft_prep_arr_b(int *arr_b, int ac, int nulnum);
void	ft_organize(int *arr_a, int *arr_b, int nulnum, int ac);

#endif