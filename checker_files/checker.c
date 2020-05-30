/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 12:08:15 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/05/29 12:04:57 by dominique     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			read_input(t_prgm *prgm)
{
	int		i;
	char	*returned_line;

	i = 1;
	while (i > 0)
	{
		i = get_next_line(0, &returned_line);
		if (i != 0)
		{
			if (ft_saveinstructions(prgm, returned_line) == -1)
			{
				free(returned_line);
				return (-1);
			}
		}
		free(returned_line);
	}
	return (0);
}

int			main(int argc, char **argv)
{
	t_prgm	*prgm;

	prgm = ft_memalloc(sizeof(t_prgm));
	prgm_initialize(prgm, 0);
	if (argc < 2)
		return (0);
	else
	{
		if (set_prgm_options(argv[1], prgm) == -1)
			return (0);
		if (ft_build_stacks(argc, argv, prgm) == -1)
			return (ft_exitprogram(prgm, argc));
	}
	if (read_input(prgm) == -1)
		return (ft_exitprogram(prgm, argc));
	// ft_printf("numbers : %d\n", prgm->total_numbers);
	prgm->sorted_stack = ft_copy_list(prgm->stacks->stacka_lst);
	ft_presort(&(prgm->sorted_stack));
	ft_call_operations(prgm->instr_lst, prgm);
	if (ft_check_ifsorted(prgm) == -1)
		return (ft_exitprogram(prgm, argc));
	ft_exitprogram(prgm, argc);
	return (0);
}
