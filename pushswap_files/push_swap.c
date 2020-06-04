/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/24 13:49:21 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/06/04 17:46:16 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	prgm = ft_memalloc(sizeof(t_prgm));
	prgm_initialize(prgm, 1);
	if (set_prgm_options(argv[1], prgm) == ERROR)
		return (ERROR);
	if (ft_build_stacks(argc, argv, prgm) == ERROR)
		return (ft_exitprogram(prgm, argc));
	ft_sorting_prep_calls(prgm);
	ft_print_instructions(prgm);
	ft_exitprogram(prgm, argc);
	return (SUCCESS);
	while (1)
		;
}
