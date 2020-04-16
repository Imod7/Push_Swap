/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_prgm_functions.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/08 21:57:49 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/04/16 22:47:44 by dominique     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void			prgm_initialize(t_prgm *prgm, size_t flag)
{
	prgm->stacks = ft_memalloc(sizeof(t_stacks));
	prgm->stacks->stacka_lst = NULL;
	prgm->instr_lst = NULL;
	prgm->exec = flag;
}

int				ft_exitprogram(t_prgm *prgm)
{
	if (prgm->options & OPTION_N)
	{
		ft_printf(ANSI_COLOR_YELLOW);
		ft_printf("Total number of operations %d\n", prgm->number_operations);
	}
	ft_free_list(prgm->stacks->stacka_lst);
	ft_free_list(prgm->stacks->stackb_lst);
	ft_free_list(prgm->sorted_stack);
	free(prgm->stacks);
	free(prgm);
	return (0);
}

int				print_usage(t_prgm *prgm)
{
	prgm->options |= OPTION_U;
	ft_printf("usage: ./program_name [-u | -vcnf] [num1] [num2] [num3] ...\n");
	ft_printf("program_name can be push_swap or checker\n");
	return (-1);
}

int				set_prgm_options(char *argv, t_prgm *prgm)
{
	size_t		i;

	i = 0;
	if (argv[i] == '-')
	{
		i += 1;
		while (argv[i] != 0)
		{
			if (argv[i] == 'u')
				return (print_usage(prgm));
			if (argv[i] == 'v')
				prgm->options |= OPTION_V;
			if (argv[i] == 'c')
				prgm->options |= OPTION_C;
			if (argv[i] == 'n')
				prgm->options |= OPTION_N;
			if (argv[i] == 'f')
				prgm->options |= OPTION_F;
			i += 1;
		}
	}
	prgm->number_operations = 0;
	return (0);
}

size_t			check_prgm_options(t_prgm *prgm)
{
	size_t		i;

	i = 0;
	if (prgm->options != 0)
		i = 1;
	return (i);
}
