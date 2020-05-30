/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_stacks.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/31 18:57:55 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/05/30 15:24:51 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void				ft_print_stack_numbers(t_prgm *prgm, t_stack_list **temp)
{
	if (*temp != NULL)
	{
		ft_printf("|\t\t");
		if ((prgm->options & OPTION_C) && ((*temp)->colored == 1))
		{
			ft_printf(ANSI_COLOR_GREEN_EMER);
			(*temp)->colored = 0;
		}
		ft_printf("%-10d", (*temp)->num);
		if (prgm->options & OPTION_C)
			ft_printf(ANSI_COLOR_BLUE);
		ft_printf("\t\t|\t");
		*temp = (*temp)->next;
	}
	else
		ft_printf("|\t\t\t\t\t|\t");
}

void				ft_print_stacks(t_prgm *prgm, char *operation)
{
	t_stack_list	*temp_a;
	t_stack_list	*temp_b;

	if (prgm->options & OPTION_C)
		ft_set_color_moving_num(prgm, operation);
	ft_print_borders(prgm, 1, prgm->stacks->stacka_id, prgm->stacks->stackb_id);
	temp_a = prgm->stacks->stacka_lst;
	temp_b = prgm->stacks->stackb_lst;
	while ((temp_a != NULL) || (temp_b != NULL))
	{
		ft_print_stack_numbers(prgm, &temp_a);
		ft_print_stack_numbers(prgm, &temp_b);
		ft_printf("\n");
	}
	ft_printf("-----------------------------------------\t");
	ft_printf("-----------------------------------------\n"ANSI_COLOR_RESET);
}
