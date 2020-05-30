/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sort_big.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/11 12:22:18 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/05/30 11:02:24 by dominique     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Checks the distance of the 2nd number from top of Stack B
** from its adjacent ones and also compared to the number
** at the bottom of Stack B
*/

static int			ft_check_distance_in_b(t_prgm *prgm, t_stack_list **tmp, \
									t_stack_list *temp)
{
	int				dis1;
	int				dis2;
	int				dis3;

	if (prgm->stackb_len > 2)
	{
		dis1 = (*tmp)->next->num - (*tmp)->prev->num;
		dis2 = (*tmp)->prev->num - temp->num;
		dis3 = (*tmp)->next->num - (*tmp)->num;
		dis1 = (dis1 < 0) ? (dis1) * (-1) : dis1;
		dis2 = (dis2 < 0) ? (dis2) * (-1) : dis2;
		dis3 = (dis3 < 0) ? (dis3) * (-1) : dis3;
	}
	if ((prgm->stackb_len > 2) && ((*tmp)->dis_from_top == 1) && \
	(temp->bucket == (*tmp)->prev->bucket) && (dis1 < dis2) && (dis3 > dis1))
	{
		ft_swap_b(prgm);
		(*tmp) = (*tmp)->prev;
		return (1);
	}
	return (0);
}

/*
** If this function is called with flag 0 then
** we check Stack B, otherwise we check Stack A
** Here we choose the operation that will move
** the number either based on its distance from the adjacent ones
** either based on its value compared to its adjacent ones
*/

static void			ft_choose_move(t_prgm *prgm, t_stack_list **tmp, \
									size_t flag)
{
	t_stack_list	*temp;

	if (flag == 1)
	{
		temp = prgm->stacks->stackb_lst;
		while (temp->next != NULL)
			temp = temp->next;
		if (ft_check_distance_in_b(prgm, tmp, temp) == 1)
			;
		else if ((prgm->stackb_len > 2) && \
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

static void			ft_move_to_top_of_stack(t_prgm *prgm, int num, size_t flag)
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
