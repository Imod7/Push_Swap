/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_set_colors.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/30 15:15:33 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/05/30 17:39:02 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void				ft_set_color_when_revrotating(t_prgm *prgm, char *operation)
{
	if (!ft_strcmp(operation, "rrr"))
	{
		if (prgm->stacka_len > 1)
			prgm->stacks->stacka_lst->colored = 1;
		if (prgm->stackb_len > 1)
			prgm->stacks->stackb_lst->colored = 1;
	}
}

void				ft_set_color_when_rotating(t_prgm *prgm, char *operation)
{
	t_stack_list	*temp;

	if (!ft_strcmp(operation, "rr"))
	{
		if (prgm->stacka_len > 1)
		{
			temp = prgm->stacks->stacka_lst;
			while (temp->next != NULL)
				temp = temp->next;
			temp->colored = 1;
		}
		if (prgm->stackb_len > 1)
		{
			temp = prgm->stacks->stackb_lst;
			while (temp->next != NULL)
				temp = temp->next;
			temp->colored = 1;
		}
	}
}

void				ft_set_color_stack_a(t_prgm *prgm, char *operation)
{
	t_stack_list	*temp;

	if (prgm->stacka_len > 1)
	{
		if (!ft_strcmp(operation, "sa"))
			prgm->stacks->stacka_lst->next->colored = 1;
		if (!ft_strcmp(operation, "ra"))
		{
			temp = prgm->stacks->stacka_lst;
			while (temp->next != NULL)
				temp = temp->next;
			temp->colored = 1;
		}
	}
	if ((prgm->stacka_len > 0) && \
	((!ft_strcmp(operation, "pa")) || (!ft_strcmp(operation, "rra"))))
		prgm->stacks->stacka_lst->colored = 1;
}

void				ft_set_color_stack_b(t_prgm *prgm, char *operation)
{
	t_stack_list	*temp;

	if (prgm->stackb_len > 1)
	{
		if (!ft_strcmp(operation, "sb"))
			prgm->stacks->stackb_lst->next->colored = 1;
		if (!ft_strcmp(operation, "rb"))
		{
			temp = prgm->stacks->stackb_lst;
			while (temp->next != NULL)
				temp = temp->next;
			temp->colored = 1;
		}
	}
	if ((prgm->stackb_len > 0) && (prgm->stacka_len > 0) && \
	((!ft_strcmp(operation, "pb")) || (!ft_strcmp(operation, "rrb"))))
		prgm->stacks->stackb_lst->colored = 1;
}

void				ft_set_color_moving_num(t_prgm *prgm, char *operation)
{
	ft_set_color_stack_a(prgm, operation);
	ft_set_color_stack_b(prgm, operation);
	ft_set_color_when_rotating(prgm, operation);
	ft_set_color_when_revrotating(prgm, operation);
	if (!ft_strcmp(operation, "ss"))
	{
		if (prgm->stacka_len > 1)
			prgm->stacks->stacka_lst->next->colored = 1;
		if (prgm->stackb_len > 1)
			prgm->stacks->stackb_lst->next->colored = 1;
	}
}
