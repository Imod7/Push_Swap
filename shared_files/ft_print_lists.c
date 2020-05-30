/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_lists.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/30 15:14:12 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/05/30 15:14:15 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void				ft_print_borders(t_prgm *prgm, size_t flag, \
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
