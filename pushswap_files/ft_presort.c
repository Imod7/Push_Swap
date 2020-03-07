/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_presort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/05 13:06:40 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/03/05 13:21:03 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"
#include <stdio.h>

void				splitList(t_stack_list *completelist, t_stack_list **ahalf,\
							t_stack_list **bhalf)
{
	int				len;
	int				split;
	t_stack_list	*splitnode;

	len = ft_stack_length(completelist);
	if (len % 2 == 0)
	{
		split = len / 2;
		ft_printf("split even = %d\n"ANSI_COLOR_RESET, split);
	}
	else
	{
		split = (len / 2) + 1;
		ft_printf("split odd = %d\n"ANSI_COLOR_RESET, split);
	}
	if (len == 1)
	{
		ft_printf("\n");
		*ahalf = malloc(sizeof(t_stack_list));
		*ahalf = completelist;
		(*ahalf)->next = NULL;
		*bhalf = NULL;
	}
	else
	{
		splitnode = malloc(sizeof(t_stack_list));
		splitnode = completelist;
		while (split - 1 > 0)
		{
			splitnode = splitnode->next;
			split--;
		}
		*ahalf = completelist;
		*bhalf = splitnode->next;
		(*bhalf)->prev = NULL;
		splitnode->next =  NULL;
	}
}

void				ft_mergesort(t_stack_list **completelist)
{
	t_stack_list	*first_half;
	t_stack_list	*second_half;

	first_half = NULL;
	second_half = NULL;
	ft_printf(ANSI_COLOR_GREEN"\n\n>>>>>>> complete list <<<<<<<");
	ft_print_doublyll(*completelist);
	ft_printf(ANSI_COLOR_GREEN">>>>>>> ----------------- <<<<<<<\n\n"ANSI_COLOR_RESET);
	splitList(*completelist, &first_half, &second_half);
	if ((*completelist != NULL) || ((*completelist)->next != NULL))
	{
		printf(">>>>>>> complete list %p <<<<<<<\n", (*completelist)->next);
		ft_printf(">>>>>>> first half <<<<<<<");
		ft_print_doublyll(first_half);
		ft_printf(">>>>>>> second half <<<<<<<");
		ft_print_doublyll(second_half);
		ft_mergesort(&first_half);
		ft_mergesort(&second_half);
	}
	else
	{
		ft_printf(">>>>>>> first half <<<<<<<");
		ft_print_doublyll(first_half);
		ft_printf(">>>>>>> second half <<<<<<<");
		ft_print_doublyll(second_half);
		return ;
	}
}

t_stack				*ft_presort(t_stack_list *stack_a)
{
	t_stack			*temp;

	temp = NULL;
	ft_mergesort(&stack_a);
	return (temp);
}
