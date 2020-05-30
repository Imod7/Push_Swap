/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_exit_prgm.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/31 18:57:55 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/05/30 16:07:53 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void			ft_free_stack_list(t_stack_list *stack_lst)
{
	t_stack_list	*curr_node;
	t_stack_list	*next_node;

	curr_node = stack_lst;
	while (curr_node != NULL)
	{
		next_node = curr_node->next;
		free(curr_node);
		curr_node = next_node;
	}
	stack_lst = NULL;
}

static void			ft_free_instr_list(t_instr *instr_lst)
{
	t_instr			*curr_node;
	t_instr			*next_node;

	curr_node = instr_lst;
	while (curr_node != NULL)
	{
		next_node = curr_node->next;
		free(curr_node);
		curr_node = next_node;
	}
	instr_lst = NULL;
}

int					ft_exitprogram(t_prgm *prgm, int argc)
{
	if ((prgm->options != 0) && (argc == 2))
	{
		free(prgm->stacks);
		free(prgm);
		return (0);
	}
	else if ((prgm->options & OPTION_N) && (argc != 2) && \
	(prgm->signal != ERROR))
	{
		ft_printf(ANSI_COLOR_YELLOW_PAST);
		ft_printf("Total number of operations %d\n", prgm->number_operations);
	}
	ft_free_stack_list(prgm->stacks->stacka_lst);
	ft_free_stack_list(prgm->stacks->stackb_lst);
	ft_free_stack_list(prgm->sorted_stack);
	free(prgm->stacks);
	ft_free_instr_list(prgm->instr_lst);
	free(prgm);
	return (0);
}
