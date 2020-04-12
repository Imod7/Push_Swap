/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sort_small.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/12 13:46:56 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/04/12 20:16:01 by dominique     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

/*
** When Stack_A has only 3 numbers then  
** there are only 6 possible permutations 
*/

void				ft_sort_three(t_prgm *prgm, t_stacks **stacks)
{
	t_stack_list	*temp;

	temp = (*stacks)->stacka_lst;
	if ((temp->num > temp->next->num) && \
	(temp->next->num > temp->next->next->num))
	{
		ft_rotate_a(prgm, stacks);
		ft_swap_a(prgm, stacks);
	}
	else if ((temp->num < temp->next->num) && \
	(temp->next->num > temp->next->next->num) && \
	(temp->next->next->num < temp->num))
	{
		ft_reverserotate_a(prgm, stacks);
	}
	else if ((temp->num < temp->next->num) && \
	(temp->next->num > temp->next->next->num) && \
	(temp->next->next->num > temp->num))
	{
		ft_swap_a(prgm, stacks);
		ft_rotate_a(prgm, stacks);
	}
	else if ((temp->num > temp->next->num) && \
	(temp->next->num < temp->next->next->num) && \
	(temp->next->next->num > temp->num))
		ft_swap_a(prgm, stacks);
	else if ((temp->num > temp->next->num) && \
	(temp->next->num < temp->next->next->num) && \
	(temp->next->next->num < temp->num))
	{
		ft_rotate_a(prgm, stacks);
	}
}

void				ft_sort_lt_ten(t_prgm *prgm, t_stacks **stacks)
{
	while (ft_stack_len((*stacks)->stacka_lst) > 3)
	{
		ft_find_min_or_max(stacks, prgm, 0);
		ft_push_b(prgm, stacks);
	}
	ft_sort_three(prgm, stacks);
	while (ft_stack_len((*stacks)->stackb_lst) > 0)
		ft_push_a(prgm, stacks);
}

int					ft_sort_small(t_prgm *prgm, t_stacks **stacks, int len)
{
	t_stack_list	*temp;

	temp = (*stacks)->stacka_lst;
	if (len == 1)
	{
		return (0);
	}
	else if (len == 2)
	{
		if (temp->num > temp->next->num)
			ft_swap_a(prgm, stacks);
		return (0);
	}
	else if (len == 3)
		ft_sort_three(prgm, stacks);
	else if ((len > 3) && (len <= 10))
		ft_sort_lt_ten(prgm, stacks);
	return (0);
}
