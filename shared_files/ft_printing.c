/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printing.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/31 18:57:55 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/04/11 10:08:04 by dominique     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void				ft_print_stacks(t_stacks *stacks)
{
	t_stack_list	*temp_a;
	t_stack_list	*temp_b;

	ft_printf(ANSI_COLOR_CYAN"-----------------------------------------\t");
	ft_printf(ANSI_COLOR_CYAN"-----------------------------------------\n");
	ft_printf("|\t\tStack %c\t\t        |\t", stacks->stacka_id);
	ft_printf("|\t\tStack %c\t\t        |\n", stacks->stackb_id);
	ft_printf("-----------------------------------------");
	ft_printf("\t-----------------------------------------\n");
	temp_a = stacks->stacka_lst;
	temp_b = stacks->stackb_lst;
	while ((temp_a != NULL) || (temp_b != NULL))
	{
		if (temp_a != NULL)
		{
			ft_printf("|\t\t%-10d\t\t|\t", temp_a->num);
			temp_a = temp_a->next;
		}
		else
			ft_printf("|\t\t\t\t\t|\t");
		if (temp_b != NULL)
		{
			ft_printf("|\t\t%-10d\t\t|\t\n", temp_b->num);
			temp_b = temp_b->next;
		}
		else
			ft_printf("|\t\t\t\t\t|\n");
	}
	ft_printf("-----------------------------------------\t");
	ft_printf("-----------------------------------------\n"ANSI_COLOR_RESET);
}

void				ft_print_instructions(t_prgm *prgm)
{
	t_instr			*temp;

	// ft_printf("Printing the instructions \n");
	if (prgm->instr_lst == NULL)
		return ;
	temp = prgm->instr_lst;
	while (temp != NULL)
	{
		// ft_printf("num = %d\n", temp->instruction);
		if (temp->instruction & INSTR_SA)
			ft_printf("sa\n");
		if (temp->instruction & INSTR_SB)
			ft_printf("sb\n");
		if (temp->instruction & INSTR_SS)
			ft_printf("ss\n");
		if (temp->instruction & INSTR_PA)
			ft_printf("pa\n");
		if (temp->instruction & INSTR_PB)
			ft_printf("pb\n");
		if (temp->instruction & INSTR_RA)
			ft_printf("ra\n");
		if (temp->instruction & INSTR_RB)
			ft_printf("rb\n");
		if (temp->instruction & INSTR_RR)
			ft_printf("rr\n");
		if (temp->instruction & INSTR_RRA)
			ft_printf("rra\n");
		if (temp->instruction & INSTR_RRB)
			ft_printf("rrb\n");
		if (temp->instruction & INSTR_RRR)
			ft_printf("rrr\n");
		// if (prgm->options & OPTION_V)
		// 	ft_print_stacks(stacks);
		// (void)stacks;
		temp = temp->next;
	}
}

void				ft_print_doublyll(t_stack_list *temp)
{
	int				len;
	t_stack_list	*prevn;
	t_stack_list	*nextn;

	ft_printf(ANSI_COLOR_YELLOW"                      \n");
	ft_printf("|------------------------ Doubly Linked List -------------");
	ft_printf("------|\n");
	ft_printf("|prev\t\t\t\tcurrent \t\tnext----|\n");
	len = 0;
	if (temp == NULL)
		ft_printf("|\t\t\t\t\t\t\t|\n");
	while (temp != NULL)
	{
		len++;
		prevn = temp->prev;
		nextn = temp->next;
		if (prevn != NULL)
			ft_printf("|%d\t\t<-|\t", prevn->num);
		else
			ft_printf("NULL\t\t<-|\t");
		ft_printf("\t%-15d\t|->", temp->num);
		if (nextn != NULL)
			ft_printf("\t%d\t|\n", nextn->num);
		else
			ft_printf("\tNULL\t|\n");
		temp = temp->next;
	}
	ft_printf(ANSI_COLOR_YELLOW"|--------------------------------------------");
	ft_printf("-------------------|\n"ANSI_COLOR_RESET);
}

void				ft_print_doubly_all(t_stack_list *temp)
{
	int				len;
	t_stack_list	*prevn;
	t_stack_list	*nextn;

	ft_printf(ANSI_COLOR_CYAN);
	ft_printf("                      Doubly Linked List                    \n");
	ft_printf("----------------------------------------");
	ft_printf("---------------------------------------\n");
	ft_printf("|prev_num\tcurrent_num\tbucket\t\tdis_from_top\t\tnext_num|\n");
	len = 0;
	if (temp == NULL)
		ft_printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	while (temp != NULL)
	{
		len++;
		prevn = temp->prev;
		nextn = temp->next;
		if (prevn != NULL)
			ft_printf("|%d\t<-\t", prevn->num);
		else
			ft_printf("|NULL\t<-\t");
		ft_printf("%-15d\t", temp->num);
		ft_printf("%d\t\t", temp->bucket);
		ft_printf("%d\t", temp->dis_from_top);
		if (nextn != NULL)
			ft_printf("\t->\t%d\t|\n", nextn->num);
		else
			ft_printf("\t->\tNULL\t|\n");
		temp = temp->next;
	}
	ft_printf("--------------------------------------");
	ft_printf("------------------------------------------\n"ANSI_COLOR_RESET);
}
