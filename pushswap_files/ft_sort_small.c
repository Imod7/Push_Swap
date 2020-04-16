/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sort_small.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/12 13:46:56 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/04/16 17:28:24 by dominique     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** When Stack_A has only 3 numbers then
** there are only 6 possible permutations
*/

void				ft_sort_three(t_prgm *prgm)
{
	t_stack_list	*a;
	t_stack_list	*b;
	t_stack_list	*c;

	a = prgm->stacks->stacka_lst;
	b = prgm->stacks->stacka_lst->next;
	c = prgm->stacks->stacka_lst->next->next;
	if ((a->num > b->num) && (b->num > c->num))
	{
		ft_rotate_a(prgm);
		ft_swap_a(prgm);
	}
	else if ((a->num < b->num) && (b->num > c->num) && (c->num < a->num))
		ft_reverserotate_a(prgm);
	else if ((a->num < b->num) && (b->num > c->num) && (c->num > a->num))
	{
		ft_swap_a(prgm);
		ft_rotate_a(prgm);
	}
	else if ((a->num > b->num) && (b->num < c->num) && (c->num > a->num))
		ft_swap_a(prgm);
	else if ((a->num > b->num) && (b->num < c->num) && (c->num < a->num))
		ft_rotate_a(prgm);
}

void				ft_sort_lt_ten(t_prgm *prgm)
{
	while (ft_stack_len(prgm->stacks->stacka_lst) > 3)
	{
		ft_move_num_to_top_of_stack(prgm, 0);
		ft_push_b(prgm);
	}
	ft_sort_three(prgm);
	while (ft_stack_len(prgm->stacks->stackb_lst) > 0)
		ft_push_a(prgm);
}

int					ft_sort_small(t_prgm *prgm)
{
	t_stack_list	*temp;

	temp = prgm->stacks->stacka_lst;
	if (prgm->stack_len == 1)
	{
		return (0);
	}
	else if (prgm->stack_len == 2)
	{
		if (temp->num > temp->next->num)
			ft_swap_a(prgm);
		return (0);
	}
	else if (prgm->stack_len == 3)
		ft_sort_three(prgm);
	else if ((prgm->stack_len > 3) && (prgm->stack_len <= 10))
		ft_sort_lt_ten(prgm);
	return (0);
}
