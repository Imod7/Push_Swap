/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_save_instructions.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/24 14:52:10 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/05/29 13:53:41 by dominique     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int					valid_instruction(char *str)
{
	if (str == NULL)
		return (0);
	if (!ft_strcmp(str, "sa") || !ft_strcmp(str, "sb") || \
	!ft_strcmp(str, "ss") || !ft_strcmp(str, "pa") || \
	!ft_strcmp(str, "pb") || !ft_strcmp(str, "ra") || \
	!ft_strcmp(str, "rb") || !ft_strcmp(str, "rr") || \
	!ft_strcmp(str, "rra") || !ft_strcmp(str, "rrb") || \
	!ft_strcmp(str, "rrr"))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

void				ft_setinstruction(char *operation, t_instr *instr)
{
	if (!ft_strcmp(operation, "sa"))
		instr->name |= INSTR_SA;
	else if (!ft_strcmp(operation, "sb"))
		instr->name |= INSTR_SB;
	else if (!ft_strcmp(operation, "ss"))
		instr->name |= INSTR_SS;
	else if (!ft_strcmp(operation, "pa"))
		instr->name |= INSTR_PA;
	else if (!ft_strcmp(operation, "pb"))
		instr->name |= INSTR_PB;
	else if (!ft_strcmp(operation, "ra"))
		instr->name |= INSTR_RA;
	else if (!ft_strcmp(operation, "rb"))
		instr->name |= INSTR_RB;
	else if (!ft_strcmp(operation, "rr"))
		instr->name |= INSTR_RR;
	else if (!ft_strcmp(operation, "rra"))
		instr->name |= INSTR_RRA;
	else if (!ft_strcmp(operation, "rrb"))
		instr->name |= INSTR_RRB;
	else if (!ft_strcmp(operation, "rrr"))
		instr->name |= INSTR_RRR;
	instr->next = NULL;
}

int					ft_saveinstructions(t_prgm *prgm, char *operation)
{
	t_instr			*instr_node;

	if (valid_instruction(operation) == 0)
		return (ft_exit_msg(prgm, 0));
	else
	{
		instr_node = (t_instr *)ft_memalloc(sizeof(t_instr));
		ft_setinstruction(operation, instr_node);
		ft_instr_add_or_optmz(prgm, instr_node, &operation);
		if ((prgm->options & OPTION_V) && (prgm->exec == 1))
		{
			if (prgm->options & OPTION_C)
				ft_printf(ANSI_COLOR_GREEN_EMER);
			ft_printf("%s\n", operation);
			ft_printf(ANSI_COLOR_RESET);
			ft_print_stacks(prgm, operation);
		}
	}
	return (0);
}
