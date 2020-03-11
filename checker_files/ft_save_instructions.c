/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_save_instructions.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/24 14:52:10 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/02/24 14:52:13 by dsaripap      ########   odam.nl         */
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

void				ft_setinstruction(char *operation, t_instr *instr_node)
{
	if (!ft_strcmp(operation, "sa"))
		instr_node->instruction |= INSTR_SA;
	else if (!ft_strcmp(operation, "sb"))
		instr_node->instruction |= INSTR_SB;
	else if (!ft_strcmp(operation, "ss"))
		instr_node->instruction |= INSTR_SS;
	else if (!ft_strcmp(operation, "pa"))
		instr_node->instruction |= INSTR_PA;
	else if (!ft_strcmp(operation, "pb"))
		instr_node->instruction |= INSTR_PB;
	else if (!ft_strcmp(operation, "ra"))
		instr_node->instruction |= INSTR_RA;
	else if (!ft_strcmp(operation, "rb"))
		instr_node->instruction |= INSTR_RB;
	else if (!ft_strcmp(operation, "rr"))
		instr_node->instruction |= INSTR_RR;
	else if (!ft_strcmp(operation, "rra"))
		instr_node->instruction |= INSTR_RRA;
	else if (!ft_strcmp(operation, "rrb"))
		instr_node->instruction |= INSTR_RRB;
	else if (!ft_strcmp(operation, "rrr"))
		instr_node->instruction |= INSTR_RRR;
}

void				ft_instr_addend(t_instr **lst, t_instr *new)
{
	t_instr			*temp;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
}

// void				ft_print_instructions(t_instr *lst)
// {
// 	t_instr			*temp;
// 	int				len;

// 	ft_printf("Printing the instructions \n");
// 	temp = lst;
// 	len = 0;
// 	if (temp == NULL)
// 		;
// 	while (temp != NULL)
// 	{
// 		len++;
// 		ft_printf("%d \n", temp->instruction);
// 		temp = temp->next;
// 	}
// 	ft_printf("Length of the stack = %d \n", len);
// }

int					ft_saveinstructions(t_instr **instr_lst, char *operation)
{
	char			**strarr;
	t_instr			*instr_node;

	// ft_printf(ANSI_COLOR_GREEN"\noperation='%s'\n"ANSI_COLOR_RESET, operation);
	strarr = ft_strsplit(operation, '\n');
	operation = strarr[0];
	if (valid_instruction(operation) == 0)
	{
		ft_printf("Error\n");
		return (-1);
	}
	else
	{
		instr_node = ft_memalloc(sizeof(t_instr));
		ft_setinstruction(operation, instr_node);
		// ft_printf("\ninstr = %d\t: ", instr_node->instruction);
		// print_binary(instr_node->instruction);
		ft_instr_addend(instr_lst, instr_node);
	}
	return (0);
}