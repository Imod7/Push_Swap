/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_call_instructions.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/24 14:53:52 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/05/29 15:27:33 by dominique     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void					ft_checkinstruction(size_t instruction, \
												char **oper)
{
	if (instruction & INSTR_SA)
		*oper = "sa";
	if (instruction & INSTR_SB)
		*oper = "sb";
	if (instruction & INSTR_SS)
		*oper = "ss";
	if (instruction & INSTR_PA)
		*oper = "pa";
	if (instruction & INSTR_PB)
		*oper = "pb";
	if (instruction & INSTR_RA)
		*oper = "ra";
	if (instruction & INSTR_RB)
		*oper = "rb";
	if (instruction & INSTR_RR)
		*oper = "rr";
	if (instruction & INSTR_RRA)
		*oper = "rra";
	if (instruction & INSTR_RRB)
		*oper = "rrb";
	if (instruction & INSTR_RRR)
		*oper = "rrr";
	ft_printf("%s\n", *oper);
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
	char				*oper;

	ft_initialize_array(oper_func);
	temp = lst;
	while (temp != NULL)
	{
		instr = power_of_two_converter(temp->name);
		oper_func[instr](prgm);
		if (prgm->options & OPTION_V)
		{
			if (prgm->options & OPTION_C)
				ft_printf(ANSI_COLOR_GREEN_EMER);
			ft_checkinstruction(temp->name, &oper);
			ft_printf(ANSI_COLOR_RESET);
			ft_print_stacks(prgm, oper);
		}
		temp = temp->next;
	}
}
