/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sort_small.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/12 13:46:56 by dsaripap       #+#    #+#                */
/*   Updated: 2020/03/29 21:22:51 by dominique     ########   odam.nl         */
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
	else
		ft_sort_three(prgm, stacks);
	return (0);
}