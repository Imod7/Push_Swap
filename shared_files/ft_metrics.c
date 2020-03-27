/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_metrics.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dominique <dominique@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/14 15:47:55 by dominique      #+#    #+#                */
/*   Updated: 2020/03/24 18:29:45 by dominique     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void				ft_calculate_buckets(t_prgm *prgm, int len)
{
	int				temp;

	temp = len;
	prgm->buckets = 2;
	while (temp > 10)
	{
		prgm->buckets += 2;
		temp = temp / 2;
	}
	if (temp % 2 != 0)
		prgm->bucket_size = (len / prgm->buckets) + 1;
	else
		prgm->bucket_size = len / prgm->buckets;
}

void				ft_update_buckets(t_prgm **prgm)
{
	t_stack_list	*sorted;
	int				i;
	int				j;

	sorted = (*prgm)->sorted_stack;
	i = 0;
	j = -1;
	while (sorted != NULL)
	{
		if ((i % (*prgm)->bucket_size) == 0)
		{
			// ft_printf("%d, %d \n", i, (*prgm)->bucket_size);
			j += 1;
		}
		sorted->bucket = j;
		sorted = sorted->next;
		i += 1;
	}
}

/*
** Instead of mallocking a Copy of my Linked List and
** doing merge sort to store the numbers in the copy 
** in ascending order
** I use the function ft_metrics_calculation where I iterate 
** through my linked list with 2 pointers and store the goal_pos 
** (where the number should be), the distance from the goal position
** (dis_from_goal)
** and the distance from top (dis_from_top)
*/

void				ft_metrics_calculation(t_prgm *prgm, t_stacks **stacks, \
											int init)
{
	t_stack_list	*temp;
	t_stack_list	*sorted;
	// int				len;
	int				i;
	int				j;

	temp = (*stacks)->stacka_lst;
	sorted = prgm->sorted_stack;
	i = 0;
	j = 0;
	while (temp != NULL)
	{
		// ft_printf("j = %d\n", j);
		// ft_printf("i = %d\n", i);
		// ft_printf("Stack C (copy) Sorted");
		// ft_print_doublyll(prgm->sorted_stack);
		while (sorted->num != temp->num)
		{
			// ft_printf("num %d\n", sorted->num);
			sorted = sorted->next;
			j += 1;
		}
		temp->goal_pos = j;
		temp->dis_from_top = i;
		temp->dis_from_goal = j - i;
		if (init == 1)
			temp->bucket = sorted->bucket;
		while (sorted->prev != NULL)
		{
			sorted = sorted->prev;
			j -= 1;
		}
		temp = temp->next;
		i += 1;
	}
	i = 0;
	temp = (*stacks)->stackb_lst;
	// len = ft_stack_length(temp);
	// ft_printf(ANSI_COLOR_CYAN"start here in Stack B = %d, %d\n", temp->prev, len);
	while (temp != NULL)
	{
		// ft_printf(ANSI_COLOR_CYAN"here in Stack B = %d, %d\n", temp->prev, temp->num);
		temp->dis_from_top = i;
		temp = temp->next;
		i += 1;
	}
}
