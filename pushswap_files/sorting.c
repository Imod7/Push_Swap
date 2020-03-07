/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorting.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/26 13:10:01 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/02/26 14:18:04 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void				ft_sorting(t_prgm_props *prgm_sets, t_stack **stack_a, \
								t_stack **stack_b)
{
	t_stack_list	**alist;
	t_stack_list	**blist;
	int				temp;

	alist = &(*stack_a)->stack_lst;
	blist = &(*stack_b)->stack_lst;
	ft_push_b(alist, blist);
	prgm_sets->number_operations += 1;
	temp = (*alist)->num;
	ft_printf(ANSI_COLOR_CYAN"temp = %d\n"ANSI_COLOR_RESET, temp);
	ft_print_doublyll(*alist);
	ft_print_doublyll(*blist);
	while (ft_stack_length(*alist) > 0)
	{
		ft_printf(ANSI_COLOR_CYAN"\n\n-----------------LOOP START-------------------\n"ANSI_COLOR_RESET);
		while ((ft_stack_length(*alist) > 0) && (*alist)->num > (*blist)->num)
		{
			ft_printf(ANSI_COLOR_CYAN"alistnum = %d > blistnum = %d\n", (*alist)->num, (*blist)->num);
			ft_printf(ANSI_COLOR_CYAN"temp = %d\n", temp);
			ft_push_b(alist, blist);
			prgm_sets->number_operations += 1;
			if (ft_stack_length(*alist) > 0)
				temp = (*alist)->num;
			ft_print_doublyll(*alist);
			ft_print_doublyll(*blist);
		}
		while ((ft_stack_length(*blist) > 0) && (ft_stack_length(*alist) > 0) && ((*blist)->num > temp))
		{
			ft_printf("blistnum = %d > temp = %d\n"ANSI_COLOR_RESET, (*blist)->num, temp);
			ft_printf("temp = %d\n", temp);
			ft_rotate_a(alist, blist);
			ft_push_a(alist, blist);
			ft_reverserotate_a(alist, blist);
			ft_print_doublyll(*alist);
			ft_print_doublyll(*blist);
			prgm_sets->number_operations += 3;
		}
		if (ft_stack_length(*alist) > 0)
		{
			ft_printf(ANSI_COLOR_CYAN"temp = %d\n"ANSI_COLOR_RESET, temp);
			ft_push_b(alist, blist);
			temp = (*alist)->num;
			prgm_sets->number_operations += 1;
		}
		ft_printf(ANSI_COLOR_CYAN"---------------------------LOOP END-------------------------\n"ANSI_COLOR_RESET);
		ft_print_doublyll(*alist);
		ft_print_doublyll(*blist);
	}
	while (ft_stack_length(*blist) > 0)
	{
		ft_push_a(alist, blist);
		prgm_sets->number_operations += 1;	
	}
}
