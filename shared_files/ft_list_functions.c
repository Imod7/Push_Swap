/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_list_functions.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/24 14:54:47 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/04/11 10:44:12 by dominique     ########   odam.nl         */
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

int					ft_stack_len(t_stack_list *lst)
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

int					ft_numexists_instack(t_stack_list *lst, int num)
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
