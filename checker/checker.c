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

int		ft_exitprogram(int signal, t_stack **stack_lst)
{
	if (signal == -1)
	{
		ft_free_list(stack_lst);
		return (-1);
	}
	return (0);
}

int			main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_instr	*instr_lst;
	char	operation[BUFFER_SIZE + 1];

	stack_a = NULL;
	stack_b = NULL;
	instr_lst = NULL;
	if (argc < 2)
		return (0);
	else
	{
		if (ft_checkargs(argc, argv, &stack_a) == -1)
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
	ft_call_instructfunctions(instr_lst, stack_a, stack_b);
	return (0);
}
