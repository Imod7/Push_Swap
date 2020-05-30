/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_presort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/05 13:06:40 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/05/30 10:52:36 by dominique     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** The splitting part of merge sort
*/

void				ft_splitlist(t_stack_list *completelist, \
								t_stack_list **ahalf, t_stack_list **bhalf)
{
	int				len;
	int				split;
	t_stack_list	*splitnode;

	len = ft_stack_len(completelist);
	split = (len % 2 == 0) ? (len / 2) : ((len / 2) + 1);
	if (len == 1)
	{
		*ahalf = completelist;
		(*ahalf)->next = NULL;
		*bhalf = NULL;
	}
	else
	{
		splitnode = completelist;
		while (split - 1 > 0)
		{
			splitnode = splitnode->next;
			split--;
		}
		*ahalf = completelist;
		*bhalf = splitnode->next;
		(*bhalf)->prev = NULL;
		splitnode->next = NULL;
	}
}

/*
** The merging part of merge sort
*/

t_stack_list		*ft_mergeback(t_stack_list **ahalf, t_stack_list **bhalf)
{
	t_stack_list	*result_list;

	result_list = NULL;
	if (*ahalf == NULL)
		return (*bhalf);
	else if (*bhalf == NULL)
		return (*ahalf);
	else
	{
		if ((*ahalf)->num > (*bhalf)->num)
		{
			result_list = *bhalf;
			result_list->next = ft_mergeback(&((*bhalf)->next), ahalf);
			result_list->next->prev = *bhalf;
		}
		else
		{
			result_list = *ahalf;
			result_list->next = ft_mergeback(&((*ahalf)->next), bhalf);
			result_list->next->prev = *ahalf;
		}
	}
	return (result_list);
}

/*
** Doing a presort in the Sorted Stack by implementing
** the Merge Sort algorithm
*/

void				ft_presort(t_stack_list **completelist)
{
	t_stack_list	*first_half;
	t_stack_list	*second_half;

	first_half = NULL;
	second_half = NULL;
	if ((*completelist)->next == NULL)
		return ;
	ft_splitlist((*completelist), &first_half, &second_half);
	ft_presort(&first_half);
	ft_presort(&second_half);
	*completelist = ft_mergeback(&first_half, &second_half);
}

/*
** Checking Stack A against Sorted Stack if they are the same
** which means Stack A is sorted
** The check is done in the beginning (in case the input is an
** already sorted list) or in the end to check if the algorithm
** sorted the Stack successfully
*/

int					ft_check_ifsorted(t_prgm *prgm)
{
	t_stack_list	*stacka;
	t_stack_list	*sorted;

	sorted = prgm->sorted_stack;
	stacka = prgm->stacks->stacka_lst;
	if (prgm->stacka_len != prgm->total_numbers)
		return (ft_exit_msg(prgm, 1));
	if ((prgm->stacka_len != ft_stack_len(sorted)) && \
	(prgm->stackb_len == 0))
		return (ft_exit_msg(prgm, 0));
	if ((stacka == NULL) || (stacka->next == NULL))
		(prgm->exec == 0) ? ft_printf("OK\n") : (void)prgm;
	else
	{
		while (stacka != NULL)
		{
			if (sorted->num != stacka->num)
				return (ft_exit_msg(prgm, 1));
			sorted = sorted->next;
			stacka = stacka->next;
		}
		(prgm->exec == 0) ? ft_printf("OK\n") : (void)prgm;
	}
	return (0);
}
