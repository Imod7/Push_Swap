/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/24 13:49:21 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/05/29 15:26:57 by dominique     ########   odam.nl         */
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
	if ((prgm->stacka_len <= 10) && (ft_check_ifsorted(prgm) == -1))
		ft_sort_small(prgm);
	else
	{
		if (ft_check_ifsorted(prgm) == -1)
			ft_algorithm(prgm);
	}
}

int				main(int argc, char **argv)
{
	t_prgm		*prgm;

	prgm = ft_memalloc(sizeof(t_prgm));
	prgm_initialize(prgm, 1);
	if (argc < 2)
		return (0);
	else
	{
		if (set_prgm_options(argv[1], prgm) == -1)
			return (0);
		if (ft_build_stacks(argc, argv, prgm) == -1)
			return (ft_exitprogram(prgm, argc));
	}
	ft_sorting_prep_calls(prgm);
	ft_print_instructions(prgm);
	ft_exitprogram(prgm, argc);
	return (0);
}
