/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_stack_oper_push.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/24 14:53:01 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/04/16 10:50:19 by dominique     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int					ft_push_a(t_prgm *prgm)
{
	t_stack_list	*first_node;
	t_stack_list	*second_node;
	t_stack_list	*temp;
	t_stack_list	*newnode;

	first_node = prgm->stacks->stackb_lst;
	if (first_node == NULL)
		return (0);
	second_node = prgm->stacks->stackb_lst->next;
	prgm->stacks->stackb_lst = second_node;
	if (second_node != NULL)
		second_node->prev = NULL;
	temp = prgm->stacks->stacka_lst;
	newnode = ft_stack_newnode(first_node->num);
	newnode->next = temp;
	newnode->prev = NULL;
	prgm->stacks->stacka_lst = newnode;
	if (temp != NULL)
		newnode->next->prev = newnode;
	if (prgm->exec == 1)
	{
		ft_saveinstructions(prgm, "pa");
		ft_metrics_calculation(prgm, 0);
	}
	return (0);
}

int					ft_push_b(t_prgm *prgm)
{
	t_stack_list	*first_node;
	t_stack_list	*second_node;
	t_stack_list	*temp;
	t_stack_list	*newnode;

	first_node = prgm->stacks->stacka_lst;
	if (first_node == NULL)
		return (0);
	second_node = prgm->stacks->stacka_lst->next;
	prgm->stacks->stacka_lst = second_node;
	if (second_node != NULL)
		second_node->prev = NULL;
	temp = prgm->stacks->stackb_lst;
	newnode = ft_stack_newnode(first_node->num);
	newnode->next = temp;
	newnode->prev = NULL;
	prgm->stacks->stackb_lst = newnode;
	if (temp != NULL)
		newnode->next->prev = newnode;
	if (prgm->exec == 1)
	{
		ft_saveinstructions(prgm, "pb");
		ft_metrics_calculation(prgm, 0);
	}
	return (0);
}
