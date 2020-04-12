/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_stack_oper_rotation.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/24 14:53:01 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/04/12 22:53:48 by dominique     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int					ft_rotate_a(t_prgm *prgm, t_stacks **stacks)
{
	t_stack_list	*first_node;
	t_stack_list	*second_node;
	t_stack_list	*temp_a;

	temp_a = (*stacks)->stacka_lst;
	if (temp_a == NULL)
		return (0);
	first_node = (*stacks)->stacka_lst;
	second_node = (*stacks)->stacka_lst->next;
	second_node->prev = NULL;
	while (temp_a->next != NULL)
		temp_a = temp_a->next;
	temp_a->next = first_node;
	first_node->prev = temp_a;
	first_node->next = NULL;
	(*stacks)->stacka_lst = second_node;
	if (prgm->exec == 1)
	{
		ft_saveinstructions(prgm, *stacks, "ra");
		ft_metrics_calculation(prgm, stacks, 0);
	}
	return (0);
}

int					ft_rotate_b(t_prgm *prgm, t_stacks **stacks)
{
	t_stack_list	*first_node;
	t_stack_list	*second_node;
	t_stack_list	*temp_b;

	temp_b = (*stacks)->stackb_lst;
	if (temp_b == NULL)
		return (0);
	first_node = (*stacks)->stackb_lst;
	second_node = ((*stacks)->stackb_lst)->next;
	second_node->prev = NULL;
	while (temp_b->next != NULL)
		temp_b = temp_b->next;
	temp_b->next = first_node;
	first_node->prev = temp_b;
	first_node->next = NULL;
	(*stacks)->stackb_lst = second_node;
	if (prgm->exec == 1)
	{
		ft_saveinstructions(prgm, *stacks, "rb");
		ft_metrics_calculation(prgm, stacks, 0);
	}
	return (0);
}

int					ft_rotate_both(t_prgm *prgm, t_stacks **stacks)
{
	size_t			flag;

	flag = 0;
	if (ft_stack_len((*stacks)->stacka_lst) >= 2)
	{
		ft_rotate_a(prgm, stacks);
		flag = 1;
	}
	if (ft_stack_len((*stacks)->stackb_lst) >= 2)
	{
		ft_rotate_b(prgm, stacks);
		flag = 2;
	}
	if ((flag > 0) && (prgm->exec == 1))
	{
		ft_saveinstructions(prgm, *stacks, "rr");
		ft_metrics_calculation(prgm, stacks, 0);
	}
	return (0);
}
