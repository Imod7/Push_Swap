/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sorting.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/10 11:24:29 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/03/10 11:24:37 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void				ft_sorting(t_prgm *prgm_sets, t_stacks **stacks)
{
	t_stack_list	**alist;
	t_stack_list	**blist;
	int				temp;

	alist = &(*stacks)->stacka_lst;
	blist = &(*stacks)->stackb_lst;
	ft_push_b(prgm_sets, stacks);
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
			ft_push_b(prgm_sets, stacks);
			ft_printf(" --- dom 111\n");
			// prgm_sets->number_operations += 1;
			if (ft_stack_length(*alist) > 0)
				temp = (*alist)->num;
			ft_printf(" --- dom \n");
			ft_print_doublyll((*stacks)->stacka_lst);
			ft_print_doublyll((*stacks)->stackb_lst);
		}
		while ((ft_stack_length(*blist) > 0) && (ft_stack_length(*alist) > 0) && ((*blist)->num > temp))
		{
			ft_printf("blistnum = %d > temp = %d\n"ANSI_COLOR_RESET, (*blist)->num, temp);
			ft_printf("temp = %d\n", temp);
			ft_rotate_a(prgm_sets, stacks);
			ft_push_a(prgm_sets, stacks);
			ft_reverserotate_a(prgm_sets, stacks);
			ft_print_doublyll(*alist);
			ft_print_doublyll(*blist);
			// prgm_sets->number_operations += 3;
		}
		if (ft_stack_length(*alist) > 0)
		{
			ft_printf(ANSI_COLOR_CYAN"temp = %d\n"ANSI_COLOR_RESET, temp);
			ft_push_b(prgm_sets, stacks);
			temp = (*alist)->num;
			// prgm_sets->number_operations += 1;
		}
		ft_printf(ANSI_COLOR_CYAN"---------------------------LOOP END-------------------------\n"ANSI_COLOR_RESET);
		ft_print_doublyll(*alist);
		ft_print_doublyll(*blist);
	}
	while (ft_stack_length(*blist) > 0)
	{
		ft_push_a(prgm_sets, stacks);
		// prgm_sets->number_operations += 1;	
	}
}
