/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_save_instructions.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/24 14:52:10 by dsaripap       #+#    #+#                */
/*   Updated: 2020/03/25 17:50:38 by dominique     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

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
		// ft_printf(ANSI_COLOR_GREEN"\n'%s'\n"ANSI_COLOR_RESET, str);
		return (1);
	}
	else
	{
		// ft_printf(ANSI_COLOR_RED"\n'%s'\n"ANSI_COLOR_RESET, str);
		return (0);
	}
}

void				ft_setinstruction(char *operation, t_instr *instr)
{
	if (!ft_strcmp(operation, "sa"))
		instr->instruction |= INSTR_SA;
	else if (!ft_strcmp(operation, "sb"))
		instr->instruction |= INSTR_SB;
	else if (!ft_strcmp(operation, "ss"))
		instr->instruction |= INSTR_SS;
	else if (!ft_strcmp(operation, "pa"))
		instr->instruction |= INSTR_PA;
	else if (!ft_strcmp(operation, "pb"))
		instr->instruction |= INSTR_PB;
	else if (!ft_strcmp(operation, "ra"))
		instr->instruction |= INSTR_RA;
	else if (!ft_strcmp(operation, "rb"))
		instr->instruction |= INSTR_RB;
	else if (!ft_strcmp(operation, "rr"))
		instr->instruction |= INSTR_RR;
	else if (!ft_strcmp(operation, "rra"))
		instr->instruction |= INSTR_RRA;
	else if (!ft_strcmp(operation, "rrb"))
		instr->instruction |= INSTR_RRB;
	else if (!ft_strcmp(operation, "rrr"))
		instr->instruction |= INSTR_RRR;
	instr->next = NULL;
}

void				ft_instr_addend(t_prgm **prgm, t_instr *new)
{
	t_instr			*temp;

	if ((*prgm)->instr_lst == NULL)
	{
		(*prgm)->instr_lst = new;
		// ft_printf(ANSI_COLOR_GREEN"NULL SO ADD : instr='%d'\n"ANSI_COLOR_RESET, (*prgm)->instr_lst->instruction);
		return ;
	}
	temp = (*prgm)->instr_lst;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = new;
}

int					ft_saveinstructions(t_prgm *prgm, char *operation)
{
	// char			**strarr;
	t_instr			*instr_node;

	// strarr = ft_strsplit(operation, '\n');
	// operation = strarr[0];
	// ft_printf("%s\n", operation);
	if (valid_instruction(operation) == 0)
	{
		ft_printf("Error\n");
		return (-1);
	}
	else
	{
		// if (prgm->instr_lst == NULL)
		// 	prgm->instr_lst = ft_memalloc(sizeof(t_instr));
		instr_node = ft_memalloc(sizeof(t_instr));
		ft_setinstruction(operation, instr_node);
		// ft_printf(ANSI_COLOR_GREEN"AFTER the SET FUNCTION : instr='%d'\n"ANSI_COLOR_RESET, instr_node->instruction);
		// print_binary(instr_node->instruction);
		ft_instr_addend(&prgm, instr_node);
	}
	// ft_print_instructions(prgm);
	return (0);
}