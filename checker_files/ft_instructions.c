/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_instructions.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/07 14:16:19 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/02/07 14:16:21 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int					valid_instruction(char *str)
{
	// char	*newstr;

	if (!ft_strcmp(str, "sa") || !ft_strcmp(str, "sb") || \
	!ft_strcmp(str, "ss") || !ft_strcmp(str, "pa") || \
	!ft_strcmp(str, "pb") || !ft_strcmp(str, "ra") || \
	!ft_strcmp(str, "rb") || !ft_strcmp(str, "rr") || \
	!ft_strcmp(str, "rra") || !ft_strcmp(str, "rrb") || \
	!ft_strcmp(str, "rrr"))
	{
		// ft_printf(ANSI_COLOR_GREEN"\n%s"ANSI_COLOR_RESET, str);
		return (1);
	}
	else
	{
		// ft_printf(ANSI_COLOR_RED"\n%s"ANSI_COLOR_RESET, str);
		return (0);
	}
}

t_instr				*ft_instr_newnode(char *operation)
{
	t_instr			*newnode;

	ft_printf("%s \n", operation);
	newnode = malloc(sizeof(t_instr));
	if (newnode == NULL)
		return (NULL);
	// ft_printf("Num = %d Size : %d \n", content, sizeof(content));
	newnode->instruction = 1;
	newnode->next = NULL;
	return (newnode);
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

void				ft_print_instructions(t_instr *lst)
{
	t_instr			*temp;
	int				len;

	ft_printf("Printing the instructions \n");
	temp = lst;
	len = 0;
	if (temp == NULL)
		;
	while (temp != NULL)
	{
		len++;
		ft_printf("%d \n", temp->instruction);
		temp = temp->next;
	}
	ft_printf("Length of the stack = %d \n", len);
}

void				ft_call_instructfunctions(t_instr *lst, t_stack **stack_a, \
											t_stack **stack_b)
{
	t_instr			*temp;
	operation_func	oper_func[11];

	oper_func[0] = ft_swap_a;
	oper_func[1] = ft_swap_b;
	oper_func[2] = ft_swap_both;
	oper_func[3] = ft_push_a;
	oper_func[4] = ft_push_b;
	oper_func[5] = ft_rotate_a;
	oper_func[6] = ft_rotate_b;
	oper_func[7] = ft_rotate_both;
	oper_func[8] = ft_reverserotate_a;
	oper_func[9] = ft_reverserotate_b;
	oper_func[10] = ft_reverserotate_both;
	temp = lst;
	if (temp == NULL)
		;
	while (temp != NULL)
	{
		oper_func[temp->instruction](stack_a, stack_b);
		temp = temp->next;
	}
	ft_print_stack(*stack_a);
	ft_print_stack(*stack_b);
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

int					ft_saveinstructions(t_instr **instr_lst, char *operation)
{
	char			**strarr;
	t_instr			*instr_node;

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
