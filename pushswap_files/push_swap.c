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
    // t_stack			*stack_a;
	// t_stack			*stack_b;
	t_stacks		*stacks;
	t_stack_list	*sorted_stack;
	// t_instr			*instr_lst;
	t_prgm			*prgm;

	stacks = ft_memalloc(sizeof(t_stacks));
	stacks->stacka_lst = NULL;
	sorted_stack = ft_memalloc(sizeof(t_stack_list));
	// stacks->stackb_lst = ft_memalloc(sizeof(t_stack));
	prgm = ft_memalloc(sizeof(t_prgm));
	prgm->instr_lst = NULL;
	if (argc < 2)
		return (0);
	else
	{
		check_v_option(argv[1], prgm);
		// ft_printf("debug_mode = %d \n", prgm->debug_mode);
		// print_binary(prgm->debug_mode);
		if (ft_build_stacka(argc, argv, &stacks, prgm) == -1)
			return (ft_exitprogram(&(stacks->stacka_lst)));
	}
	ft_build_stackb(&stacks);
	ft_print_stacks(stacks);
	// ft_print_instructions(instr_lst);
	ft_printf(ANSI_COLOR_MAGENTA"\nBEFORE OPERATIONS"ANSI_COLOR_RESET);
	ft_print_doublyll(stacks->stacka_lst);
	ft_print_doublyll(stacks->stackb_lst);
	if (ft_stack_length(stacks->stacka_lst) == 3)
		ft_sort_three(&stacks);
	ft_presort(&stacks, &sorted_stack);
	// ft_sorting(prgm, &stacks);
	// ft_call_instructfunctions(instr_lst, &stack_a, &stack_b, prgm);
	ft_printf(ANSI_COLOR_MAGENTA"\n============ AFTER OPERATIONS ============"ANSI_COLOR_RESET);
	ft_printf("\nStack A");
	ft_print_doublyll(stacks->stacka_lst);
	ft_printf("Stack B");
	ft_print_doublyll(stacks->stackb_lst);
	ft_printf("Stack C (copy) Sorted");
	ft_print_doublyll(sorted_stack);
	ft_print_stacks(stacks);
	// ft_call_instructfunctions(instr_lst, &(stack_a->stack_lst), &(stack_b->stack_lst));
	ft_printf(ANSI_COLOR_YELLOW"Number of Operations = %d\n"ANSI_COLOR_RESET, prgm->number_operations);
	ft_free_list(&(stacks->stacka_lst));
	ft_free_list(&(stacks->stackb_lst));
	ft_free_list(&sorted_stack);
	// free(stack_a);
	// free(stack_b);
	// free(prgm);
	// while (1)
	// 	;
	return (0);
}
