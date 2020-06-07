/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/24 13:49:21 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/06/07 12:21:57 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** This function does all the preparation calls before
** calling the main sorting algorithm. These calls include
** a. building the sorted stack, b. calculating the buckets to
** be used and c. check which algorithm to call based on the
** amount of numbers
*/

static void		ft_sorting_prep_calls(t_prgm *prgm)
{
	ft_calculate_buckets(prgm);
	prgm->sorted_stack = ft_copy_list(prgm->stacks->stacka_lst);
	ft_presort(&(prgm->sorted_stack));
	ft_update_buckets(prgm);
	ft_metrics_calculation(prgm, 1);
	prgm->stacka_len = ft_stack_len(prgm->stacks->stacka_lst);
	if ((prgm->stacka_len <= 10) && (ft_check_ifsorted(prgm) != SUCCESS))
		ft_sort_small(prgm);
	else
	{
		if (ft_check_ifsorted(prgm) != SUCCESS)
			ft_algorithm(prgm);
	}
}

int				main(int argc, char **argv)
{
	t_prgm		*prgm;

	if (argc < 2)
		return (SUCCESS);
	prgm_initialize(&prgm, 1);
	if (set_prgm_options(argv[1], prgm) != CONTINUE)
		return (SUCCESS);
	if (ft_build_stacks(argc, argv, prgm) == ERROR)
		return (ft_exitprogram(prgm, argc));
	ft_sorting_prep_calls(prgm);
	ft_print_instructions(prgm);
	ft_exitprogram(prgm, argc);
	return (SUCCESS);
	while (1)
		;
}
