/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_checkinput.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 11:54:51 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/02/06 11:54:54 by dsaripap      ########   odam.nl         */
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

int					ft_build_stackb(t_stack **stack_b)
{
	// (*stack_b) = NULL;
	// (*stack_b) = ft_memalloc(sizeof(t_stack));
	(*stack_b)->stack_id = 'B';
	ft_print_stack(*stack_b);
	return (0);
}

int					ft_build_stacka(int argc, char **argv, t_stack	**stack_a)
{
	int				i;
	int				num;
	int				num_len;
	t_stack_list	*stack_node;

	stack_node = NULL;
	(*stack_a) = ft_memalloc(sizeof(t_stack));
	i = 1;
	while (i < argc)
	{
		num_len = ft_strlen(argv[i]);
		// ft_printf("str_len = %d, string = %s --> ", num_len, argv[i]);
		num = ft_atoi(argv[i]);
		if (((num == 0) && ((num_len != 1) || (ft_strcmp(argv[i], "0") != 0))) \
		|| (ft_isnum(argv[i]) == -1))
		{
			ft_printf(ANSI_COLOR_RED"Error\n"ANSI_COLOR_RESET);
			return (-1);
		}
		else
		{
			// ft_printf(ANSI_COLOR_GREEN"VALID %d\n"ANSI_COLOR_RESET, num);
			stack_node = ft_stack_newnode(num);
			if (ft_numexists((*stack_a)->stack_lst, num) == 1)
			{
				ft_printf(ANSI_COLOR_RED"Error\n"ANSI_COLOR_RESET);
				return (-1);
			}
			ft_stack_addend(&(*stack_a)->stack_lst, stack_node);
		}
		i++;
	}
	(*stack_a)->stack_id = 'A';
	// ft_print_stack((*stack_a)->stack_lst);
	ft_print_stack(*stack_a);
	return (0);
}
