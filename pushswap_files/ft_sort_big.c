/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sort_big.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/11 12:22:18 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/04/11 15:14:20 by dominique     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

// void				ft_move_min(t_stacks **stacks, t_prgm *prgm, int len, 
// 								int min)
// {
// 	t_stack_list	*temp;

// 	temp = (*stacks)->stackb_lst;
// 	while ((temp->num != min) && (!(len < 2)))
// 		temp = temp->next;
// 	if ((temp->dis_from_top <= (len / 2)) && (!(len < 2)))
// 	{
// 		// while ((temp->prev != NULL) && (stack_id == 0))
// 		// 	ft_rotate_a(prgm, stacks);
// 		while (temp->prev != NULL)
// 			ft_rotate_b(prgm, stacks);
// 	}
// 	else
// 	{
// 		// while ((temp->dis_from_top != 0) && (stack_id == 0))
// 		// 	ft_reverserotate_a(prgm, stacks);
// 		while (temp->dis_from_top != 0)
// 			ft_reverserotate_b(prgm, stacks);
// 	}
// }

void				ft_min_to_top_of_stack(t_stacks **stacks, t_prgm *prgm, \
										int len, int min, size_t flag)
{
	t_stack_list	*temp;

	if (flag == 1)
		temp = (*stacks)->stackb_lst;
	else
		temp = (*stacks)->stacka_lst;
	while ((temp->num != min) && (!(len < 2)))
		temp = temp->next;
	if ((temp->dis_from_top <= (len / 2)) && (!(len < 2)))
	{
		// while ((temp->prev != NULL) && (stack_id == 0))
		// 	ft_rotate_a(prgm, stacks);
		while (temp->prev != NULL)
		{
			if (flag == 1)
				ft_rotate_b(prgm, stacks);
			else
				ft_rotate_a(prgm, stacks);
		}
	}
	else
	{
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
** Moves the smallest number on top of the stack
** The Stack is specified by the parameter stack_id
** Until now it is used only to move the smallest number 
** on top of Stack B (stack_id = 1)
*/

void				ft_find_min(t_stacks **stacks, t_prgm *prgm, size_t flag)
{
	t_stack_list	*temp;
	int				min;
	int				len;
	size_t			i;

	min = 2147483647;
	if (flag == 1)
		temp = (*stacks)->stackb_lst;
	else
		temp = (*stacks)->stacka_lst;
	len = ft_stack_len(temp);
	i = 0;
	if (len > 1)
	{
		while (temp != NULL)
		{
			if (temp->num < min)
			{
				min = temp->num;
				temp->dis_from_top = i;
			}
			temp = temp->next;
			i += 1;
		}
		// ft_print_doubly_all((*stacks)->stacka_lst);
		// ft_print_doubly_all((*stacks)->stackb_lst);
		ft_min_to_top_of_stack(stacks, prgm, len, min, flag);
		// ft_print_doubly_all((*stacks)->stacka_lst);
		// ft_print_doubly_all((*stacks)->stackb_lst);
	}
}

// void				ft_min_ontop_of_b(t_stacks **stacks, t_prgm *prgm)
// {
// 	t_stack_list	*temp;
// 	int				min;
// 	int				len;
// 	size_t			i;

// 	min = 2147483647;
// 	temp = (*stacks)->stackb_lst;
// 	len = ft_stack_len((*stacks)->stackb_lst);
// 	i = 0;
// 	if (len > 1)
// 	{
// 		while (temp != NULL)
// 		{
// 			if (temp->num < min)
// 			{
// 				min = temp->num;
// 				temp->dis_from_top = i;
// 			}
// 			temp = temp->next;
// 			i += 1;
// 		}
// 		ft_move_min(stacks, prgm, len, min);
// 	}
// }
