/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 12:08:15 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/01/29 13:07:35 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int				ft_push_btemp(t_stack **stacka_ref, t_stack_prop **stack_b)
{
	t_stack	*first_node;
	t_stack	*second_node;
	t_stack	*temp_b;
	t_stack *newnode_b;

	// first_node = ft_memalloc(sizeof(t_stack));
	// second_node = ft_memalloc(sizeof(t_stack));
	ft_printf("push_b function called\n");
	first_node = *stacka_ref;
	second_node = (*stacka_ref)->next;
	*stacka_ref = second_node;
	temp_b = (*stack_b)->stack_lst;
	if (temp_b == NULL)
	{
		newnode_b = ft_stack_newnode(first_node->num);
		newnode_b->next = temp_b;
		ft_printf("einai NULL %d \n", newnode_b->num);
		newnode_b->prev = NULL;
		temp_b = newnode_b;
	}
	ft_print_stack(*stacka_ref);
	ft_print_stacktemp(*stack_b);
	return (0);
}

int					ft_exitprogram(int signal, t_stack **stack_lst)
{
	if (signal == -1)
	{
		ft_free_list(stack_lst);
		return (-1);
	}
	return (0);
}

int					main(int argc, char **argv)
{
	t_stack			*stack_a;
	t_stack_prop	*stack_b;
	t_instr			*instr_lst;
	char			operation[BUFFER_SIZE + 1];

	stack_a = NULL;
	stack_b = ft_memalloc(sizeof(t_stack_prop));
	instr_lst = NULL;
	if (argc < 2)
		return (0);
	else
	{
		if (ft_build_stacka(argc, argv, &stack_a) == -1)
			return (ft_exitprogram(-1, &stack_a));
	}
	ft_build_stackb(&stack_b);
	ft_bzero(operation, BUFFER_SIZE + 1);
	read(0, operation, BUFFER_SIZE);
	while (ft_strcmp(operation, "\n") != 0)
	{
		if (ft_saveinstructions(&instr_lst, operation) == -1)
			return (ft_exitprogram(-1, &stack_a));
		ft_bzero(operation, BUFFER_SIZE + 1);
		read(0, operation, BUFFER_SIZE);
	}
	// ft_print_instructions(instr_lst);
	// ft_call_instructfunctions(instr_lst, &stack_a, &stack_b);
	ft_push_btemp(&stack_a, &stack_b);
	return (0);
}
