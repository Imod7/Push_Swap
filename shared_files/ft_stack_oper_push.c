/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_stack_oper_push.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/24 14:53:01 by dsaripap       #+#    #+#                */
/*   Updated: 2020/03/29 18:24:30 by dominique     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int					ft_push_a(t_prgm *prgm, t_stacks **stacks)
{
	t_stack_list	*first_node;
	t_stack_list	*second_node;
	t_stack_list	*temp;
	t_stack_list 	*newnode;

	// ft_printf("pa\n");
	first_node = (*stacks)->stackb_lst;
	if (first_node == NULL)
		return (0);
	second_node = (*stacks)->stackb_lst->next;
	(*stacks)->stackb_lst = second_node;
	if (second_node != NULL)
		second_node->prev = NULL;
	temp = (*stacks)->stacka_lst;
	newnode = ft_stack_newnode(first_node->num);
	newnode->next = temp;
	newnode->prev = NULL;
	(*stacks)->stacka_lst = newnode;
	if (temp != NULL)
		newnode->next->prev = newnode;
	// prgm->number_operations += 1;
	if (prgm->exec == 1)
	{
		ft_saveinstructions(prgm, *stacks, "pa");
		ft_metrics_calculation(prgm, stacks, 0);
	}
	// if (prgm->options & OPTION_V)
	// 	ft_print_stacks(*stacks);
	return (0);
}

int					ft_push_b(t_prgm *prgm, t_stacks **stacks)
{
	t_stack_list	*first_node;
	t_stack_list	*second_node;
	t_stack_list	*temp;
	t_stack_list	*newnode;

	// ft_printf("pb\n");
	first_node = (*stacks)->stacka_lst;
	if (first_node == NULL)
		return (0);
	second_node = (*stacks)->stacka_lst->next;
	(*stacks)->stacka_lst = second_node;
	if (second_node != NULL)
		second_node->prev = NULL;
	// if ((*stacks)->stackb_lst == NULL)
	// 	(*stacks)->stackb_lst = ft_memalloc(sizeof(t_stack_list));
	temp = (*stacks)->stackb_lst;
	// temp_b = ft_memalloc(sizeof(t_stack));
	newnode = ft_stack_newnode(first_node->num);
	newnode->next = temp;
	newnode->prev = NULL;
	(*stacks)->stackb_lst = newnode;
	if (temp != NULL)
		newnode->next->prev = newnode;
	// prgm->number_operations += 1;
	if (prgm->exec == 1)
	{
		ft_saveinstructions(prgm, *stacks, "pb");
		ft_metrics_calculation(prgm, stacks, 0);
	}
	// if (prgm->options & OPTION_V)
	// 	ft_print_stacks(*stacks);
	return (0);
}
