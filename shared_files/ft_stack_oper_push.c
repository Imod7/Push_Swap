/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_stack_oper_push.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/24 14:53:01 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/05/30 10:30:55 by dominique     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int					ft_push_a(t_prgm *prgm)
{
	t_stack_list	*first_node_b;
	t_stack_list	*second_node_b;
	t_stack_list	*first_node_a;

	first_node_b = prgm->stacks->stackb_lst;
	if (first_node_b == NULL)
		return (0);
	second_node_b = prgm->stacks->stackb_lst->next;
	prgm->stacks->stackb_lst = second_node_b;
	if (second_node_b != NULL)
		second_node_b->prev = NULL;
	first_node_a = prgm->stacks->stacka_lst;
	first_node_b->next = first_node_a;
	first_node_b->prev = NULL;
	prgm->stacks->stacka_lst = first_node_b;
	if (first_node_a != NULL)
		first_node_b->next->prev = first_node_b;
	ft_metrics_calculation(prgm, 0);
	if (prgm->exec == 1)
		ft_saveinstructions(prgm, "pa");
	return (0);
}

int					ft_push_b(t_prgm *prgm)
{
	t_stack_list	*first_node_a;
	t_stack_list	*second_node_a;
	t_stack_list	*first_node_b;

	first_node_a = prgm->stacks->stacka_lst;
	if (first_node_a == NULL)
		return (0);
	second_node_a = prgm->stacks->stacka_lst->next;
	prgm->stacks->stacka_lst = second_node_a;
	if (second_node_a != NULL)
		second_node_a->prev = NULL;
	first_node_b = prgm->stacks->stackb_lst;
	first_node_a->next = first_node_b;
	first_node_a->prev = NULL;
	prgm->stacks->stackb_lst = first_node_a;
	if (first_node_b != NULL)
		first_node_a->next->prev = first_node_a;
	ft_metrics_calculation(prgm, 0);
	if (prgm->exec == 1)
		ft_saveinstructions(prgm, "pb");
	return (0);
}
