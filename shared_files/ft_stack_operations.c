/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_stack_operations.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/24 14:53:01 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/02/24 14:53:04 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static	void		swap_nodes(t_stack_list *node1, t_stack_list *node2)
{
	int				temp;

	temp = node1->num;
	node1->num = node2->num;
	node2->num = temp;
}

int					ft_swap_a(t_stacks **stacks)
{
	(void)(*stacks)->stackb_lst;
	ft_printf("sa\n");
	if (ft_stack_length((*stacks)->stacka_lst) < 2)
		return (0);
	swap_nodes((*stacks)->stacka_lst, ((*stacks)->stacka_lst)->next);
	return (0);
}

int					ft_swap_b(t_stacks **stacks)
{
	ft_printf("sb\n");
	if (ft_stack_length((*stacks)->stackb_lst) < 2)
		return (0);
	swap_nodes((*stacks)->stackb_lst, ((*stacks)->stackb_lst)->next);
	return (0);
}

int					ft_swap_both(t_stacks **stacks)
{
	ft_printf("ss\n");
	if (ft_stack_length((*stacks)->stacka_lst) >= 2)
		swap_nodes((*stacks)->stacka_lst, (*stacks)->stacka_lst->next);
	if (ft_stack_length((*stacks)->stackb_lst) >= 2)
		swap_nodes((*stacks)->stackb_lst, ((*stacks)->stackb_lst)->next);
	return (0);
}

int					ft_push_a(t_stacks **stacks)
{
	t_stack_list	*first_node;
	t_stack_list	*second_node;
	t_stack_list	*temp_a;
	t_stack_list 	*newnode_a;

	ft_printf("pa\n");
	first_node = (*stacks)->stackb_lst;
	second_node = (*stacks)->stackb_lst->next;
	(*stacks)->stackb_lst = second_node;
	temp_a = (*stacks)->stacka_lst;
	// temp_b = ft_memalloc(sizeof(t_stack));
	newnode_a = ft_stack_newnode(first_node->num);
	newnode_a->next = temp_a;
	newnode_a->prev = NULL;
	(*stacks)->stacka_lst = newnode_a;
	if (temp_a != NULL)
		newnode_a->next->prev = newnode_a;
	return (0);
}

int					ft_push_b(t_stacks **stacks)
{
	t_stack_list	*first_node;
	t_stack_list	*second_node;
	t_stack_list	*temp_b;
	t_stack_list	*newnode_b;

	ft_printf("pb\n");
	first_node = (*stacks)->stacka_lst;
	second_node = (*stacks)->stacka_lst->next;
	(*stacks)->stacka_lst = second_node;
	if (second_node != NULL)
		second_node->prev = NULL;
	temp_b = (*stacks)->stackb_lst;
	// temp_b = ft_memalloc(sizeof(t_stack));
	newnode_b = ft_stack_newnode(first_node->num);
	newnode_b->next = temp_b;
	newnode_b->prev = NULL;
	((*stacks)->stackb_lst) = newnode_b;
	if (temp_b != NULL)
		newnode_b->next->prev = newnode_b;
	return (0);
}

int					ft_rotate_a(t_stacks **stacks)
{
	t_stack_list	*first_node;
	t_stack_list	*second_node;
	t_stack_list	*temp_a;

	ft_printf("ra\n");
	(void)(*stacks)->stackb_lst;
	temp_a = (*stacks)->stacka_lst;
	if (ft_stack_length(temp_a) < 2)
		return (0);
	first_node = (*stacks)->stacka_lst;
	second_node = (*stacks)->stacka_lst->next;
	second_node->prev = NULL;
	while (temp_a->next != NULL)
		temp_a = temp_a->next;
	temp_a->next = first_node;
	first_node->prev = temp_a;
	first_node->next = NULL;
	(*stacks)->stacka_lst = second_node;
	return (0);
}

int					ft_rotate_b(t_stacks **stacks)
{
	t_stack_list	*first_node;
	t_stack_list	*second_node;
	t_stack_list	*temp_b;

	ft_printf("rb\n");
	(void)(*stacks)->stacka_lst;
	temp_b = (*stacks)->stackb_lst;
	if (ft_stack_length(temp_b) < 2)
		return (0);
	first_node = (*stacks)->stackb_lst;
	second_node = ((*stacks)->stackb_lst)->next;
	second_node->prev = NULL;
	while (temp_b->next != NULL)
		temp_b = temp_b->next;
	temp_b->next = first_node;
	first_node->prev = temp_b;
	first_node->next = NULL;
	(*stacks)->stackb_lst = second_node;
	return (0);
}

int					ft_rotate_both(t_stacks **stacks)
{
	ft_printf("rr function called\n");
	if (ft_stack_length((*stacks)->stacka_lst) >= 2)
		ft_rotate_a(stacks);
	if (ft_stack_length((*stacks)->stackb_lst) >= 2)
		ft_rotate_b(stacks);
	return (0);
}

int					ft_reverserotate_a(t_stacks **stacks)
{
	t_stack_list	*first_node;
	t_stack_list	*last_node;

	ft_printf("rra\n");
	(void)(*stacks)->stackb_lst;
	last_node = (*stacks)->stacka_lst;
	if (ft_stack_length(last_node) < 2)
		return (0);
	first_node = (*stacks)->stacka_lst;
	while (last_node->next != NULL)
		last_node = last_node->next;
	last_node->prev->next = NULL;
	last_node->prev = NULL;
	last_node->next = first_node;
	first_node->prev = last_node;
	(*stacks)->stacka_lst = last_node;
	return (0);
}

int					ft_reverserotate_b(t_stacks **stacks)
{
	t_stack_list	*first_node;
	t_stack_list	*last_node;

	ft_printf("rrb\n");
	(void)(*stacks)->stacka_lst;
	last_node = (*stacks)->stackb_lst;
	if (ft_stack_length(last_node) < 2)
		return (0);
	first_node = (*stacks)->stackb_lst;
	while (last_node->next != NULL)
		last_node = last_node->next;
	last_node->prev->next = NULL;
	last_node->prev = NULL;
	last_node->next = first_node;
	first_node->prev = last_node;
	(*stacks)->stackb_lst = last_node;
	return (0);
}

int				ft_reverserotate_both(t_stacks **stacks)
{
	ft_printf("rrr\n");
	if (ft_stack_length((*stacks)->stacka_lst) >= 2)
		ft_reverserotate_a(stacks);
	if (ft_stack_length((*stacks)->stackb_lst) >= 2)
		ft_reverserotate_b(stacks);
	return (0);
}
