/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_stacka_vs_stackb.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <dsaripap@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/07 15:15:48 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/06/07 15:17:25 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Checks if the numbers left in Stack A are sorted
** and if all nums in B are smaller than the min num in A
*/

int						ft_bnums_smaller_anums(t_prgm *prgm)
{
	t_stack_list		*stacka;
	t_stack_list		*stackb;

	stacka = prgm->stacks->stacka_lst;
	stackb = prgm->stacks->stackb_lst;
	while (stackb != NULL)
	{
		if (stackb->num < stacka->num)
			stackb = stackb->next;
		else
			return (ERROR);
	}
	while (stacka->next != NULL)
	{
		if (stacka->num < stacka->next->num)
			stacka = stacka->next;
		else
			return (ERROR);
	}
	return (SUCCESS);
}

/*
** Checks if the numbers left in Stack A are sorted
** and if all nums in B are bigger then the max num in A
*/

int						ft_bnums_bigger_anums(t_prgm *prgm)
{
	t_stack_list		*stacka;
	t_stack_list		*stackb;

	stacka = prgm->stacks->stacka_lst;
	stackb = prgm->stacks->stackb_lst;
	while (stackb != NULL)
	{
		if (stackb->num > stacka->num)
			stackb = stackb->next;
		else
			return (ERROR);
	}
	while (stacka->next != NULL)
	{
		if (stacka->num < stacka->next->num)
			stacka = stacka->next;
		else
			return (ERROR);
	}
	return (SUCCESS);
}
