/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_stack_oper_rrotation.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/24 14:53:01 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/04/12 22:54:26 by dominique     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int					ft_reverserotate_a(t_prgm *prgm, t_stacks **stacks)
{
	t_stack_list	*first_node;
	t_stack_list	*last_node;

	last_node = (*stacks)->stacka_lst;
	if (last_node == NULL)
		return (0);
	first_node = (*stacks)->stacka_lst;
	while (last_node->next != NULL)
		last_node = last_node->next;
	last_node->prev->next = NULL;
	last_node->prev = NULL;
	last_node->next = first_node;
	first_node->prev = last_node;
	(*stacks)->stacka_lst = last_node;
	if (prgm->exec == 1)
	{
		ft_saveinstructions(prgm, *stacks, "rra");
		ft_metrics_calculation(prgm, stacks, 0);
	}
	return (0);
}

int					ft_reverserotate_b(t_prgm *prgm, t_stacks **stacks)
{
	t_stack_list	*first_node;
	t_stack_list	*last_node;

	(void)(*stacks)->stacka_lst;
	last_node = (*stacks)->stackb_lst;
	if (ft_stack_len(last_node) < 2)
		return (0);
	first_node = (*stacks)->stackb_lst;
	while (last_node->next != NULL)
		last_node = last_node->next;
	last_node->prev->next = NULL;
	last_node->prev = NULL;
	last_node->next = first_node;
	first_node->prev = last_node;
	(*stacks)->stackb_lst = last_node;
	if (prgm->exec == 1)
	{
		ft_saveinstructions(prgm, *stacks, "rrb");
		ft_metrics_calculation(prgm, stacks, 0);
	}
	return (0);
}

int				ft_reverserotate_both(t_prgm *prgm, t_stacks **stacks)
{
	size_t		flag;

	flag = 0;
	if (ft_stack_len((*stacks)->stacka_lst) >= 2)
	{
		ft_reverserotate_a(prgm, stacks);
		flag = 1;
	}
	if (ft_stack_len((*stacks)->stackb_lst) >= 2)
	{
		ft_reverserotate_b(prgm, stacks);
		flag = 2;
	}
	if ((flag > 0) && (prgm->exec == 1))
	{
		ft_saveinstructions(prgm, *stacks, "rrr");
		ft_metrics_calculation(prgm, stacks, 0);
	}
	return (0);
}
