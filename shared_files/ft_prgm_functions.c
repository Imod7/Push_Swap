/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_prgm_functions.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/08 21:57:49 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/05/26 10:59:06 by dominique     ########   odam.nl         */
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

int				ft_exit_msg(t_prgm *prgm, size_t flag)
{
	if (flag == 0)
		write(2, "Error\n", 6);
	if (flag == 1)
		(prgm->exec == 0) ? ft_printf("KO\n") : (void)prgm;
	return (-1);
}
