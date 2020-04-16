/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_stack_oper_rrotation.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/24 14:53:01 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/04/16 10:32:08 by dominique     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int					ft_reverserotate_a(t_prgm *prgm)
{
	t_stack_list	*first_node;
	t_stack_list	*last_node;

	last_node = prgm->stacks->stacka_lst;
	if (last_node == NULL)
		return (0);
	first_node = prgm->stacks->stacka_lst;
	while (last_node->next != NULL)
		last_node = last_node->next;
	last_node->prev->next = NULL;
	last_node->prev = NULL;
	last_node->next = first_node;
	first_node->prev = last_node;
	prgm->stacks->stacka_lst = last_node;
	if (prgm->exec == 1)
	{
		ft_saveinstructions(prgm, "rra");
		ft_metrics_calculation(prgm, 0);
	}
	return (0);
}

int					ft_reverserotate_b(t_prgm *prgm)
{
	t_stack_list	*first_node;
	t_stack_list	*last_node;

	last_node = prgm->stacks->stackb_lst;
	if (ft_stack_len(last_node) < 2)
		return (0);
	first_node = prgm->stacks->stackb_lst;
	while (last_node->next != NULL)
		last_node = last_node->next;
	last_node->prev->next = NULL;
	last_node->prev = NULL;
	last_node->next = first_node;
	first_node->prev = last_node;
	prgm->stacks->stackb_lst = last_node;
	if (prgm->exec == 1)
	{
		ft_saveinstructions(prgm, "rrb");
		ft_metrics_calculation(prgm, 0);
	}
	return (0);
}

int					ft_reverserotate_both(t_prgm *prgm)
{
	size_t			flag;

	flag = 0;
	if (ft_stack_len(prgm->stacks->stacka_lst) >= 2)
	{
		ft_reverserotate_a(prgm);
		flag = 1;
	}
	if (ft_stack_len(prgm->stacks->stackb_lst) >= 2)
	{
		ft_reverserotate_b(prgm);
		flag = 2;
	}
	if ((flag > 0) && (prgm->exec == 1))
	{
		ft_saveinstructions(prgm, "rrr");
		ft_metrics_calculation(prgm, 0);
	}
	return (0);
}
