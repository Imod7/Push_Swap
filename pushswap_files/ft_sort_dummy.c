/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sort_dummy.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/10 11:24:29 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/04/16 17:55:03 by dominique     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void				ft_dummy_sort(t_prgm *prgm)
{
	t_stack_list	**alist;
	t_stack_list	**blist;
	int				temp;

	alist = &(prgm->stacks)->stacka_lst;
	blist = &(prgm->stacks)->stackb_lst;
	ft_push_b(prgm);
	temp = (*alist)->num;
	while (ft_stack_len(*alist) > 0)
	{
		while ((ft_stack_len(*alist) > 0) && (*alist)->num > (*blist)->num)
		{
			ft_push_b(prgm);
			if (ft_stack_len(*alist) > 0)
				temp = (*alist)->num;
		}
		while ((ft_stack_len(*blist) > 0) && (ft_stack_len(*alist) > 0) && \
		((*blist)->num > temp))
		{
			ft_rotate_a(prgm);
			ft_push_a(prgm);
			ft_reverserotate_a(prgm);
		}
		if (ft_stack_len(*alist) > 0)
		{
			ft_push_b(prgm);
			temp = (*alist)->num;
		}
	}
	while (ft_stack_len(*blist) > 0)
		ft_push_a(prgm);
}
