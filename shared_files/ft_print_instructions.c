/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_instructions.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dominique <dominique@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/30 07:42:58 by dominique     #+#    #+#                 */
/*   Updated: 2020/04/30 12:14:41 by dominique     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void			ft_print_instruct_rotates(t_instr *instr)
{
	if (instr->name & INSTR_RA)
		ft_printf("ra\n");
	if (instr->name & INSTR_RB)
		ft_printf("rb\n");
	if (instr->name & INSTR_RR)
		ft_printf("rr\n");
	if (instr->name & INSTR_RRA)
		ft_printf("rra\n");
	if (instr->name & INSTR_RRB)
		ft_printf("rrb\n");
	if (instr->name & INSTR_RRR)
		ft_printf("rrr\n");
}

void				ft_print_instructions(t_prgm *prgm)
{
	t_instr			*instr;

	if (prgm->instr_lst == NULL)
		return ;
	instr = prgm->instr_lst;
	while (instr != NULL)
	{
		if (instr->name & INSTR_SA)
			ft_printf("sa\n");
		if (instr->name & INSTR_SB)
			ft_printf("sb\n");
		if (instr->name & INSTR_SS)
			ft_printf("ss\n");
		if (instr->name & INSTR_PA)
			ft_printf("pa\n");
		if (instr->name & INSTR_PB)
			ft_printf("pb\n");
		ft_print_instruct_rotates(instr);
		instr = instr->next;
	}
}

void				ft_print_doublyll_instr(t_instr *temp)
{
	t_instr			*prevn;
	t_instr			*nextn;

	ft_print_borders(2, '/', '/');
	if (temp == NULL)
		ft_printf("|\t\t\t\t\t\t\t\t|\n");
	while (temp != NULL)
	{
		prevn = temp->prev;
		nextn = temp->next;
		if (prevn != NULL)
			ft_printf("|%d\t\t|\t", prevn->name);
		else
			ft_printf("NULL\t\t|\t");
		ft_printf("\t%-15d\t|", temp->name);
		if (nextn != NULL)
			ft_printf("\t%d\t|\n", nextn->name);
		else
			ft_printf("\tNULL\t|\n");
		temp = temp->next;
	}
	ft_printf("--------------------------------------------");
	ft_printf("--------------------\n"ANSI_COLOR_RESET);
}
