/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sort_big.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/11 12:22:18 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/04/12 22:52:27 by dominique     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void				ft_move_to_top_of_stack(t_stacks **stacks, t_prgm *prgm, \
										int len, int num, size_t flag)
{
	t_stack_list	*temp;

	if (flag == 1)
		temp = (*stacks)->stackb_lst;
	else
		temp = (*stacks)->stacka_lst;
	while ((temp->num != num) && (!(len < 2)))
		temp = temp->next;
	if ((temp->pos_index <= (len / 2)) && (!(len < 2)))
	{
		// while ((temp->prev != NULL) && (stack_id == 0))
		// 	ft_rotate_a(prgm, stacks);
		while (temp->prev != NULL)
		{
			if (flag == 1)
			{
				if ((ft_stack_len((*stacks)->stackb_lst) > 2) && \
				(temp->dis_from_top == 1) && \
				(temp->num > temp->prev->num) && \
				(temp->prev->num > temp->next->num))
				{
					ft_swap_b(prgm, stacks);
					temp = temp->prev;
				}
				else
					ft_rotate_b(prgm, stacks);
			}
			else
				ft_rotate_a(prgm, stacks);
		}
	}
	else
	{
		// ft_printf("CHECK if this part ever RUNS");
		// while ((temp->dis_from_top != 0) && (stack_id == 0))
		// 	ft_reverserotate_a(prgm, stacks);
		while (temp->dis_from_top != 0)
		{
			if (flag == 1)
				ft_reverserotate_b(prgm, stacks);
			else
				ft_reverserotate_a(prgm, stacks);
		}
	}
}

/*
** Function where I need to find the min or the max num
** based on the flag that is passed as a parameter.
** If flag == 0 then I need to find the min in Stack A
** If flag == 1 then I need to find the max in Stack B
** When I find it, I call the function ft_move_to_top_of_stack
** to move the number (min or max) to the top of the corresponding 
** Stack (A or B respectively)
*/

void				ft_find_min_or_max(t_stacks **stacks, t_prgm *prgm, \
										size_t flag)
{
	t_stack_list	*temp;
	int				min;
	int				max;
	int				len;
	size_t			i;

	min = 2147483647;
	max = -2147483648;
	if (flag == 0)
		temp = (*stacks)->stacka_lst;
	else
		temp = (*stacks)->stackb_lst;
	len = ft_stack_len(temp);
	i = 0;
	if (len > 1)
	{
		while (temp != NULL)
		{
			if ((temp->num < min) && (flag == 0))
			{
				min = temp->num;
				temp->dis_from_top = i;
			}
			if ((temp->num > max) && (flag == 1))
			{
				max = temp->num;
				temp->dis_from_top = i;
			}
			temp = temp->next;
			i += 1;
		}
		if (flag == 0)
			ft_move_to_top_of_stack(stacks, prgm, len, min, flag);
		else
			ft_move_to_top_of_stack(stacks, prgm, len, max, flag);
		// ft_print_doubly_all((*stacks)->stacka_lst);
		// ft_print_doubly_all((*stacks)->stackb_lst);
	}
}
