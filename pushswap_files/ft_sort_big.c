/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sort_big.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/11 12:22:18 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/04/30 15:33:42 by dominique     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void				ft_choose_move(t_prgm *prgm, t_stack_list **tmp, \
									size_t flag)
{
	if (flag == 1)
	{
		if ((ft_stack_len(prgm->stacks->stackb_lst) > 2) && \
		((*tmp)->dis_from_top == 1) && \
		((*tmp)->num > (*tmp)->prev->num) && \
		((*tmp)->prev->num > (*tmp)->next->num))
		{
			ft_swap_b(prgm);
			(*tmp) = (*tmp)->prev;
		}
		else
			ft_rotate_b(prgm);
	}
	else
		ft_rotate_a(prgm);
}

void				ft_move_to_top_of_stack(t_prgm *prgm, int num, size_t flag)
{
	t_stack_list	*temp;

	if (flag == 1)
		temp = prgm->stacks->stackb_lst;
	else
		temp = prgm->stacks->stacka_lst;
	while ((temp->num != num) && (!(prgm->stack_len < 2)))
		temp = temp->next;
	if ((temp->pos_index <= (prgm->stack_len / 2)) && (!(prgm->stack_len < 2)))
	{
		while (temp->prev != NULL)
			ft_choose_move(prgm, &temp, flag);
	}
	else
	{
		while (temp->dis_from_top != 0)
		{
			if (flag == 1)
				ft_reverserotate_b(prgm);
			else
				ft_reverserotate_a(prgm);
		}
	}
}

void				ft_find_min_or_max(t_stack_list *temp, size_t flag, \
										int *min, int *max)
{
	size_t			i;

	i = 0;
	while (temp != NULL)
	{
		if ((temp->num < *min) && (flag == 0))
		{
			*min = temp->num;
			temp->dis_from_top = i;
		}
		if ((temp->num > *max) && (flag == 1))
		{
			*max = temp->num;
			temp->dis_from_top = i;
		}
		temp = temp->next;
		i += 1;
	}
}

/*
** Function where I need to find the min or the max num
** based on the flag that is passed as a parameter.
** If flag == 0 then I need to find the min in Stack A
** If flag == 1 then I need to find the max in Stack B
** When I find it, I call the function ft_move_to_top_of_stack
** to move the number (min or max) to the top of the corresponding
** Stack (A or B respectively)
*/

void				ft_move_num_to_top_of_stack(t_prgm *prgm, size_t flag)
{
	t_stack_list	*temp;
	int				min;
	int				max;

	min = 2147483647;
	max = -2147483648;
	if (flag == 0)
		temp = prgm->stacks->stacka_lst;
	else
		temp = prgm->stacks->stackb_lst;
	prgm->stack_len = ft_stack_len(temp);
	if (prgm->stack_len > 1)
	{
		ft_find_min_or_max(temp, flag, &min, &max);
		if (flag == 0)
			ft_move_to_top_of_stack(prgm, min, flag);
		else
			ft_move_to_top_of_stack(prgm, max, flag);
	}
}
