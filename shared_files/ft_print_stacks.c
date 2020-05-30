/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_stacks.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/31 18:57:55 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/05/29 14:45:12 by dominique     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void				ft_print_borders(t_prgm *prgm, size_t flag, \
										char a, char b)
{
	if (prgm->options & OPTION_C)
		ft_printf(ANSI_COLOR_BLUE);
	if (flag == 1)
	{
		ft_printf("\t\tStack %c\t\t        \t", a);
		ft_printf("\t\tStack %c\t\t        \n", b);
		ft_printf("-----------------------------------------");
		ft_printf("\t-----------------------------------------\n");
	}
	if (flag == 2)
	{
		ft_printf("                      \n");
		ft_printf("                          Doubly Linked List            \n");
		ft_printf("---------------------------------");
		ft_printf("--------------------------------\n");
		ft_printf("|prev\t\t\t\tcurrent \t\tnext\t|\n");
	}
	if (flag == 3)
	{
		ft_printf("\n                    Doubly Linked List                \n");
		ft_printf("----------------------------------------");
		ft_printf("----------------------------------------\n");
		ft_printf("|prev_num\tcurrent_num\tbucket\tdis_from_top\tpos_index");
		ft_printf("\tnext_num|\n");
	}
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
		if (temp_a != NULL)
		{
			ft_printf("|\t\t");
			if ((prgm->options & OPTION_C) && (temp_a->colored == 1))
			{
				ft_printf(ANSI_COLOR_GREEN_EMER);
				temp_a->colored = 0;
			}
			ft_printf("%-10d", temp_a->num);
			if (prgm->options & OPTION_C)
				ft_printf(ANSI_COLOR_BLUE);
			ft_printf("\t\t|\t");
			temp_a = temp_a->next;
		}
		else
			ft_printf("|\t\t\t\t\t|\t");
		if (temp_b != NULL)
		{
			ft_printf("|\t\t");
			if ((prgm->options & OPTION_C) && (temp_b->colored == 1))
			{
				ft_printf(ANSI_COLOR_GREEN_EMER);
				temp_b->colored = 0;
			}
			ft_printf("%-10d", temp_b->num);
			if (prgm->options & OPTION_C)
				ft_printf(ANSI_COLOR_BLUE);
			ft_printf("\t\t|\t\n");
			// ft_printf("|\t\t%-10d\t\t|\t\n", temp_b->num);
			temp_b = temp_b->next;
		}
		else
			ft_printf("|\t\t\t\t\t|\n");
	}
	ft_printf("-----------------------------------------\t");
	ft_printf("-----------------------------------------\n"ANSI_COLOR_RESET);
	// ft_printf("after printing \n");
	// ft_printf("Stack A size : %d \n", prgm->stacka_len);
	// ft_printf("Stack B size : %d \n", prgm->stackb_len);
}

void				ft_print_doublyll(t_prgm *prgm, t_stack_list *temp)
{
	t_stack_list	*prevn;
	t_stack_list	*nextn;

	ft_print_borders(prgm, 2, '/', '/');
	if (temp == NULL)
		ft_printf("|\t\t\t\t\t\t\t\t|\n");
	while (temp != NULL)
	{
		prevn = temp->prev;
		nextn = temp->next;
		if (prevn != NULL)
			ft_printf("|%d\t\t|\t", prevn->num);
		else
			ft_printf("NULL\t\t|\t");
		ft_printf("\t%-15d\t|", temp->num);
		if (nextn != NULL)
			ft_printf("\t%d\t|\n", nextn->num);
		else
			ft_printf("\tNULL\t|\n");
		temp = temp->next;
	}
	ft_printf("--------------------------------------------");
	ft_printf("--------------------\n"ANSI_COLOR_RESET);
}

void				ft_print_doubly_all(t_prgm *prgm, t_stack_list *temp)
{
	t_stack_list	*prevn;
	t_stack_list	*nextn;

	ft_print_borders(prgm, 3, '/', '/');
	if (temp == NULL)
		ft_printf("|\t\t\t\t\t\t\t\t\t\t|\n");
	while (temp != NULL)
	{
		prevn = temp->prev;
		nextn = temp->next;
		if (prevn != NULL)
			ft_printf("|%d\t\t", prevn->num);
		else
			ft_printf("|NULL\t\t");
		ft_printf("%-15d\t%d\t", temp->num, temp->bucket);
		ft_printf("%d\t\t%d\t", temp->dis_from_top, temp->pos_index);
		if (nextn != NULL)
			ft_printf("\t%d\t|\n", nextn->num);
		else
			ft_printf("\tNULL\t|\n");
		temp = temp->next;
	}
	ft_printf("--------------------------------------");
	ft_printf("------------------------------------------\n"ANSI_COLOR_RESET);
}

void				print_binary(int instr)
{
	unsigned short	mask;
	int				bit;

	bit = 16;
	while (bit >= 0)
	{
		mask = instr >> bit;
		if (mask & 1)
		{
			ft_printf(ANSI_COLOR_CYAN);
			ft_printf("1 ");
			ft_printf(ANSI_COLOR_RESET);
		}
		else
			ft_printf("0 ");
		bit--;
	}
	ft_printf("\n");
}
