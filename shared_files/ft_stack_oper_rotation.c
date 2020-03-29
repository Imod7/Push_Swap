/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_stack_oper_rotation.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/24 14:53:01 by dsaripap       #+#    #+#                */
/*   Updated: 2020/03/29 18:24:48 by dominique     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int					ft_rotate_a(t_prgm *prgm, t_stacks **stacks)
{
	t_stack_list	*first_node;
	t_stack_list	*second_node;
	t_stack_list	*temp_a;

	// ft_printf("ra\n");
	// (void)(*stacks)->stackb_lst;
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
	// prgm->number_operations += 1;
	if (prgm->exec == 1)
	{
		ft_saveinstructions(prgm, *stacks, "ra");
		ft_metrics_calculation(prgm, stacks, 0);
	}
	// if (prgm->options & OPTION_V)
	// 	ft_print_stacks(*stacks);
	return (0);
}

int					ft_rotate_b(t_prgm *prgm, t_stacks **stacks)
{
	t_stack_list	*first_node;
	t_stack_list	*second_node;
	t_stack_list	*temp_b;

	// ft_printf("rb\n");
	// (void)(*stacks)->stacka_lst;
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
	// prgm->number_operations += 1;
	if (prgm->exec == 1)
	{
		ft_saveinstructions(prgm, *stacks, "rb");
		ft_metrics_calculation(prgm, stacks, 0);
	}
	// if (prgm->options & OPTION_V)
	// 	ft_print_stacks(*stacks);
	return (0);
}

int					ft_rotate_both(t_prgm *prgm, t_stacks **stacks)
{
	size_t			flag;

	// ft_printf("rr\n");
	flag = 0;
	if (ft_stack_length((*stacks)->stacka_lst) >= 2)
	{
		ft_rotate_a(prgm, stacks);
		flag = 1;
	}
	if (ft_stack_length((*stacks)->stackb_lst) >= 2)
	{
		ft_rotate_b(prgm, stacks);
		flag = 2;
	}
	// if (flag > 0)
	// 	prgm->number_operations += 1;
	if ((flag > 0) && (prgm->exec == 1))
	{
		ft_saveinstructions(prgm, *stacks, "rr");
		ft_metrics_calculation(prgm, stacks, 0);
	}
	// if (prgm->options & OPTION_V)
	// 	ft_print_stacks(*stacks);
	return (0);
}
