/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_algorithm.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/11 12:22:18 by dsaripap       #+#    #+#                */
/*   Updated: 2020/03/27 17:34:54 by dominique     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void				ft_min_ontop(t_stacks **stacks, t_prgm *prgm, int stack_id)
{
	t_stack_list	*temp;
	int				min;
	int				len;
	size_t			i;

	min = 2147483647;
	// ft_printf(ANSI_COLOR_CYAN"MIN on TOP function\n");
	if (stack_id == 0)
	{
		temp = (*stacks)->stacka_lst;
		len = ft_stack_length((*stacks)->stacka_lst);
	}
	else
	{
		temp = (*stacks)->stackb_lst;
		len = ft_stack_length((*stacks)->stackb_lst);
	}
	i = 0;
	if (len > 1)
	{
		while (temp != NULL)
		{
			if (temp->num < min)
			{
				// ft_printf(ANSI_COLOR_CYAN"is temp=%d < MIN=%d ?\n", temp->num, min);
				min = temp->num;
				temp->dis_from_top = i;
				// ft_printf(ANSI_COLOR_CYAN"MIN %d\n", min);
			}
			temp = temp->next;
			i += 1;
		}
		temp = (*stacks)->stackb_lst;
		// while (temp->prev != NULL)
		// 	temp = temp->prev;
		while ((temp->num != min) && (!(len < 2)))
			temp = temp->next;
		if ((temp->dis_from_top <= (len / 2)) && (!(len < 2)))
		{
			while ((temp->prev != NULL) && (stack_id == 0))
				ft_rotate_a(prgm, stacks);
			while ((temp->prev != NULL) && (stack_id == 1))
			{
				// ft_printf("rotate b temp = %d\n", temp->num);
				ft_rotate_b(prgm, stacks);
			}
		}
		else
		{
			while ((temp->dis_from_top != 0) && (stack_id == 0))
				ft_reverserotate_a(prgm, stacks);
			while ((temp->dis_from_top != 0) && (stack_id == 1))
			{
				// ft_printf("reverse rotate b temp = %d\n", temp->num);
				ft_reverserotate_b(prgm, stacks);
			}
		}
	}
	// if (stack_id == 0)
	// 	ft_printf(ANSI_COLOR_CYAN">>>>>MIN in Stack A = %d\n", min);
	// else
	// 	ft_printf(ANSI_COLOR_CYAN">>>>>MIN in Stack B = %d\n", min);
}

/*
** Find the max number in Stack B per bucket
** and move this number to Stack A
*/

void				ft_b_to_a(t_stacks **stacks, t_prgm *prgm, \
									int current_bucket)
{
	t_stack_list	*top;
	t_stack_list	*bottom;
	int				middle_pos;
	t_stack_list	*max;
	int				i;

	i = 0;
	// ft_printf(ANSI_COLOR_GREEN"======== SIMILAR ALGORITHM FROM B TO A ========\n"ANSI_COLOR_RESET);
	top = (*stacks)->stackb_lst;
	bottom = (*stacks)->stackb_lst;
	while (bottom->next != NULL)
		bottom = bottom->next;
	middle_pos = ft_stack_length(top) / 2;
	while ((*stacks)->stackb_lst != NULL)
	{
		if (ft_stack_length((*stacks)->stackb_lst) % prgm->bucket_size == 0)
			current_bucket -= 1;
		// ft_printf("Next Loop of Algorithm : ");
		// ft_printf("i = %d, ", i);
		// ft_printf("CURRENT BUCKET\t= %d\n", current_bucket);
		// ft_printf("----- TOP\tnumber = %d\tbucket = %d\n", top->num, top->bucket);
		// ft_printf("----- BOTTOM\tnumber = %d\tbucket = %d\n", bottom->num, bottom->bucket);
		max = (*stacks)->stackb_lst;
		// ft_printf("----- top->bucket= %d\tbottom->bucket = %d, top->dis=%d, bottom->num =%d\n", top->bucket, bottom->bucket, top->dis_from_top, bottom->num);
		while (((top->bucket == current_bucket) || \
		(bottom->bucket == current_bucket)) && \
		(top->dis_from_top != bottom->dis_from_top) && (ft_stack_length(top) != 1))
		{
			// ft_printf("cur_buck=%d\ntop->num=%d\ttop_buck=%d\nbot->num=%d\tbot->buck=%d\n", current_bucket, top->num, top->bucket, bottom->num, bottom->bucket);
			if (top->num >= max->num)
				max = top;
			if (bottom->num > max->num)
				max = bottom;
			top = top->next;
			bottom = bottom->prev;
			// ft_printf("so max is %d\n", max->num);
			// ft_printf("middle_pos=%d\n", middle_pos);
			// ft_printf("top->dis_from_top=%d\tbot->dis_from_top=%d\tlen_top=%d\n", top->dis_from_top, bottom->dis_from_top, ft_stack_length(top));
		}
		if (top->num >= max->num)
				max = top;
		// ft_printf("so max is %d\n", max->num);
		if (max->dis_from_top <= middle_pos)
		{
			// ft_printf("----- ROTATE MAX number = %d\t\tMax->bucket = %d\n", max->num, max->bucket);
			while (max->dis_from_top != 0)
				ft_rotate_b(prgm, stacks);
		}
		else
		{
			// ft_printf("----- REVERSE ROTATE MAX number = %d\t\tMax->bucket = %d\n", max->num, max->bucket);
			while (max->dis_from_top != 0)
				ft_reverserotate_b(prgm, stacks);
		}
		ft_push_a(prgm, stacks);
		top = (*stacks)->stackb_lst;
		bottom = (*stacks)->stackb_lst;
		if (bottom != NULL)
		{
			while (bottom->next != NULL)
				bottom = bottom->next;
		}
		middle_pos = ft_stack_length(top) / 2;
		// ft_printf("STACK A");
		// ft_print_doubly_all((*stacks)->stacka_lst);
		// ft_printf("STACK B");
		// ft_print_doubly_all((*stacks)->stackb_lst);
		// ft_print_stacks(*stacks);
	}
	// ft_printf("======== END OF ALGORITHM in STACK B========\n");
}

void				ft_algorithm(t_prgm *prgm, t_stacks **stacks)
{
	t_stack_list	*top;
	t_stack_list	*bottom;
	int				current_bucket;
	int				middle_pos;
	int				i;

	// max = ft_give_max(stacks, prgm->bucket_size);
	// ft_printf("Max = %d \n", max);
	// ft_printf(ANSI_COLOR_GREEN"======== START OF ALGORITHM ======== \n"ANSI_COLOR_RESET);
	top = (*stacks)->stacka_lst;
	bottom = (*stacks)->stacka_lst;
	while (bottom->next != NULL)
		bottom = bottom->next;
	middle_pos = ft_stack_length(top) / 2;
	current_bucket = 0;
	while ((*stacks)->stacka_lst != NULL)
	{
		// ft_printf("Stack_A is not NULL\n");
		i = 0;
		while (i <= middle_pos)
		{
			// ft_printf("Next Internal Loop [ i = %d ]\n", i);
			// ft_printf("CURRENT BUCKET\t= %d\n", current_bucket);
			// ft_printf("MIDDLE POS = %d\n", middle_pos);
			// ft_printf("MIN\t= %d\n", min);
			// ft_printf("----- TOP\tnumber = %d\tbucket = %d\n", top->num, top->bucket);
			// ft_printf("----- BOTTOM\tnumber = %d\tbucket = %d\n", bottom->num, bottom->bucket);
			if ((top->bucket == current_bucket) && \
			(bottom->bucket == current_bucket))
			{
				if (top->dis_from_top <= bottom->dis_from_top)
				{
					// ft_printf("----- ROTATE TOP Top number = %d\t\tTop->bucket = %d\n", top->num, top->bucket);
					while (top->dis_from_top != 0)
						ft_rotate_a(prgm, stacks);
				}
				else
				{
					// ft_printf("----- REVERSE ROTATE BOTTOM  Top number = %d\t\tTop->bucket = %d\n", top->num, top->bucket);
					while (bottom->dis_from_top != 0)
						ft_reverserotate_a(prgm, stacks);
				}
				if (ft_stack_length((*stacks)->stackb_lst) > 1)
					ft_min_ontop(stacks, prgm, 1);
				ft_push_b(prgm, stacks);
				(*stacks)->stackb_lst->bucket = current_bucket;
				if ((*stacks)->stacka_lst != NULL)
				{
					top = (*stacks)->stacka_lst;
					bottom = (*stacks)->stacka_lst;
					while (bottom->next != NULL)
						bottom = bottom->next;
					middle_pos = ft_stack_length(top) / 2;
					i = 0;
				}
				else
					i += 1;
				if (ft_stack_length((*stacks)->stackb_lst) % prgm->bucket_size == 0)
					current_bucket += 1;
			}
			else if ((top->bucket == current_bucket) && \
			(bottom->bucket != current_bucket))
			{
				while (top->dis_from_top != 0)
					ft_rotate_a(prgm, stacks);
				if (ft_stack_length((*stacks)->stackb_lst) > 1)
					ft_min_ontop(stacks, prgm, 1);
				ft_push_b(prgm, stacks);
				(*stacks)->stackb_lst->bucket = current_bucket;
				top = (*stacks)->stacka_lst;
				bottom = (*stacks)->stacka_lst;
				while (bottom->next != NULL)
					bottom = bottom->next;
				middle_pos = ft_stack_length(top) / 2;
				i = 0;
				if (ft_stack_length((*stacks)->stackb_lst) % prgm->bucket_size == 0)
					current_bucket += 1;
			}
			else if ((top->bucket != current_bucket) && \
			(bottom->bucket == current_bucket))
			{
				while (bottom->dis_from_top != 0)
					ft_reverserotate_a(prgm, stacks);
				if (ft_stack_length((*stacks)->stackb_lst) > 1)
					ft_min_ontop(stacks, prgm, 1);
				ft_push_b(prgm, stacks);
				(*stacks)->stackb_lst->bucket = current_bucket;
				top = (*stacks)->stacka_lst;
				bottom = (*stacks)->stacka_lst;
				while (bottom->next != NULL)
					bottom = bottom->next;
				middle_pos = ft_stack_length(top) / 2;
				i = 0;
				if (ft_stack_length((*stacks)->stackb_lst) % prgm->bucket_size == 0)
					current_bucket += 1;
			}
			else
			{
				top = top->next;
				bottom = bottom->prev;
				i += 1;
			}
		}
	}
	// ft_printf("STACK A");
	// ft_print_doubly_all((*stacks)->stacka_lst);
	// ft_printf("STACK B");
	// ft_print_doubly_all((*stacks)->stackb_lst);
	// ft_print_stacks(*stacks);
	ft_b_to_a(stacks, prgm, current_bucket);
}
