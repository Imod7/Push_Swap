/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_list_functions.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/24 14:54:47 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/02/24 14:54:51 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

t_stack_list		*ft_stack_newnode(int content)
{
	t_stack_list	*newnode;

	newnode = malloc(sizeof(t_stack_list));
	if (newnode == NULL)
		return (NULL);
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

void				ft_print_stacks(t_stacks *stacks)
{
	t_stack_list	*temp_a;
	t_stack_list	*temp_b;

	ft_printf(ANSI_COLOR_CYAN"\n-----------------------------------------\t");
	ft_printf(ANSI_COLOR_CYAN"-----------------------------------------\n");
	ft_printf("|\t\tStack %c\t\t        |\t", stacks->stacka_id);
	ft_printf("|\t\tStack %c\t\t        |\n", stacks->stackb_id);
	ft_printf("-----------------------------------------");
	ft_printf("\t-----------------------------------------\n");
	temp_a = stacks->stacka_lst;
	temp_b = stacks->stackb_lst;
	while ((temp_a != NULL) || (temp_b != NULL))
	{
		if (temp_a != NULL)
		{
			ft_printf("|\t\t%-15d\t\t|\t", temp_a->num);
			temp_a = temp_a->next;
		}
		else
			ft_printf("|\t\t	\t\t|\t");
		if (temp_b != NULL)
		{
			ft_printf("|\t\t%-15d\t\t|\n", temp_b->num);
			temp_b = temp_b->next;
		}
		else
			ft_printf("|\t\t	\t\t|\n");
	}
	ft_printf("-----------------------------------------\t");
	ft_printf("-----------------------------------------\n"ANSI_COLOR_RESET);
}

void				ft_print_doublyll(t_stack_list *temp)
{
	int				len;
	t_stack_list	*prevn;
	t_stack_list	*nextn;

	ft_printf(ANSI_COLOR_YELLOW"\n|------------------------------------------");
	ft_printf("---------------------|\n");
	ft_printf("|--------------------- Doubly Linked List --------------------");
	ft_printf("--|\n");
	ft_printf("|prev\t\t\t\tcurrent \t\tnext----|\n");
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
	ft_printf(ANSI_COLOR_YELLOW"|--------------------------------------------");
	ft_printf("-------------------|\n"ANSI_COLOR_RESET);
}

void				ft_print_doubly_all(t_stack_list *temp)
{
	int				len;
	t_stack_list	*prevn;
	t_stack_list	*nextn;

	ft_printf(ANSI_COLOR_CYAN"\n|------------------------------------------");
	ft_printf("-----------------------------------------|\n");
	ft_printf("|--------------------- Doubly Linked List -------------------");
	ft_printf("-----------------------|\n");
	ft_printf("|prev\t\tcurrent\t\tgoal_pos\tdistance\t\tnext\t|\n");
	len = 0;
	if (temp == NULL)
		ft_printf("|\t\t\t\t\t|\n");
	while (temp != NULL)
	{
		len++;
		prevn = temp->prev;
		nextn = temp->next;
		if (prevn != NULL)
			ft_printf("|%d\t<-\t", prevn->num);
		else
			ft_printf("|NULL\t<-\t");
		ft_printf("|%-15d", temp->num);
		if (temp != NULL)
			ft_printf("|%d\t\t|", temp->goal_pos);
		else
			ft_printf("|NULL\t\t|");
		if (temp != NULL)
			ft_printf("%d\t|", temp->distance);
		else
			ft_printf("NULL\t|");
		if (nextn != NULL)
			ft_printf("\t->\t%d\t|\n", nextn->num);
		else
			ft_printf("\t->\tNULL\t|\n");
		temp = temp->next;
	}
	ft_printf("|--------------------------------------------");
	ft_printf("--------------------------------------|\n"ANSI_COLOR_RESET);
}

int					ft_stack_length(t_stack_list *lst)
{
	t_stack_list	*temp;
	int				len;

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
	if (temp == NULL)
		return (0);
	while (temp != NULL)
	{
		if (temp->num == num)
			return (1);
		temp = temp->next;
	}
	return (0);
}
