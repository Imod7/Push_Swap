/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/24 13:49:21 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/02/24 13:49:24 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int     main(int argc, char **argv)
{
    t_stack			*stack_a;
	t_stack			*stack_b;
	t_stack			*sorted_stack;
	t_instr			*instr_lst;
	t_prgm_props	*prgm_settings;

	stack_a = NULL;
	sorted_stack = NULL;
	stack_b = ft_memalloc(sizeof(t_stack));
	prgm_settings = ft_memalloc(sizeof(t_prgm_props));
	instr_lst = NULL;
	if (argc < 2)
		return (0);
	else
	{
		check_v_option(argv[1], prgm_settings);
		// ft_printf("debug_mode = %d \n", prgm_settings->debug_mode);
		// print_binary(prgm_settings->debug_mode);
		if (ft_build_stacka(argc, argv, &stack_a, prgm_settings) == -1)
			return (ft_exitprogram(-1, &(stack_a->stack_lst)));
	}
	ft_build_stackb(&stack_b);
	// ft_print_instructions(instr_lst);
	ft_printf(ANSI_COLOR_MAGENTA"BEFORE OPERATIONS\n"ANSI_COLOR_RESET);
	ft_print_doublyll(stack_a->stack_lst);
	ft_print_doublyll(stack_b->stack_lst);
	sorted_stack = ft_presort(stack_a->stack_lst);
	// ft_sorting(prgm_settings, &stack_a, &stack_b);
	// ft_call_instructfunctions(instr_lst, &stack_a, &stack_b, prgm_settings);
	ft_printf(ANSI_COLOR_MAGENTA"AFTER OPERATIONS\n"ANSI_COLOR_RESET);
	ft_print_doublyll(stack_a->stack_lst);
	ft_print_doublyll(stack_b->stack_lst);
	// ft_call_instructfunctions(instr_lst, &(stack_a->stack_lst), &(stack_b->stack_lst));
	ft_printf(ANSI_COLOR_YELLOW"Number of Operations = %d\n"ANSI_COLOR_RESET, prgm_settings->number_operations);
	return (0);
}
