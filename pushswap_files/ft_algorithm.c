/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_algorithm.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/11 12:22:18 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/03/11 12:35:12 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void				ft_goalpos_calculation(t_stacks **stacks, \
											t_stack_list *sorted_stacka)
{
	size_t			index_a;
	size_t			index_s;
	t_stack_list	*temp;

	index_a = 0;
	index_s = 0;
	temp = (*stacks)->stacka_lst;
	while (temp != NULL)
	{
		// ft_printf(ANSI_COLOR_RED"temp = %d , sorted = %d\n", temp->num, sorted_stacka->num);
		if (temp->num == sorted_stacka->num)
		{
			temp->goal_pos = index_s;
			temp->distance = index_s - index_a;
			temp = temp->next;
			index_a += 1;
			while (index_s != 0)
			{
				sorted_stacka = sorted_stacka->prev;
				index_s -= 1;
			}
		}
		else
		{
			sorted_stacka = sorted_stacka->next;
			index_s += 1;
		}
	}
}
