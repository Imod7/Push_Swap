/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_optmz_instructions.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/30 15:14:56 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/05/30 15:14:58 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int			ft_merge_operations(t_instr *instr_lst, t_instr *new, \
										char **operation, char *oper)
{
	if (!ft_strcmp(oper, "rr"))
	{
		instr_lst = instr_lst->next;
		instr_lst->name = 0;
		instr_lst->name |= INSTR_RR;
	}
	else if (!ft_strcmp(oper, "rrr"))
	{
		instr_lst = instr_lst->next;
		instr_lst->name = 0;
		instr_lst->name |= INSTR_RRR;
	}
	else if (!ft_strcmp(oper, "ss"))
	{
		while ((instr_lst->prev != NULL) && (((instr_lst->name & INSTR_SA) && \
		(new->name & INSTR_SB)) || ((instr_lst->name & INSTR_SB) && \
		(new->name & INSTR_SA))))
			instr_lst = instr_lst->prev;
		instr_lst->name = 0;
		instr_lst->name |= INSTR_SS;
	}
	*operation = oper;
	free(new);
	return (1);
}

static int			ft_instr_optimize(t_instr *instr, t_instr *new, \
											char **operation)
{
	if (((instr->name & INSTR_RA) && (new->name & INSTR_RB)) \
	|| ((instr->name & INSTR_RB) && (new->name & INSTR_RA)))
	{
		while ((instr->prev != NULL) && (((instr->name & INSTR_RA) && \
		(new->name & INSTR_RB)) || ((instr->name & INSTR_RB) && \
		(new->name & INSTR_RA))))
			instr = instr->prev;
		return (ft_merge_operations(instr, new, operation, "rr"));
	}
	else if (((instr->name & INSTR_RRA) && (new->name & INSTR_RRB)) || \
	((instr->name & INSTR_RRB) && (new->name & INSTR_RRA)))
	{
		while ((instr->prev != NULL) && (((instr->name & INSTR_RRA) && \
		(new->name & INSTR_RRB)) || ((instr->name & INSTR_RRB) && \
		(new->name & INSTR_RRA))))
			instr = instr->prev;
		return (ft_merge_operations(instr, new, operation, "rrr"));
	}
	else if (((instr->name & INSTR_SA) && (new->name & INSTR_SB)) || \
	((instr->name & INSTR_SB) && (new->name & INSTR_SA)))
		return (ft_merge_operations(instr, new, operation, "ss"));
	return (0);
}

int					ft_instr_add_or_optmz(t_prgm *prgm, t_instr *new, \
									char **operation)
{
	t_instr			*temp;

	if (prgm->instr_lst == NULL)
	{
		prgm->instr_lst = new;
		new->prev = NULL;
		prgm->number_operations += 1;
		return (0);
	}
	temp = prgm->instr_lst;
	while (temp->next != NULL)
		temp = temp->next;
	if ((prgm->exec == 1) && (ft_instr_optimize(temp, new, operation) == 1))
		return (1);
	else
	{
		temp->next = new;
		prgm->number_operations += 1;
		new->prev = temp;
	}
	return (0);
}
