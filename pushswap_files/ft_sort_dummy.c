/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sort_dummy.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/10 11:24:29 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/04/11 16:24:40 by dominique     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void				ft_dummy_sort(t_prgm *prgm_sets, t_stacks **stacks)
{
	t_stack_list	**alist;
	t_stack_list	**blist;
	int				temp;

	alist = &(*stacks)->stacka_lst;
	blist = &(*stacks)->stackb_lst;
	ft_push_b(prgm_sets, stacks);
	temp = (*alist)->num;
	while (ft_stack_len(*alist) > 0)
	{
		while ((ft_stack_len(*alist) > 0) && (*alist)->num > (*blist)->num)
		{
			ft_push_b(prgm_sets, stacks);
			if (ft_stack_len(*alist) > 0)
				temp = (*alist)->num;
			// ft_print_doublyll((*stacks)->stacka_lst);
			// ft_print_doublyll((*stacks)->stackb_lst);
		}
		while ((ft_stack_len(*blist) > 0) && (ft_stack_len(*alist) > 0) && \
		((*blist)->num > temp))
		{
			ft_rotate_a(prgm_sets, stacks);
			ft_push_a(prgm_sets, stacks);
			ft_reverserotate_a(prgm_sets, stacks);
		}
		if (ft_stack_len(*alist) > 0)
		{
			ft_push_b(prgm_sets, stacks);
			temp = (*alist)->num;
		}
		// ft_print_doublyll(*alist);
		// ft_print_doublyll(*blist);
	}
	while (ft_stack_len(*blist) > 0)
		ft_push_a(prgm_sets, stacks);
}
