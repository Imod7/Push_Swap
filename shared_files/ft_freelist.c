/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_freelist.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/31 18:57:55 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/04/16 13:06:28 by dominique     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void				ft_free_list(t_stack_list *stack_lst)
{
	t_stack_list	*curr_node;
	t_stack_list	*next_node;

	curr_node = stack_lst;
	while (curr_node != NULL)
	{
		next_node = curr_node->next;
		free(curr_node);
		curr_node = next_node;
	}
	stack_lst = NULL;
}
