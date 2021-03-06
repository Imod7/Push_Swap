/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_metrics.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/30 15:14:32 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/05/30 17:38:41 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Calculating how many buckets I will have
** based on the amount of numbers (len) of my list
** and also the bucket size
*/

void				ft_calculate_buckets(t_prgm *prgm)
{
	int				temp;

	temp = prgm->stacka_len;
	prgm->buckets = 2;
	while (temp > 25)
	{
		prgm->buckets += 2;
		temp = temp / 2;
	}
	if (prgm->stacka_len == 500)
		prgm->buckets = 14;
	if (temp % 2 != 0)
		prgm->bucket_size = (prgm->stacka_len / prgm->buckets) + 1;
	else
		prgm->bucket_size = prgm->stacka_len / prgm->buckets;
}

/*
** Updating the bucket information in my sorted list
*/

void				ft_update_buckets(t_prgm *prgm)
{
	t_stack_list	*sorted;
	int				i;
	int				j;

	sorted = prgm->sorted_stack;
	i = 0;
	j = -1;
	while (sorted != NULL)
	{
		if ((i % prgm->bucket_size) == 0)
			j += 1;
		sorted->bucket = j;
		sorted = sorted->next;
		i += 1;
	}
}

void				ft_calculate_distance(t_prgm *prgm, size_t *i, size_t *j, \
										t_stack_list **temp)
{
	if (prgm->stack_len == 1)
	{
		(*temp)->dis_from_top = 0;
		(*temp)->pos_index = 0;
	}
	else
	{
		if (*i < prgm->stack_middle)
		{
			(*temp)->dis_from_top = *i;
			(*temp)->pos_index = *i;
			*i += 1;
			*j = *i;
		}
		else
		{
			(*temp)->pos_index = *i;
			if ((prgm->stack_len % 2 == 1) && (*i == prgm->stack_middle + 1))
				*j = prgm->stack_middle;
			else if (*i != prgm->stack_middle)
				*j -= 1;
			(*temp)->dis_from_top = *j;
			*i += 1;
		}
	}
}

static void			ft_metrics_stackb(t_prgm *prgm, size_t j)
{
	t_stack_list	*temp;
	size_t			i;

	i = 0;
	temp = prgm->stacks->stackb_lst;
	prgm->stack_len = prgm->stackb_len;
	prgm->stack_middle = prgm->stackb_len / 2;
	while (temp != NULL)
	{
		ft_calculate_distance(prgm, &i, &j, &temp);
		temp = temp->next;
	}
}

/*
** In function ft_metrics_calculation I update the metric
** dis_from_top (distance from top) for Stack A and Stack B
** by comparing with the numbers in the sorted_list
** it only calculates if length of Stack A > 3
*/

void				ft_metrics_calculation(t_prgm *prgm, int init)
{
	t_stack_list	*temp;
	size_t			i;
	size_t			j;

	i = 0;
	temp = prgm->stacks->stacka_lst;
	prgm->stacka_len = ft_stack_len(prgm->stacks->stacka_lst);
	prgm->stackb_len = prgm->total_numbers - prgm->stacka_len;
	prgm->stack_len = prgm->stacka_len;
	prgm->stack_middle = prgm->stacka_len / 2;
	while (temp != NULL)
	{
		while (prgm->sorted_stack->num != temp->num)
			prgm->sorted_stack = prgm->sorted_stack->next;
		ft_calculate_distance(prgm, &i, &j, &temp);
		if (init == 1)
			temp->bucket = prgm->sorted_stack->bucket;
		while (prgm->sorted_stack->prev != NULL)
			prgm->sorted_stack = prgm->sorted_stack->prev;
		temp = temp->next;
	}
	ft_metrics_stackb(prgm, j);
}
