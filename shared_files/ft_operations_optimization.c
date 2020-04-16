/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_operations_optimization.c                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/16 14:53:01 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/04/16 20:02:31 by dominique     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_instr				*ft_instr_newnode(size_t content)
{
	t_instr			*newnode;

	newnode = malloc(sizeof(t_instr));
	if (newnode == NULL)
		return (NULL);
	newnode->instruction = content;
	newnode->next = NULL;
	return (newnode);
}

void				ft_instruc_addend(t_instr **lst, t_instr *new)
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

/*
** Copy operation_list from prgm to test if merging the operations
** will optimize my operations
*/

// t_instr				*ft_copy_instrlist(t_instr *instr_lst)
// {
// 	t_instr			*newnode;
// 	t_instr			*newlist;

// 	// newlist = ft_memalloc(sizeof(t_stack_list));
// 	newlist = NULL;
// 	if (instr_lst == NULL)
// 	{
// 		return (NULL);
// 	}
// 	else
// 	{
// 		while (instr_lst != NULL)
// 		{
// 			newnode = ft_instr_newnode(instr_lst->instruction);
// 			ft_instruc_addend(&newlist, newnode);
// 			instr_lst = instr_lst->next;
// 		}
// 	}
// 	return (newlist);
// }

size_t				ft_instr_len(t_instr *instr_lst)
{
	t_instr			*temp;
	size_t			len;

	temp = instr_lst;
	len = 0;
	while (temp != NULL)
	{
		len += 1;
		temp = temp->next;
	}
	return (len);
}

void				ft_operation_descr(t_prgm *prgm)
{
	t_instr			*temp;
	t_instr			*new_lst;
	t_instr			*new_node;
	int				rr;
	int				rrr;
	int				ss;

	temp = prgm->instr_lst;
	rr = 0;
	rrr = 0;
	ss = 0;
	new_lst = ft_memalloc(sizeof(t_instr));
	while (temp->next != NULL)
	{
		new_node = ft_memalloc(sizeof(t_instr));
		if (((temp->instruction & INSTR_RA) && \
		(temp->next->instruction & INSTR_RB)) || \
		((temp->instruction & INSTR_RB) && \
		(temp->next->instruction & INSTR_RA)))
		{
			rr += 1;
			ft_setinstruction("rr", new_node);
			temp = temp->next;
		}
		else if (((temp->instruction & INSTR_RRA) && \
		(temp->next->instruction & INSTR_RRB)) || \
		((temp->instruction & INSTR_RRB) && \
		(temp->next->instruction & INSTR_RRA)))
		{
			rrr += 1;
			ft_setinstruction("rrr", new_node);
			temp = temp->next;
		}
		else if (((temp->instruction & INSTR_SA) && \
		(temp->next->instruction & INSTR_SB)) || \
		((temp->instruction & INSTR_SB) && \
		(temp->next->instruction & INSTR_SA)))
		{
			ss += 1;
			ft_setinstruction("ss", new_node);
			temp = temp->next;
		}
		else
		{
			new_node->instruction = temp->instruction;
		}
		ft_instr_addend(&new_lst, new_node);
		// ft_printf("new = %d\n", new_node->instruction);
		// new_lst = new_lst->next;
		temp = temp->next;
	}
	// new_lst = ft_copy_instrlist(prgm->instr_lst);
	// prgm->instr_lst = new_lst;
	// ft_printf("Possibilities to rr : %d\n", rr);
	// ft_printf("Possibilities to rrr : %d\n", rrr);
	// ft_printf("Possibilities to ss : %d\n", ss);
	// ft_printf("Operations in newlist: %d\n", ft_instr_len(new_lst));
	// ft_printf("Operations in oldlist : %d\n", ft_instr_len(prgm->instr_lst));
}
