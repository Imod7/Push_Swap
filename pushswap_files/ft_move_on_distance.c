/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_move_on_distance.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dominique <dominique@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/26 12:20:18 by dominique     #+#    #+#                 */
/*   Updated: 2020/05/29 15:18:29 by dominique     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int			ft_find_dis(t_prgm *prgm, t_stack_list *temp)
{
	int				dis3;

	dis3 = 0;
	if (prgm->top->next != NULL)
	{
		dis3 = prgm->top->next->num - temp->num;
		dis3 = (dis3 < 0) ? (dis3) * (-1) : dis3;
	}
	return (dis3);
}

static int			ft_check_distance(t_prgm *prgm, t_stack_list *temp)
{
	int				dis1;
	int				dis2;
	int				dis3;

	if (temp != NULL)
	{
		dis1 = prgm->top->num - temp->num;
		dis2 = prgm->bottom->num - temp->num;
		dis1 = (dis1 < 0) ? (dis1) * (-1) : dis1;
		dis2 = (dis2 < 0) ? (dis2) * (-1) : dis2;
	}
	if ((temp != NULL) && (dis1 < dis2))
	{
		dis3 = ft_find_dis(prgm, temp);
		if ((prgm->top->next != NULL) && (dis3 < dis1) && \
		(prgm->top->bucket == prgm->top->next->bucket))
			prgm->top = prgm->top->next;
		while (prgm->top->dis_from_top != 0)
			ft_rotate_a(prgm);
		return (1);
	}
	return (0);
}

static void			ft_check_distance_bottom(t_prgm *prgm, t_stack_list *temp, \
											int dis2)
{
	int				dis4;

	if ((temp != NULL) && (prgm->bottom->prev != NULL))
	{
		dis4 = prgm->bottom->prev->num - temp->num;
		dis4 = (dis4 < 0) ? (dis4) * (-1) : dis4;
		if ((prgm->bottom->prev != NULL) && (dis4 < dis2) && \
		(prgm->bottom->bucket == prgm->bottom->prev->bucket))
			prgm->bottom = prgm->bottom->prev;
		while (prgm->bottom->dis_from_top != 0)
			ft_reverserotate_a(prgm);
	}
	else if ((prgm->bottom->prev != NULL) && \
	(prgm->bottom->num > prgm->bottom->prev->num) && \
	(prgm->bottom->bucket == prgm->bottom->prev->bucket))
		prgm->bottom = prgm->bottom->prev;
	while (prgm->bottom->dis_from_top != 0)
		ft_reverserotate_a(prgm);
}

static void			ft_different_buckets(t_prgm *prgm, int bucket)
{
	if ((prgm->top->bucket == bucket) && (prgm->bottom->bucket != bucket))
	{
		if ((prgm->top->next != NULL) && \
		(prgm->top->num > prgm->top->next->num) && \
		(prgm->top->bucket == prgm->top->next->bucket))
			prgm->top = prgm->top->next;
		while (prgm->top->dis_from_top != 0)
			ft_rotate_a(prgm);
	}
	else if ((prgm->top->bucket != bucket) && (prgm->bottom->bucket == bucket))
	{
		if ((prgm->bottom->prev != NULL) && \
		(prgm->bottom->num > prgm->bottom->prev->num) && \
		(prgm->bottom->bucket == prgm->bottom->prev->bucket))
			prgm->bottom = prgm->bottom->prev;
		while (prgm->bottom->dis_from_top != 0)
			ft_reverserotate_a(prgm);
	}
}

void				ft_check_num_to_move(t_prgm *prgm, int bucket)
{
	t_stack_list	*temp;

	temp = prgm->stacks->stackb_lst;
	if ((prgm->top->bucket == bucket) && (prgm->bottom->bucket == bucket))
	{
		if (temp != NULL)
			prgm->distance = prgm->bottom->num - temp->num;
		if (ft_check_distance(prgm, temp) == 1)
			;
		else if (prgm->top->num < prgm->bottom->num)
		{
			if ((prgm->top->next != NULL) && \
			(prgm->top->num > prgm->top->next->num) && \
			(prgm->top->bucket == prgm->top->next->bucket))
				prgm->top = prgm->top->next;
			while (prgm->top->dis_from_top != 0)
				ft_rotate_a(prgm);
		}
		else
			ft_check_distance_bottom(prgm, temp, prgm->distance);
	}
	else
		ft_different_buckets(prgm, bucket);
	if (ft_stack_len(prgm->stacks->stackb_lst) > 1)
		ft_move_num_to_top_of_stack(prgm, 1);
}
