/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_prgm_functions.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/08 21:57:49 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/05/30 16:03:54 by dsaripap      ########   odam.nl         */
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

int				print_usage(t_prgm *prgm)
{
	prgm->options |= OPTION_U;
	ft_printf("usage: ./program_name [-u | -vnc] [num1] [num2] [num3] ...\n");
	ft_printf("program_name can be push_swap or checker\n");
	return (ERROR);
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
			if (argv[i] == 'n')
				prgm->options |= OPTION_N;
			if (argv[i] == 'c')
				prgm->options |= OPTION_C;
			i += 1;
		}
	}
	prgm->number_operations = 0;
	return (SUCCESS);
}

int				check_prgm_options(t_prgm *prgm, int argc)
{
	int			i;

	i = 0;
	if (prgm->options != 0)
		i = 1;
	if ((prgm->options != 0) && (argc == 2))
		return (ERROR);
	return (i);
}

int				ft_exit_msg(t_prgm *prgm, size_t flag)
{
	if (flag == 0)
	{
		write(2, "Error\n", 6);
		prgm->signal = ERROR;
		return (ERROR);
	}
	if (flag == 1)
	{
		(prgm->exec == 0) ? ft_printf("KO\n") : (void)prgm;
		prgm->signal = KO;
		return (KO);
	}
	return (SUCCESS);
}
