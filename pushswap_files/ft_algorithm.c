/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_algorithm.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/11 12:22:18 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/04/12 23:14:39 by dominique     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void				ft_common_checks(t_stack_list *stack, t_stack_list **top, \
									t_stack_list **bottom, int *middle, int *i)
{
	if (stack != NULL)
	{
		(*top) = stack;
		(*bottom) = stack;
		while ((*bottom)->next != NULL)
			(*bottom) = (*bottom)->next;
		*middle = ft_stack_len((*top)) / 2;
		*i = 0;
	}
	else
		*i += 1;
}

void				ft_find_max(t_stack_list **top, t_stack_list **bottom, \
								t_stack_list **max)
{
	int				index;

	index = 0;
	if ((*top)->num >= (*max)->num)
		(*max) = (*top);
	if ((*bottom)->num > (*max)->num)
		(*max) = (*bottom);
	(*top) = (*top)->next;
	(*bottom) = (*bottom)->prev;
}

/*
** Find the max number in Stack B per bucket
** and move this number to Stack A
*/

void				ft_b_to_a(t_stacks **stacks, t_prgm *prgm, int cur_bucket)
{
	t_stack_list	*top;
	t_stack_list	*bottom;
	t_stack_list	*max;
	int				mid;
	int				i;

	ft_common_checks((*stacks)->stackb_lst, &top, &bottom, &mid, &i);
	while ((*stacks)->stackb_lst != NULL)
	{
		if (ft_stack_len((*stacks)->stackb_lst) % prgm->bucket_size == 0)
			cur_bucket -= 1;
		max = (*stacks)->stackb_lst;
		while (((top->bucket == cur_bucket) || \
		(bottom->bucket == cur_bucket)) && \
		(top->dis_from_top != bottom->dis_from_top) && (ft_stack_len(top) != 1))
			ft_find_max(&top, &bottom, &max);
		if (top->num >= max->num)
			max = top;
		while ((max->pos_index <= mid) && (max->pos_index != 0))
			ft_rotate_b(prgm, stacks);
		while ((max->pos_index > mid) && (max->pos_index != 0))
			ft_reverserotate_b(prgm, stacks);
		ft_push_a(prgm, stacks);
		ft_common_checks((*stacks)->stackb_lst, &top, &bottom, &mid, &i);
	}
}

void				ft_check_num_to_move(t_prgm *prgm, t_stacks **stacks, \
									t_stack_list **top, t_stack_list **bottom, \
									int cur_bucket)
{
	if (((*top)->bucket == cur_bucket) && ((*bottom)->bucket == cur_bucket))
	{
		while (((*top)->dis_from_top <= (*bottom)->dis_from_top) && \
		((*top)->dis_from_top != 0))
			ft_rotate_a(prgm, stacks);
		while (((*top)->dis_from_top > (*bottom)->dis_from_top) && \
		((*bottom)->dis_from_top != 0))
			ft_reverserotate_a(prgm, stacks);
	}
	else if (((*top)->bucket == cur_bucket) && \
	((*bottom)->bucket != cur_bucket))
	{
		while ((*top)->dis_from_top != 0)
			ft_rotate_a(prgm, stacks);
	}
	else if (((*top)->bucket != cur_bucket) && \
	((*bottom)->bucket == cur_bucket))
	{
		while ((*bottom)->dis_from_top != 0)
			ft_reverserotate_a(prgm, stacks);
	}
	if (ft_stack_len((*stacks)->stackb_lst) > 1)
		ft_find_min_or_max(stacks, prgm, 1);
	ft_push_b(prgm, stacks);
	(*stacks)->stackb_lst->bucket = cur_bucket;
}

/*
** Iterating Stack A from top to bottom and bottom to top 
** at the same time to find the number that is in the current bucket
** Once we find the number then we decide to move on top of Stack A
** based on the distance 
*/

void				ft_algorithm(t_prgm *prgm, t_stacks **stacks)
{
	t_stack_list	*top;
	t_stack_list	*bottom;
	int				cur_bucket;
	int				middle;
	int				i;

	ft_common_checks((*stacks)->stacka_lst, &top, &bottom, &middle, &i);
	cur_bucket = 0;
	while (((*stacks)->stacka_lst != NULL) && (i <= middle))
	{
		if ((top->bucket != cur_bucket) && (bottom->bucket != cur_bucket))
		{
			top = top->next;
			bottom = bottom->prev;
			i += 1;
		}
		else
		{
			// ft_printf("Stack A");
			// ft_print_doubly_all((*stacks)->stacka_lst);
			// ft_printf("Stack B");
			// ft_print_doubly_all((*stacks)->stackb_lst);
			ft_check_num_to_move(prgm, stacks, &top, &bottom, cur_bucket);
			ft_common_checks((*stacks)->stacka_lst, &top, &bottom, &middle, &i);
			if (ft_stack_len((*stacks)->stackb_lst) % prgm->bucket_size == 0)
				cur_bucket += 1;
		}
	}
	ft_b_to_a(stacks, prgm, cur_bucket);
	// ft_printf("Stack C (copy) Sorted");
	// ft_print_doubly_all(prgm->sorted_stack);
}
