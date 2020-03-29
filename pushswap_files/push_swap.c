/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/24 13:49:21 by dsaripap       #+#    #+#                */
/*   Updated: 2020/03/29 21:22:19 by dominique     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int     main(int argc, char **argv)
{
	t_stacks		*stacks;
	t_prgm			*prgm;
	int				len;

	stacks = ft_memalloc(sizeof(t_stacks));
	stacks->stacka_lst = NULL;
	// prgm->sorted_stack = ft_memalloc(sizeof(t_stack_list));
	prgm = ft_memalloc(sizeof(t_prgm));
	prgm->instr_lst = NULL;
	prgm->exec = 1;
	if (argc < 2)
		return (0);
	else
	{
		if (set_prgm_options(argv[1], prgm) == -1)
			return (0);
		// print_binary(prgm->debug_mode);
		if (ft_build_stacka(argc, argv, &stacks, prgm) == -1)
			return (ft_exitprogram(&(stacks->stacka_lst)));
	}
	ft_build_stackb(&stacks);
	len = ft_stack_length(stacks->stacka_lst);
	if (len <= 3)
		return(ft_sort_small(prgm, &stacks, len));
	else
	{
		ft_calculate_buckets(prgm, len);
		// ft_printf("Buckets = %d \n", prgm->buckets);
		// ft_printf("Bucket Size = %d \n", prgm->bucket_size);
		ft_presort(prgm, &stacks);
		ft_update_buckets(&prgm);
		ft_metrics_calculation(prgm, &stacks, 1);
		ft_algorithm(prgm, &stacks);
	}
	// ft_sorting(prgm, &stacks);
	// ft_call_operations(instr_lst, &stack_a, &stack_b, prgm);
	// ft_printf("Stack A");
	// ft_print_doublyll(stacks->stacka_lst);
	// ft_printf("Stack B");
	// ft_print_doublyll(stacks->stackb_lst);
	// ft_printf("Stack C (copy) Sorted");
	// ft_print_doublyll(prgm->sorted_stack);
	// ft_print_stacks(stacks);
	// ft_printf(ANSI_COLOR_YELLOW"Number of Operations = %d\n"ANSI_COLOR_RESET, prgm->number_operations);
	// ft_print_instructions(prgm, stacks);
	if (prgm->options & OPTION_N)
		print_number_of_oper(prgm);
	ft_free_list(&(stacks->stacka_lst));
	ft_free_list(&(stacks->stackb_lst));
	ft_free_list(&(prgm->sorted_stack));
	// free(stack_a);
	// free(stack_b);
	// free(prgm);
	// while (1)
	// 	;
	return (0);
}
