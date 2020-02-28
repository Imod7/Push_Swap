/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_program_checks.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/24 14:49:58 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/02/24 14:50:37 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int					ft_exitprogram(int signal, t_stack_list **stacklst_ref)
{
	if (signal == -1)
	{
		ft_free_list(stacklst_ref);
		return (-1);
	}
	return (0);
}

int					check_v_option(char *argv, t_prgm_props *prgm_sets)
{
	if ((argv[0] == '-') && (argv[1] == 'v'))
		prgm_sets->debug_mode = 1;
	prgm_sets->number_operations = 0;
	return (0);
}
