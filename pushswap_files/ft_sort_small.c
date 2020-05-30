/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sort_small.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/12 13:46:56 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/05/29 15:26:28 by dominique     ########   odam.nl         */
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

static int			ft_sort_lt_ten(t_prgm *prgm)
{
	int				counter;

	counter = 0;
	while (prgm->stacka_len > 3)
	{
		ft_move_num_to_top_of_stack(prgm, 0);
		if (ft_check_ifsorted(prgm) != -1)
			return (SUCCESS);
		ft_push_b(prgm);
		counter++;
	}
	ft_sort_three(prgm);
	while (counter > 0)
	{
		ft_push_a(prgm);
		counter--;
	}
	return (CONTINUE);
}

int					ft_sort_small(t_prgm *prgm)
{
	t_stack_list	*temp;

	temp = prgm->stacks->stacka_lst;
	if (prgm->stacka_len == 1)
	{
		return (0);
	}
	else if (prgm->stacka_len == 2)
	{
		if (temp->num > temp->next->num)
			ft_swap_a(prgm);
		return (0);
	}
	else if (prgm->stacka_len == 3)
		ft_sort_three(prgm);
	else if ((prgm->stacka_len > 3) && (prgm->stacka_len <= 10))
		ft_sort_lt_ten(prgm);
	return (0);
}
