/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sort_small.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/12 13:46:56 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/03/12 14:14:41 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

/*
** When Stack_A has only 3 numbers then  
** there are only 6 possible permutations 
*/

void				ft_sort_three(t_stacks **stacks)
{
	t_stack_list	*temp;

	temp = (*stacks)->stacka_lst;
	if ((temp->num > temp->next->num) && \
	(temp->next->num > temp->next->next->num))
	{
		ft_rotate_a(stacks);
		ft_swap_a(stacks);
	}
	else if ((temp->num < temp->next->num) && \
	(temp->next->num > temp->next->next->num) && \
	(temp->next->next->num < temp->num))
		ft_reverserotate_a(stacks);
	else if ((temp->num < temp->next->num) && \
	(temp->next->num > temp->next->next->num) && \
	(temp->next->next->num > temp->num))
	{
		ft_swap_a(stacks);
		ft_rotate_a(stacks);
	}
	else if ((temp->num > temp->next->num) && \
	(temp->next->num < temp->next->next->num) && \
	(temp->next->next->num > temp->num))
		ft_swap_a(stacks);
	else if ((temp->num > temp->next->num) && \
	(temp->next->num < temp->next->next->num) && \
	(temp->next->next->num < temp->num))
		ft_rotate_a(stacks);
}
