/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_freelist.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/31 18:57:55 by dsaripap       #+#    #+#                */
/*   Updated: 2020/03/21 16:53:45 by dominique     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void				ft_free_list(t_stack_list **stack_lst)
{
	t_stack_list	*curr_node;
	t_stack_list	*next_node;

	curr_node = *stack_lst;
	while (curr_node != NULL)
	{
		next_node = curr_node->next;
		free(curr_node);
		curr_node = next_node;
	}
	*stack_lst = NULL;
}

void				ft_print_instructions(t_prgm *prgm)
{
	t_instr			*temp;

	ft_printf("Printing the instructions \n");
	if (prgm->instr_lst == NULL)
		return ;
	temp = prgm->instr_lst;
	while (temp != NULL)
	{
		if (temp->instruction & INSTR_SA)
			ft_printf("sa\n");
		if (temp->instruction & INSTR_SB)
			ft_printf("sb\n");
		if (temp->instruction & INSTR_RA)
			ft_printf("ra\n");
		if (temp->instruction & INSTR_RB)
			ft_printf("rb\n");
		if (temp->instruction & INSTR_PA)
			ft_printf("pa\n");
		if (temp->instruction & INSTR_PB)
			ft_printf("pb\n");
		temp = temp->next;
	}
}