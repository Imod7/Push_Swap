/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_stackoperations.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/31 19:07:15 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/01/31 19:07:18 by dsaripap      ########   odam.nl         */
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

int					ft_swap_a(t_stack_list **stacka_ref, \
								t_stack_list **stackb_ref)
{
	(void)*stackb_ref;
	ft_printf("sa\n");
	if (ft_stack_length(*stacka_ref) < 2)
		return (0);
	swap_nodes(*stacka_ref, (*stacka_ref)->next);
	return (0);
}

int					ft_swap_b(t_stack_list **stacka_ref, \
								t_stack_list **stackb_ref)
{
	(void)*stacka_ref;
	ft_printf("sb\n");
	if (ft_stack_length(*stackb_ref) < 2)
		return (0);
	swap_nodes(*stackb_ref, (*stackb_ref)->next);
	return (0);
}

int					ft_swap_both(t_stack_list **stacka_ref, \
									t_stack_list **stackb_ref)
{
	ft_printf("ss\n");
	if (ft_stack_length(*stacka_ref) >= 2)
		swap_nodes(*stacka_ref, (*stacka_ref)->next);
	if (ft_stack_length(*stackb_ref) >= 2)
		swap_nodes(*stackb_ref, (*stackb_ref)->next);
	return (0);
}

int					ft_push_a(t_stack_list **stacka_ref, \
								t_stack_list **stackb_ref)
{
	t_stack_list	*first_node;
	t_stack_list	*second_node;
	t_stack_list	*temp_a;
	t_stack_list 	*newnode_a;

	ft_printf("pa\n");
	first_node = *stackb_ref;
	second_node = (*stackb_ref)->next;
	*stackb_ref = second_node;
	temp_a = *stacka_ref;
	// temp_b = ft_memalloc(sizeof(t_stack));
	newnode_a = ft_stack_newnode(first_node->num);
	newnode_a->next = temp_a;
	newnode_a->prev = NULL;
	(*stacka_ref) = newnode_a;
	if (temp_a != NULL)
		newnode_a->next->prev = newnode_a;
	return (0);
}

int					ft_push_b(t_stack_list **stacka_ref, \
							t_stack_list **stackb_ref)
{
	t_stack_list	*first_node;
	t_stack_list	*second_node;
	t_stack_list	*temp_b;
	t_stack_list	*newnode_b;

	ft_printf("pb\n");
	first_node = *stacka_ref;
	second_node = (*stacka_ref)->next;
	*stacka_ref = second_node;
	temp_b = *stackb_ref;
	// temp_b = ft_memalloc(sizeof(t_stack));
	newnode_b = ft_stack_newnode(first_node->num);
	newnode_b->next = temp_b;
	newnode_b->prev = NULL;
	(*stackb_ref) = newnode_b;
	if (temp_b != NULL)
		newnode_b->next->prev = newnode_b;
	return (0);
}

int					ft_rotate_a(t_stack_list **stacka_ref, \
								t_stack_list **stackb_ref)
{
	t_stack_list	*first_node;
	t_stack_list	*second_node;
	t_stack_list	*temp_a;

	ft_printf("ra\n");
	(void)*stackb_ref;
	temp_a = *stacka_ref;
	if (ft_stack_length(temp_a) < 2)
		return (0);
	first_node = *stacka_ref;
	second_node = (*stacka_ref)->next;
	second_node->prev = NULL;
	while (temp_a->next != NULL)
		temp_a = temp_a->next;
	temp_a->next = first_node;
	first_node->prev = temp_a;
	first_node->next = NULL;
	*stacka_ref = second_node;
	return (0);
}

int					ft_rotate_b(t_stack_list **stacka_ref, \
								t_stack_list **stackb_ref)
{
	t_stack_list	*first_node;
	t_stack_list	*second_node;
	t_stack_list	*temp_b;

	ft_printf("rb\n");
	(void)*stacka_ref;
	temp_b = *stackb_ref;
	if (ft_stack_length(temp_b) < 2)
		return (0);
	first_node = *stackb_ref;
	second_node = (*stackb_ref)->next;
	second_node->prev = NULL;
	while (temp_b->next != NULL)
		temp_b = temp_b->next;
	temp_b->next = first_node;
	first_node->prev = temp_b;
	first_node->next = NULL;
	*stackb_ref = second_node;
	return (0);
}

int					ft_rotate_both(t_stack_list **stacka_ref, \
									t_stack_list **stackb_ref)
{
	ft_printf("rr function called\n");
	if (ft_stack_length(*stacka_ref) >= 2)
		ft_rotate_a(stacka_ref, stackb_ref);
	if (ft_stack_length(*stackb_ref) >= 2)
		ft_rotate_b(stacka_ref, stackb_ref);
	return (0);
}

int					ft_reverserotate_a(t_stack_list **stacka_ref, \
										t_stack_list **stackb_ref)
{
	t_stack_list	*first_node;
	t_stack_list	*last_node;

	ft_printf("rra\n");
	(void)*stackb_ref;
	last_node = *stacka_ref;
	if (ft_stack_length(last_node) < 2)
		return (0);
	first_node = *stacka_ref;
	while (last_node->next != NULL)
		last_node = last_node->next;
	last_node->prev->next = NULL;
	last_node->prev = NULL;
	last_node->next = first_node;
	first_node->prev = last_node;
	*stacka_ref = last_node;
	return (0);
}

int					ft_reverserotate_b(t_stack_list **stacka_ref, \
										t_stack_list **stackb_ref)
{
	t_stack_list	*first_node;
	t_stack_list	*last_node;

	ft_printf("rrb\n");
	(void)*stacka_ref;
	last_node = *stackb_ref;
	if (ft_stack_length(last_node) < 2)
		return (0);
	first_node = *stackb_ref;
	while (last_node->next != NULL)
		last_node = last_node->next;
	last_node->prev->next = NULL;
	last_node->prev = NULL;
	last_node->next = first_node;
	first_node->prev = last_node;
	*stackb_ref = last_node;
	return (0);
}

int				ft_reverserotate_both(t_stack_list **stacka_ref, \
									t_stack_list **stackb_ref)
{
	ft_printf("rrr\n");
	if (ft_stack_length(*stacka_ref) >= 2)
		ft_reverserotate_a(stacka_ref, stackb_ref);
	if (ft_stack_length(*stackb_ref) >= 2)
		ft_reverserotate_b(stacka_ref, stackb_ref);
	return (0);
}
