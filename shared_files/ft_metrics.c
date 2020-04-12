/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_metrics.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dominique <dominique@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/14 15:47:55 by dominique     #+#    #+#                 */
/*   Updated: 2020/04/12 23:30:06 by dominique     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

/*
** Calculating how many buckets I will have 
** based on the amount of numbers (len) of my list
** and also the bucket size 
*/

void				ft_calculate_buckets(t_prgm *prgm, int len)
{
	int				temp;

	temp = len;
	prgm->buckets = 2;
	while (temp > 10)
	{
		prgm->buckets += 2;
		temp = temp / 2;
	}
	if (temp % 2 != 0)
		prgm->bucket_size = (len / prgm->buckets) + 1;
	else
		prgm->bucket_size = len / prgm->buckets;
}

/*
** Updating the bucket information in my sorted list
*/

void				ft_update_buckets(t_prgm **prgm)
{
	t_stack_list	*sorted;
	int				i;
	int				j;

	sorted = (*prgm)->sorted_stack;
	i = 0;
	j = -1;
	while (sorted != NULL)
	{
		if ((i % (*prgm)->bucket_size) == 0)
			j += 1;
		sorted->bucket = j;
		sorted = sorted->next;
		i += 1;
	}
}

void				ft_calculate_distance(int *i, int *j, t_stack_list **temp, 
										int len, int middle)
{
	if (len == 1)
	{
		(*temp)->dis_from_top = 0;
		(*temp)->pos_index = 0;
	}
	else
	{
		if (*i < middle)
		{
			(*temp)->dis_from_top = *i;
			(*temp)->pos_index = *i;
			*i += 1;
			*j = *i;
		}
		else
		{
			(*temp)->pos_index = *i;
			if ((len % 2 == 1) && (*i == middle + 1))
				*j = middle;
			else if (*i != middle)
				*j -= 1;
			(*temp)->dis_from_top = *j;
			*i += 1;
		}
	}
}

/*
** In function ft_metrics_calculation I update the metric 
** dis_from_top (distance from top) for Stack A and Stack B
** by comparing with the numbers in the sorted_list
** it only calculates if length of Stack A > 3
*/

void				ft_metrics_calculation(t_prgm *prgm, t_stacks **stacks, \
											int init)
{
	t_stack_list	*temp;
	// t_stack_list	*sorted;
	int				i;
	int				j;
	int				middle;
	int				len;

	// sorted = prgm->sorted_stack;
	i = 0;
	temp = (*stacks)->stacka_lst;
	len = ft_stack_len(temp);
	middle = len / 2;
	while (temp != NULL)
	{
		while (prgm->sorted_stack->num != temp->num)
			prgm->sorted_stack = prgm->sorted_stack->next;
		ft_calculate_distance(&i, &j, &temp, len, middle);
		if (init == 1)
			temp->bucket = prgm->sorted_stack->bucket;
		while (prgm->sorted_stack->prev != NULL)
			prgm->sorted_stack = prgm->sorted_stack->prev;
		temp = temp->next;
	}
	i = 0;
	temp = (*stacks)->stackb_lst;
	len = ft_stack_len(temp);
	middle = len / 2;
	while (temp != NULL)
	{
		ft_calculate_distance(&i, &j, &temp, len, middle);
		temp = temp->next;
	}
}

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
	// ft_printf("Number of operations for newlist: %d\n", ft_instr_len(new_lst));
	// ft_printf("Number of operations for oldlist : %d\n", ft_instr_len(prgm->instr_lst));
}