/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_save_input.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/24 14:55:25 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/06/07 15:11:26 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int			ft_saving_arguments(int argc, char **argv, t_prgm *prgm, \
										int i)
{
	long long		num;
	t_stack_list	*stack_node;

	stack_node = NULL;
	prgm->total_numbers = 0;
	while (i < argc)
	{
		if (ft_check_str_length(argv[i]) == ERROR)
			return (ft_exit_msg(prgm, 0));
		num = ft_atoll(argv[i]);
		if (ft_isvalid(argv[i], num) == -1)
			return (ft_exit_msg(prgm, 0));
		else
		{
			if (ft_numexists_instack(prgm->stacks->stacka_lst, num) == 1)
				return (ft_exit_msg(prgm, 0));
			stack_node = ft_stack_newnode(num);
			ft_stack_addend(&(prgm->stacks)->stacka_lst, stack_node);
		}
		prgm->total_numbers += 1;
		i++;
	}
	prgm->stacka_len = ft_stack_len(prgm->stacks->stacka_lst);
	return (SUCCESS);
}

int					ft_build_stacks(int argc, char **argv, t_prgm *prgm)
{
	int				i;

	i = 0;
	if (check_prgm_options(prgm, argc) == ERROR)
		return (ERROR);
	else
		i = 1 + check_prgm_options(prgm, argc);
	if (ft_saving_arguments(argc, argv, prgm, i) == -1)
		return (ERROR);
	prgm->stacks->stacka_id = 'A';
	prgm->stacks->stackb_id = 'B';
	return (SUCCESS);
}
