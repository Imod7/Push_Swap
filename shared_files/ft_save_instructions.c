/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_save_instructions.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/24 14:52:10 by dsaripap       #+#    #+#                */
/*   Updated: 2020/04/02 13:10:10 by dominique     ########   odam.nl         */
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

void				ft_checkinstruction(size_t instruction)
{
	if (instruction & INSTR_SA)
		ft_printf("sa\n");
	if (instruction & INSTR_SB)
		ft_printf("sb\n");
	if (instruction & INSTR_SS)
		ft_printf("ss\n");
	if (instruction & INSTR_PA)
		ft_printf("pa\n");
	if (instruction & INSTR_PB)
		ft_printf("pb\n");
	if (instruction & INSTR_RA)
		ft_printf("ra\n");
	if (instruction & INSTR_RB)
		ft_printf("rb\n");
	if (instruction & INSTR_RR)
		ft_printf("rr\n");
	if (instruction & INSTR_RRA)
		ft_printf("rra\n");
	if (instruction & INSTR_RRB)
		ft_printf("rrb\n");
	if (instruction & INSTR_RRR)
		ft_printf("rrr\n");
}

void				ft_instr_addend(t_prgm **prgm, t_instr *new)
{
	t_instr			*temp;

	if ((*prgm)->instr_lst == NULL)
	{
		(*prgm)->instr_lst = new;
		return ;
	}
	temp = (*prgm)->instr_lst;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = new;
}

int					ft_saveinstructions(t_prgm *prgm, t_stacks *stacks, \
										char *operation)
{
	t_instr			*instr_node;

	if (valid_instruction(operation) == 0)
	{
		ft_printf("Error\n");
		return (-1);
	}
	else
	{
		// 	prgm->instr_lst = ft_memalloc(sizeof(t_instr));
		instr_node = ft_memalloc(sizeof(t_instr));
		ft_setinstruction(operation, instr_node);
		// print_binary(instr_node->instruction);
		ft_instr_addend(&prgm, instr_node);
		if (prgm->exec == 1)
			ft_printf("%s\n", operation);
		if ((prgm->options & OPTION_V) && (prgm->exec == 1))
			ft_print_stacks(stacks);
		prgm->number_operations += 1;
	}
	// ft_print_instructions(prgm);
	return (0);
}
