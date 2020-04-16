/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_stack_oper_swap.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/24 14:53:01 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/04/16 09:34:00 by dominique     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static	void		swap_nodes(t_stack_list *node1, t_stack_list *node2)
{
	int				temp;

	temp = node1->num;
	node1->num = node2->num;
	node2->num = temp;
}

int					ft_swap_a(t_prgm *prgm)
{
	int				len;

	len = ft_stack_len(prgm->stacks->stacka_lst);
	if (len < 2)
		return (0);
	swap_nodes(prgm->stacks->stacka_lst, (prgm->stacks->stacka_lst)->next);
	if (prgm->exec == 1)
	{
		ft_saveinstructions(prgm, "sa");
		if (len > 3)
			ft_metrics_calculation(prgm, 0);
	}
	return (0);
}

int					ft_swap_b(t_prgm *prgm)
{
	if (ft_stack_len(prgm->stacks->stackb_lst) < 2)
		return (0);
	swap_nodes(prgm->stacks->stackb_lst, (prgm->stacks->stackb_lst)->next);
	if (prgm->exec == 1)
	{
		ft_saveinstructions(prgm, "sb");
		ft_metrics_calculation(prgm, 0);
	}
	return (0);
}

int					ft_swap_both(t_prgm *prgm)
{
	size_t			flag;

	flag = 0;
	if (ft_stack_len(prgm->stacks->stacka_lst) >= 2)
	{
		swap_nodes(prgm->stacks->stacka_lst, prgm->stacks->stacka_lst->next);
		flag = 1;
	}
	if (ft_stack_len(prgm->stacks->stackb_lst) >= 2)
	{
		swap_nodes(prgm->stacks->stackb_lst, (prgm->stacks->stackb_lst)->next);
		flag = 2;
	}
	if ((flag > 0) && (prgm->exec == 1))
	{
		ft_saveinstructions(prgm, "ss");
		ft_metrics_calculation(prgm, 0);
	}
	return (0);
}
