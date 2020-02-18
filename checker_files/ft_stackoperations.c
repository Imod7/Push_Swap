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

static	void	swap_nodes(t_stack *node1, t_stack *node2)
{
	int			temp;

	ft_printf(">>swap_nodes function called\n");
	temp = node1->num;
	node1->num = node2->num;
	node2->num = temp;
}

int				ft_swap_a(t_stack **stacka_ref, t_stack **stackb_ref)
{
	(void)*stackb_ref;
	ft_printf("swap_a function called\n");
	if (ft_stack_length(*stacka_ref) < 2)
		return (0);
	swap_nodes(*stacka_ref, (*stacka_ref)->next);
	return (0);
}

int				ft_swap_b(t_stack **stacka_ref, t_stack **stackb_ref)
{
	(void)*stacka_ref;
	ft_printf("swap_b function called , len = %d\n", ft_stack_length(*stackb_ref));
	if (ft_stack_length(*stackb_ref) < 2)
		return (0);
	swap_nodes(*stackb_ref, (*stackb_ref)->next);
	return (0);
}

int				ft_swap_both(t_stack **stacka_ref, t_stack **stackb_ref)
{
	ft_printf("ss function called\n");
	if (ft_stack_length(*stacka_ref) >= 2)
		swap_nodes(*stacka_ref, (*stacka_ref)->next);
	if (ft_stack_length(*stackb_ref) >= 2)
		swap_nodes(*stackb_ref, (*stackb_ref)->next);
	return (0);
}

int				ft_push_a(t_stack **stacka_ref, t_stack **stack_b)
{
	t_stack	*first_node;
	t_stack	*second_node;
	t_stack	*temp_b;

	temp_b = *stack_b;
	ft_printf("push_a function called\n");
	first_node = *stacka_ref;
	second_node = (*stacka_ref)->next;
	*stacka_ref = second_node;
	return (0);
}

int				ft_push_b(t_stack **stacka_ref, t_stack **stack_b)
{
	t_stack	*first_node;
	t_stack	*second_node;
	t_stack	*temp_b;

	temp_b = *stack_b;
	if (temp_b == NULL)
		temp_b = ft_memalloc(sizeof(t_stack));
	ft_printf("push_b function called\n");
	first_node = *stacka_ref;
	second_node = (*stacka_ref)->next;
	*stacka_ref = second_node;
	return (0);
}

int				ft_rotate_a(t_stack **stacka_ref, t_stack **stack_b)
{
	t_stack	*first_node;
	t_stack	*second_node;
	t_stack	*temp_b;

	temp_b = *stack_b;
	ft_printf("rotate_a function called\n");
	first_node = *stacka_ref;
	second_node = (*stacka_ref)->next;
	*stacka_ref = second_node;
	return (0);
}

int				ft_rotate_b(t_stack **stacka_ref, t_stack **stack_b)
{
	t_stack	*first_node;
	t_stack	*second_node;
	t_stack	*temp_b;

	temp_b = *stack_b;
	ft_printf("rotate_b function called\n");
	first_node = *stacka_ref;
	second_node = (*stacka_ref)->next;
	*stacka_ref = second_node;
	return (0);
}

int				ft_rotate_both(t_stack **stacka_ref, t_stack **stack_b)
{
	t_stack	*first_node;
	t_stack	*second_node;
	t_stack	*temp_b;

	temp_b = *stack_b;
	ft_printf("rotate_a_rotate_b function called\n");
	first_node = *stacka_ref;
	second_node = (*stacka_ref)->next;
	*stacka_ref = second_node;
	return (0);
}

int				ft_reverserotate_a(t_stack **stacka_ref, t_stack **stack_b)
{
	t_stack	*first_node;
	t_stack	*second_node;
	t_stack	*temp_b;

	temp_b = *stack_b;
	ft_printf("ft_reverserotate_a function called\n");
	first_node = *stacka_ref;
	second_node = (*stacka_ref)->next;
	*stacka_ref = second_node;
	return (0);
}

int				ft_reverserotate_b(t_stack **stacka_ref, t_stack **stack_b)
{
	t_stack	*first_node;
	t_stack	*second_node;
	t_stack	*temp_b;

	temp_b = *stack_b;
	ft_printf("ft_reverserotate_b function called\n");
	first_node = *stacka_ref;
	second_node = (*stacka_ref)->next;
	*stacka_ref = second_node;
	return (0);
}

int				ft_reverserotate_both(t_stack **stacka_ref, t_stack **stack_b)
{
	t_stack	*first_node;
	t_stack	*second_node;
	t_stack	*temp_b;

	temp_b = *stack_b;
	ft_printf("ft_reverserotate_both function called\n");
	first_node = *stacka_ref;
	second_node = (*stacka_ref)->next;
	*stacka_ref = second_node;
	return (0);
}
