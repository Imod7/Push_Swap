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

t_stack		*ft_stack_newnode(int content)
{
	t_stack	*newnode;

	newnode = malloc(sizeof(t_stack));
	if (newnode == NULL)
		return (NULL);
	// ft_printf("Num = %d Size : %d \n", content, sizeof(content));
	newnode->num = content;
	newnode->next = NULL;
	return (newnode);
}

void		ft_stack_addend(t_stack **lst, t_stack *new)
{
	t_stack	*temp;

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

void		ft_print_stack(t_stack *lst)
{
	t_stack	*temp;
	int		len;

	ft_printf(ANSI_COLOR_CYAN"\n-----------------------------------------\n");
	ft_printf("----\t\tStack %c\t\t     ----\n", lst->stack_id);
	ft_printf("-----------------------------------------\n"ANSI_COLOR_RESET);
	temp = lst;
	len = 0;
	if (temp == NULL)
		;
	while (temp != NULL)
	{
		len++;
		ft_printf("|\t\t%-15d\t\t|\n", temp->num);
		temp = temp->next;
	}
	ft_printf("-----------------------------------------\n");
	// ft_printf("Length of the stack = %d \n", len);
}

void		ft_print_stacktemp(t_stack_prop *stackp_lst)
{
	t_stack	*temp;
	int		len;

	ft_printf(ANSI_COLOR_CYAN"\n-----------------------------------------\n");
	ft_printf("----\t\tStack %c\t\t     ----\n", stackp_lst->stackprop_id);
	ft_printf("-----------------------------------------\n"ANSI_COLOR_RESET);
	temp = stackp_lst->stack_lst;
	len = 0;
	if (temp == NULL)
		ft_printf("|\t\tlist is NULL\t\t|\n");
	while (temp != NULL)
	{
		len++;
		ft_printf("|\t\t%-15d\t\t|\n", temp->num);
		temp = temp->next;
	}
	ft_printf("-----------------------------------------\n");
	// ft_printf("Length of the stack = %d \n", len);
}

int			ft_stack_length(t_stack *lst)
{
	t_stack *temp;
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

int			ft_numexists(t_stack *lst, int num)
{
	t_stack *temp;

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
