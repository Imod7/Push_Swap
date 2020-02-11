/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_freelist.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/31 18:57:55 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/01/31 19:06:49 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void		ft_free_list(t_stack **stack_lst)
{
	t_stack	*curr_node;
	t_stack	*next_node;

	curr_node = *stack_lst;
	while (curr_node != NULL)
	{
		next_node = curr_node->next;
		free(curr_node);
		curr_node = next_node;
	}
	*stack_lst = NULL;
}
