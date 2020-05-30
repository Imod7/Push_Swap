/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_stack_oper_rotation.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/24 14:53:01 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/05/30 16:24:50 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int					ft_rotate_a(t_prgm *prgm)
{
	t_stack_list	*first_node;
	t_stack_list	*second_node;
	t_stack_list	*temp_a;

	temp_a = prgm->stacks->stacka_lst;
	if (prgm->stacka_len < 2)
		return (0);
	first_node = prgm->stacks->stacka_lst;
	second_node = prgm->stacks->stacka_lst->next;
	second_node->prev = NULL;
	while (temp_a->next != NULL)
		temp_a = temp_a->next;
	temp_a->next = first_node;
	first_node->prev = temp_a;
	first_node->next = NULL;
	prgm->stacks->stacka_lst = second_node;
	ft_metrics_calculation(prgm, 0);
	if (prgm->exec == 1)
		ft_saveinstructions(prgm, "ra");
	return (0);
}

int					ft_rotate_b(t_prgm *prgm)
{
	t_stack_list	*first_node;
	t_stack_list	*second_node;
	t_stack_list	*temp_b;

	temp_b = prgm->stacks->stackb_lst;
	if (prgm->stackb_len < 2)
		return (0);
	first_node = prgm->stacks->stackb_lst;
	second_node = (prgm->stacks->stackb_lst)->next;
	second_node->prev = NULL;
	while (temp_b->next != NULL)
		temp_b = temp_b->next;
	temp_b->next = first_node;
	first_node->prev = temp_b;
	first_node->next = NULL;
	prgm->stacks->stackb_lst = second_node;
	ft_metrics_calculation(prgm, 0);
	if (prgm->exec == 1)
		ft_saveinstructions(prgm, "rb");
	return (0);
}

int					ft_rotate_both(t_prgm *prgm)
{
	size_t			flag;

	flag = 0;
	if (prgm->stacka_len >= 2)
	{
		ft_rotate_a(prgm);
		flag = 1;
	}
	if (prgm->stackb_len >= 2)
	{
		ft_rotate_b(prgm);
		flag = 2;
	}
	ft_metrics_calculation(prgm, 0);
	if ((flag > 0) && (prgm->exec == 1))
		ft_saveinstructions(prgm, "rr");
	return (0);
}
