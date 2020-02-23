/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_listfunctions.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/07 14:28:04 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/02/07 14:28:09 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

t_stack_list		*ft_stack_newnode(int content)
{
	t_stack_list	*newnode;

	newnode = malloc(sizeof(t_stack_list));
	if (newnode == NULL)
		return (NULL);
	// ft_printf("Num = %d Size : %d \n", content, sizeof(content));
	newnode->num = content;
	newnode->next = NULL;
	newnode->prev = NULL;
	return (newnode);
}

void				ft_stack_addend(t_stack_list **lst, t_stack_list *new)
{
	t_stack_list	*temp;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
	new->prev = temp;
}

void				ft_print_stack(t_stack *stack)
{
	t_stack_list	*temp;
	int		len;

	ft_printf(ANSI_COLOR_CYAN"\n-----------------------------------------\n");
	ft_printf("|\t\tStack %c\t\t        |\n", stack->stack_id);
	ft_printf("-----------------------------------------\n"ANSI_COLOR_RESET);
	temp = stack->stack_lst;
	len = 0;
	if (temp == NULL)
		ft_printf("|\t\t	\t\t|\n");
	while (temp != NULL)
	{
		len++;
		ft_printf("|\t\t%-15d\t\t|\n", temp->num);
		temp = temp->next;
	}
	ft_printf("-----------------------------------------\n");
	// ft_printf("Length of the stack = %d \n", len);
}

void				ft_print_doublyll(t_stack_list *temp)
{
	int		len;
	t_stack_list		*prevn;
	t_stack_list		*nextn;

	ft_printf(ANSI_COLOR_YELLOW"\n|----------------------------------------------------------------|\n");
	ft_printf("|--------------------- Doubly Linked List ---------------------|\n");
	ft_printf("|prev\t\t\t\tcurrent \t\tnext----\n"ANSI_COLOR_RESET);
	len = 0;
	if (temp == NULL)
		ft_printf("|\t\t	\t\t|\n");
	while (temp != NULL)
	{
		len++;
		prevn = temp->prev;
		nextn = temp->next;
		if (prevn != NULL)
			ft_printf("|%d\t\t<-\t", prevn->num);
		else
			ft_printf("|NULL\t\t<-\t");
		ft_printf("|\t%-15d\t|->", temp->num);
		if (nextn != NULL)
			ft_printf("\t%d\t|\n", nextn->num);
		else
			ft_printf("\tNULL\t|\n");
		temp = temp->next;
	}
	ft_printf(ANSI_COLOR_YELLOW"|----------------------------------------------------------------|\n"ANSI_COLOR_RESET);
	// ft_printf("Length of the stack = %d \n", len);
}

int					ft_stack_length(t_stack_list *lst)
{
	t_stack_list	*temp;
	int		len;

	temp = lst;
	len = 0;
	if (temp == NULL)
		return (0);
	while (temp != NULL)
	{
		len++;
		temp = temp->next;
	}
	return (len);
}

int					ft_numexists(t_stack_list *lst, int num)
{
	t_stack_list	*temp;

	temp = lst;
	// ft_printf("num = %d \n", num);
	if (temp == NULL)
		return (0);
	while (temp != NULL)
	{
		// ft_printf("node = %d \n", temp->num);
		if (temp->num == num)
			return (1);
		temp = temp->next;
	}
	return (0);
}
