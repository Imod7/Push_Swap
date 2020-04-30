/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/24 13:49:21 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/04/30 16:48:10 by dominique     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		ft_sorting_process(t_prgm *prgm)
{
	prgm->stack_len = ft_stack_len(prgm->stacks->stacka_lst);
	ft_calculate_buckets(prgm);
	prgm->sorted_stack = ft_copy_list(prgm->stacks->stacka_lst);
	ft_presort(&(prgm->sorted_stack));
	ft_update_buckets(prgm);
	ft_metrics_calculation(prgm, 1);
	prgm->stack_len = ft_stack_len(prgm->stacks->stacka_lst);
	if (prgm->stack_len <= 10)
		ft_sort_small(prgm);
	else
	{
		if (ft_check_ifsorted(prgm) == -1)
			ft_algorithm(prgm);
	}
}

int			main(int argc, char **argv)
{
	t_prgm	*prgm;

	prgm = ft_memalloc(sizeof(t_prgm));
	prgm_initialize(prgm, 1);
	if (argc < 2)
		return (0);
	else
	{
		if (set_prgm_options(argv[1], prgm) == -1)
			return (0);
		if (ft_build_stacks(argc, argv, prgm) == -1)
			return (ft_exitprogram(prgm));
	}
	ft_sorting_process(prgm);
	ft_print_instructions(prgm);
	ft_exitprogram(prgm);
	return (0);
}
