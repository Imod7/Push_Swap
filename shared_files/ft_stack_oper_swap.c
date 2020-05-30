/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_stack_oper_swap.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/24 14:53:01 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/05/30 10:34:44 by dominique     ########   odam.nl         */
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
	if (prgm->stacka_len < 2)
		return (0);
	swap_nodes(prgm->stacks->stacka_lst, (prgm->stacks->stacka_lst)->next);
	if (prgm->stacka_len > 3)
			ft_metrics_calculation(prgm, 0);
	if (prgm->exec == 1)
		ft_saveinstructions(prgm, "sa");
	return (0);
}

int					ft_swap_b(t_prgm *prgm)
{
	if (prgm->stackb_len < 2)
		return (0);
	swap_nodes(prgm->stacks->stackb_lst, (prgm->stacks->stackb_lst)->next);
	ft_metrics_calculation(prgm, 0);
	if (prgm->exec == 1)
		ft_saveinstructions(prgm, "sb");
	return (0);
}

int					ft_swap_both(t_prgm *prgm)
{
	size_t			flag;

	flag = 0;
	if (prgm->stacka_len >= 2)
	{
		swap_nodes(prgm->stacks->stacka_lst, prgm->stacks->stacka_lst->next);
		flag = 1;
	}
	if (prgm->stackb_len >= 2)
	{
		swap_nodes(prgm->stacks->stackb_lst, (prgm->stacks->stackb_lst)->next);
		flag = 2;
	}
	ft_metrics_calculation(prgm, 0);
	if ((flag > 0) && (prgm->exec == 1))
		ft_saveinstructions(prgm, "ss");
	return (0);
}
