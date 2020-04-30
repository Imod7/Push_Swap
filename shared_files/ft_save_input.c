/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_save_input.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/24 14:55:25 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/04/30 17:31:03 by dominique     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int			ft_isnum(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] < 48 || str[i] > 57) && str[i] != '+' && str[i] != '-')
			return (-1);
		i++;
	}
	return (0);
}

static int			ft_isvalid(char *argv, long long num, int num_len)
{
	if (((num == 0) && ((num_len != 1) || (ft_strcmp(argv, "0") != 0))) \
	|| (ft_isnum(argv) == -1) || (num > 2147483647) || (num < -2147483648))
		return (-1);
	else
		return (0);
}

int					ft_build_stacks(int argc, char **argv, t_prgm *prgm)
{
	long long		num;
	int				num_len;
	int				i;
	t_stack_list	*stack_node;

	stack_node = NULL;
	i = 1 + check_prgm_options(prgm);
	while (i < argc)
	{
		num_len = ft_strlen(argv[i]);
		num = ft_atoll(argv[i]);
		if (ft_isvalid(argv[i], num, num_len) == -1)
			return (ft_exit_msg(prgm, 0));
		else
		{
			if (ft_numexists_instack(prgm->stacks->stacka_lst, num) == 1)
				return (ft_exit_msg(prgm, 0));
			stack_node = ft_stack_newnode(num);
			ft_stack_addend(&(prgm->stacks)->stacka_lst, stack_node);
		}
		i++;
	}
	prgm->stacks->stacka_id = 'A';
	prgm->stacks->stackb_id = 'B';
	return (0);
}
