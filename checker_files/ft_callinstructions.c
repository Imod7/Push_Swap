/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_callinstructions.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/12 13:44:41 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/02/12 13:44:45 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void				ft_print_mode(t_prgm_props *prgm_sets, t_stack *stack_a, \
								t_stack *stack_b)
{
	if (prgm_sets->debug_mode == 1)
		ft_printf(ANSI_COLOR_YELLOW"\nPrinting Intermediate State of Stacks"\
				ANSI_COLOR_RESET);
	else if (prgm_sets->debug_mode == 2)
		ft_printf(ANSI_COLOR_GREEN"\nPrinting FINAL State of Stacks"\
				ANSI_COLOR_RESET);
	if ((prgm_sets->debug_mode == 1) || (prgm_sets->debug_mode == 2))
	{
		ft_print_stack(stack_a);
		ft_print_stack(stack_b);
	}
}

void				ft_call_instructfunctions(t_instr *lst, t_stack **stack_a, \
											t_stack **stack_b, \
											t_prgm_props *prgm_sets)
{
	t_instr			*temp;
	operation_func	oper_func[11];

	oper_func[0] = ft_swap_a;
	oper_func[1] = ft_swap_b;
	oper_func[2] = ft_swap_both;
	oper_func[3] = ft_push_a;
	oper_func[4] = ft_push_b;
	oper_func[5] = ft_rotate_a;
	oper_func[6] = ft_rotate_b;
	oper_func[7] = ft_rotate_both;
	oper_func[8] = ft_reverserotate_a;
	oper_func[9] = ft_reverserotate_b;
	oper_func[10] = ft_reverserotate_both;
	temp = lst;
	if (temp == NULL)
		;
	while (temp != NULL)
	{
		oper_func[temp->instruction](&(*stack_a)->stack_lst, \
									&(*stack_b)->stack_lst);
		ft_print_mode(prgm_sets, *stack_a, *stack_b);
		temp = temp->next;
	}
	prgm_sets->debug_mode = 2;
	ft_print_mode(prgm_sets, *stack_a, *stack_b);
}
