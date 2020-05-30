/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_algorithm.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/11 12:22:18 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/05/30 16:20:02 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** top and bottom pointers point to whichever stack I pass
** in this function
** and I pass either Stack A or Stack B depending on which
** Stack I am iterating everytime
*/

void				ft_common_checks(t_stack_list *stack, t_prgm *prgm, \
									size_t *i)
{
	if (stack != NULL)
	{
		prgm->top = stack;
		prgm->bottom = stack;
		while (prgm->bottom->next != NULL)
			prgm->bottom = prgm->bottom->next;
		prgm->stack_middle = ft_stack_len(prgm->top) / 2;
		*i = 0;
	}
	else
		*i += 1;
}

void				ft_find_max(t_prgm *prgm, t_stack_list **max)
{
	if (prgm->top->num >= (*max)->num)
		(*max) = prgm->top;
	if (prgm->bottom->num > (*max)->num)
		(*max) = prgm->bottom;
	prgm->top = prgm->top->next;
	prgm->bottom = prgm->bottom->prev;
}

/*
** Find the max number in Stack B per bucket
** and move this number to Stack A
*/

void				ft_b_to_a(t_prgm *prgm, int cur_bucket)
{
	t_stack_list	*max;
	size_t			i;

	i = 0;
	ft_common_checks(prgm->stacks->stackb_lst, prgm, &i);
	while (prgm->stacks->stackb_lst != NULL)
	{
		if (ft_stack_len(prgm->stacks->stackb_lst) % prgm->bucket_size == 0)
			cur_bucket -= 1;
		max = prgm->stacks->stackb_lst;
		while (((prgm->top->bucket == cur_bucket) || \
		(prgm->bottom->bucket == cur_bucket)) && \
		(prgm->top->dis_from_top != prgm->bottom->dis_from_top) && \
		(ft_stack_len(prgm->top) != 1))
			ft_find_max(prgm, &max);
		if (prgm->top->num >= max->num)
			max = prgm->top;
		while ((max->pos_index <= prgm->stack_middle) && (max->pos_index != 0))
			ft_rotate_b(prgm);
		while ((max->pos_index > prgm->stack_middle) && (max->pos_index != 0))
			ft_reverserotate_b(prgm);
		ft_push_a(prgm);
		ft_common_checks(prgm->stacks->stackb_lst, prgm, &i);
	}
}

int					ft_move_and_push(t_prgm *prgm, int cur_bucket)
{
	ft_check_num_to_move(prgm, cur_bucket);
	if (ft_check_ifsorted(prgm) == SUCCESS)
		return (SUCCESS);
	ft_push_b(prgm);
	prgm->stacks->stackb_lst->bucket = cur_bucket;
	return (CONTINUE);
}

/*
** Iterating Stack A from top to bottom and bottom to top
** at the same time to find the number that is in the current bucket
** Once we find the number then we decide to move on top of Stack A
** based on the distance
*/

int					ft_algorithm(t_prgm *prgm)
{
	int				cur_bucket;
	size_t			i;

	cur_bucket = 0;
	ft_common_checks(prgm->stacks->stacka_lst, prgm, &i);
	while ((prgm->stacks->stacka_lst != NULL) && (i <= prgm->stack_middle))
	{
		if ((prgm->top->bucket != cur_bucket) && \
		(prgm->bottom->bucket != cur_bucket))
		{
			prgm->top = prgm->top->next;
			prgm->bottom = prgm->bottom->prev;
			i += 1;
		}
		else
		{
			if (ft_move_and_push(prgm, cur_bucket) == SUCCESS)
				return (SUCCESS);
			ft_common_checks(prgm->stacks->stacka_lst, prgm, &i);
			if (ft_stack_len(prgm->stacks->stackb_lst) % prgm->bucket_size == 0)
				cur_bucket += 1;
		}
	}
	ft_b_to_a(prgm, cur_bucket);
	return (0);
}
