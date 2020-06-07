/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_prgm_functions.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/08 21:57:49 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/06/07 15:14:19 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void			prgm_initialize(t_prgm **prgm, size_t flag)
{
	*prgm = ft_memalloc(sizeof(t_prgm));
	(*prgm)->stacks = ft_memalloc(sizeof(t_stacks));
	(*prgm)->exec = flag;
}

/*
** Function that prints the usage if the option -u is given
** or in case other characters are given that are not valid
** to indicate the way to use the options
*/

static int		ft_print_usage(t_prgm *prgm, int flag)
{
	if (flag == ERROR)
		ft_printf("--- illegal option(s) were given\n");
	ft_printf("usage: ./program_name [-u | -vnc] [num1] [num2] [num3] ...\n");
	ft_printf("       program_name can be push_swap or checker\n");
	ft_printf("       -u : prints the usage\n");
	ft_printf("       -v : displays the stack's status after each operation\n");
	ft_printf("       -c : prints the stacks & last operation colored\n");
	ft_printf("       -n : displays the total number of operations\n");
	free(prgm->stacks);
	free(prgm);
	return (SUCCESS);
}

/*
** This function sets the prgm options which they can be
** [-u | -vnc]
** It will check the first argument if it starts with the
** minus sign and if the next character is an alphabet.
** If yes, it is an option so it has to be one of the options
** available otherwise it will print the illegal options msg,
** then the usage and then exit the program.
** If all options are valid and the -u is enabled it will print
** the usage and again exit the program.
** In all other cases the program will continue
*/

int				set_prgm_options(char *argv, t_prgm *prgm)
{
	size_t		i;

	i = 0;
	if (argv[i] == '-')
	{
		i += 1;
		while ((argv[i] != 0) && (ft_isalpha(argv[i]) == 1))
		{
			if (argv[i] == 'u')
				prgm->options |= OPTION_U;
			else if (argv[i] == 'v')
				prgm->options |= OPTION_V;
			else if (argv[i] == 'n')
				prgm->options |= OPTION_N;
			else if (argv[i] == 'c')
				prgm->options |= OPTION_C;
			else
				return (ft_print_usage(prgm, ERROR));
			i += 1;
		}
	}
	if (prgm->options & OPTION_U)
		return (ft_print_usage(prgm, SUCCESS));
	return (CONTINUE);
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
