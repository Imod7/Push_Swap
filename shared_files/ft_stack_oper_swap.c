/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_stack_oper_swap.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/24 14:53:01 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/04/10 20:44:27 by dominique     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static	void		swap_nodes(t_stack_list *node1, t_stack_list *node2)
{
	int				temp;

	temp = node1->num;
	node1->num = node2->num;
	node2->num = temp;
}

int					ft_swap_a(t_prgm *prgm, t_stacks **stacks)
{
	int				len;

	len = ft_stack_len((*stacks)->stacka_lst);
	if (len < 2)
		return (0);
	swap_nodes((*stacks)->stacka_lst, ((*stacks)->stacka_lst)->next);
	if (prgm->exec == 1)
	{
		ft_saveinstructions(prgm, *stacks, "sa");
		if (len > 3)
			ft_metrics_calculation(prgm, stacks, 0);
	}
	return (0);
}

int					ft_swap_b(t_prgm *prgm, t_stacks **stacks)
{
	if (ft_stack_len((*stacks)->stackb_lst) < 2)
		return (0);
	swap_nodes((*stacks)->stackb_lst, ((*stacks)->stackb_lst)->next);
	if (prgm->exec == 1)
	{
		ft_saveinstructions(prgm, *stacks, "sb");
		ft_metrics_calculation(prgm, stacks, 0);
	}
	return (0);
}

int					ft_swap_both(t_prgm *prgm, t_stacks **stacks)
{
	size_t			flag;

	flag = 0;
	if (ft_stack_len((*stacks)->stacka_lst) >= 2)
	{
		swap_nodes((*stacks)->stacka_lst, (*stacks)->stacka_lst->next);
		flag = 1;
	}
	if (ft_stack_len((*stacks)->stackb_lst) >= 2)
	{
		swap_nodes((*stacks)->stackb_lst, ((*stacks)->stackb_lst)->next);
		flag = 2;
	}
	if ((flag > 0) && (prgm->exec == 1))
	{
		ft_saveinstructions(prgm, *stacks, "ss");
		ft_metrics_calculation(prgm, stacks, 0);
	}
	return (0);
}
