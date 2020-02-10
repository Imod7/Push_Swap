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

void		ft_swap_a(t_stack *stack_a, t_stack *stack_b)
{
	int		temp_a;
	t_stack	*temp_b;

	ft_printf("swap_a function called\n");
	temp_b = stack_b;
	temp_a = stack_a->num;
}

void		ft_swap_b(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*first_node;
	t_stack	*second_node;
	t_stack	*temp_b;

	temp_b = stack_b;
	ft_printf("swap_b function called\n");
	first_node = stack_a;
	second_node = stack_a->next;
	stack_a = second_node;
}

void		ft_swap_both(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*first_node;
	t_stack	*second_node;
	t_stack	*temp_b;

	temp_b = stack_b;
	ft_printf("ss function called\n");
	first_node = stack_a;
	second_node = stack_a->next;
	stack_a = second_node;
}

void		ft_push_a(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*first_node;
	t_stack	*second_node;
	t_stack	*temp_b;

	temp_b = stack_b;
	ft_printf("push_a function called\n");
	first_node = stack_a;
	second_node = stack_a->next;
	stack_a = second_node;
}

void		ft_push_b(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*first_node;
	t_stack	*second_node;
	t_stack	*temp_b;

	temp_b = stack_b;
	ft_printf("push_b function called\n");
	first_node = stack_a;
	second_node = stack_a->next;
	stack_a = second_node;
}

void		ft_rotate_a(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*first_node;
	t_stack	*second_node;
	t_stack	*temp_b;

	temp_b = stack_b;
	ft_printf("rotate_a function called\n");
	first_node = stack_a;
	second_node = stack_a->next;
	stack_a = second_node;
}

void		ft_rotate_b(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*first_node;
	t_stack	*second_node;
	t_stack	*temp_b;

	temp_b = stack_b;
	ft_printf("rotate_b function called\n");
	first_node = stack_a;
	second_node = stack_a->next;
	stack_a = second_node;
}

void		ft_rotate_both(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*first_node;
	t_stack	*second_node;
	t_stack	*temp_b;

	temp_b = stack_b;
	ft_printf("rotate_a_rotate_b function called\n");
	first_node = stack_a;
	second_node = stack_a->next;
	stack_a = second_node;
}

void		ft_reverserotate_a(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*first_node;
	t_stack	*second_node;
	t_stack	*temp_b;

	temp_b = stack_b;
	ft_printf("ft_reverserotate_a function called\n");
	first_node = stack_a;
	second_node = stack_a->next;
	stack_a = second_node;
}

void		ft_reverserotate_b(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*first_node;
	t_stack	*second_node;
	t_stack	*temp_b;

	temp_b = stack_b;
	ft_printf("ft_reverserotate_b function called\n");
	first_node = stack_a;
	second_node = stack_a->next;
	stack_a = second_node;
}

void		ft_reverserotate_both(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*first_node;
	t_stack	*second_node;
	t_stack	*temp_b;

	temp_b = stack_b;
	ft_printf("ft_reverserotate_both function called\n");
	first_node = stack_a;
	second_node = stack_a->next;
	stack_a = second_node;
}
