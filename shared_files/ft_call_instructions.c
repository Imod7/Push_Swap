/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_call_instructions.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/24 14:53:52 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/04/30 12:14:33 by dominique     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void					ft_checkinstruction(size_t instruction)
{
	if (instruction & INSTR_SA)
		ft_printf("sa\n");
	if (instruction & INSTR_SB)
		ft_printf("sb\n");
	if (instruction & INSTR_SS)
		ft_printf("ss\n");
	if (instruction & INSTR_PA)
		ft_printf("pa\n");
	if (instruction & INSTR_PB)
		ft_printf("pb\n");
	if (instruction & INSTR_RA)
		ft_printf("ra\n");
	if (instruction & INSTR_RB)
		ft_printf("rb\n");
	if (instruction & INSTR_RR)
		ft_printf("rr\n");
	if (instruction & INSTR_RRA)
		ft_printf("rra\n");
	if (instruction & INSTR_RRB)
		ft_printf("rrb\n");
	if (instruction & INSTR_RRR)
		ft_printf("rrr\n");
}

size_t					power_of_two_converter(size_t power)
{
	size_t				i;
	size_t				j;

	if (power == 1)
		return (0);
	i = 2;
	j = 1;
	while (i < power)
	{
		j += 1;
		i *= 2;
	}
	return (j);
}

void					ft_initialize_array(t_operation_func *oper_func)
{
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
}

void					ft_call_operations(t_instr *lst, t_prgm *prgm)
{
	t_instr				*temp;
	size_t				instr;
	t_operation_func	oper_func[11];

	ft_initialize_array(oper_func);
	temp = lst;
	while (temp != NULL)
	{
		instr = power_of_two_converter(temp->name);
		oper_func[instr](prgm);
		if (prgm->options & OPTION_V)
		{
			ft_checkinstruction(temp->name);
			ft_print_stacks(prgm->stacks);
		}
		temp = temp->next;
	}
}
