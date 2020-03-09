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

int					main(int argc, char **argv)
{
	// t_stack			*stack_a;
	// t_stack			*stack_b;
	t_stacks		*stacks;
	// t_instr			*instr_lst;
	t_prgm_props	*prgm_settings;
	char			operation[BUFFER_SIZE + 1];
	int				buffer_read;

	stacks = ft_memalloc(sizeof(t_stacks));
	stacks->stacka_lst = NULL;
	// stacks->stackb_lst = ft_memalloc(sizeof(t_stack_list));
	prgm_settings = ft_memalloc(sizeof(t_prgm_props));
	prgm_settings->instr_lst = NULL;
	if (argc < 2)
		return (0);
	else
	{
		check_v_option(argv[1], prgm_settings);
		// ft_printf("debug_mode = %d \n", prgm_settings->debug_mode);
		// print_binary(prgm_settings->debug_mode);
		if (ft_build_stacka(argc, argv, &stacks, prgm_settings) == -1)
			return (ft_exitprogram(&(stacks->stacka_lst)));
	}
	ft_build_stackb(&stacks);
	ft_bzero(operation, BUFFER_SIZE + 1);
	buffer_read = read(0, operation, BUFFER_SIZE);
	// while (ft_strcmp(operation, "\n") != 0)
	while (buffer_read != 0)
	{
		if (ft_saveinstructions(&prgm_settings->instr_lst, operation) == -1)
			return (ft_exitprogram(&(stacks->stacka_lst)));
		ft_bzero(operation, BUFFER_SIZE + 1);
		buffer_read = read(0, operation, BUFFER_SIZE);
	}
	// ft_print_instructions(instr_lst);
	ft_printf(ANSI_COLOR_MAGENTA"BEFORE OPERATIONS\n"ANSI_COLOR_RESET);
	ft_print_doublyll(stacks->stacka_lst);
	ft_print_doublyll(stacks->stackb_lst);
	ft_call_instructfunctions(prgm_settings->instr_lst, &stacks, prgm_settings);
	ft_printf(ANSI_COLOR_MAGENTA"AFTER OPERATIONS\n"ANSI_COLOR_RESET);
	ft_print_doublyll(stacks->stacka_lst);
	ft_print_doublyll(stacks->stackb_lst);
	// ft_call_instructfunctions(instr_lst, &(stack_a->stack_lst), &(stack_b->stack_lst));
	ft_exitprogram(&(stacks->stacka_lst));
	ft_exitprogram(&(stacks->stackb_lst));
	while (1)
		;
	return (0);
}
