/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_save_input.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/24 14:55:25 by dsaripap       #+#    #+#                */
/*   Updated: 2020/03/25 16:54:21 by dominique     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

// int			ft_biggerthanint(char *str)
// {
// 	long	num;
// }

int					ft_isnum(char *str)
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

int					ft_build_stackb(t_stacks **stacks)
{
	// (*stack_b) = NULL;
	// (*stacks)->stackb_lst = ft_memalloc(sizeof(t_stack));
	// (*stacks) = ft_memalloc(sizeof(t_stacks));
	(*stacks)->stackb_id = 'B';
	return (0);
}

int					ft_build_stacka(int argc, char **argv, t_stacks	**stacks, \
									t_prgm *prgm_sets)
{
	int				i;
	int				num;
	int				num_len;
	t_stack_list	*stack_node;

	stack_node = NULL;
	// (*stacks) = ft_memalloc(sizeof(t_stacks));
	// (*stacks)->stacka_lst = ft_memalloc(sizeof(t_stack_list));
	i = 1;
	if (prgm_sets->debug_mode == 1)
		i = 2;
	while (i < argc)
	{
		num_len = ft_strlen(argv[i]);
		num = ft_atoi(argv[i]);
		if (((num == 0) && ((num_len != 1) || (ft_strcmp(argv[i], "0") != 0))) \
		|| (ft_isnum(argv[i]) == -1))
		{
			ft_printf(ANSI_COLOR_RED"Error\n"ANSI_COLOR_RESET);
			return (-1);
		}
		else
		{
			stack_node = ft_stack_newnode(num);
			if (ft_numexists((*stacks)->stacka_lst, num) == 1)
			{
				ft_printf(ANSI_COLOR_RED"Error\n"ANSI_COLOR_RESET);
				return (-1);
			}
			ft_stack_addend(&(*stacks)->stacka_lst, stack_node);
		}
		i++;
	}
	(*stacks)->stacka_id = 'A';
	return (0);
}
