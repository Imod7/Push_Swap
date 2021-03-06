/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_list_functions.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/24 14:54:47 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/05/29 10:51:49 by dominique     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack_list		*ft_stack_newnode(int content)
{
	t_stack_list	*newnode;

	newnode = ft_memalloc(sizeof(t_stack_list));
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

size_t				ft_stack_len(t_stack_list *lst)
{
	t_stack_list	*temp;
	size_t			len;

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

t_stack_list		*ft_copy_list(t_stack_list *stacklst)
{
	t_stack_list	*newnode;
	t_stack_list	*newlist;

	newlist = NULL;
	if (stacklst == NULL)
	{
		return (NULL);
	}
	else
	{
		while (stacklst != NULL)
		{
			newnode = ft_stack_newnode(stacklst->num);
			ft_stack_addend(&newlist, newnode);
			stacklst = stacklst->next;
		}
	}
	return (newlist);
}
