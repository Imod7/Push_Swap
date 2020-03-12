/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_presort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/05 13:06:40 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/03/10 15:51:27 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int					ft_find_median(t_stack_list **sorted_stacka)
{
	t_stack_list	*slow;
	t_stack_list	*fast;

	slow = *sorted_stacka;
	fast = *sorted_stacka;
	if (sorted_stacka != NULL)
	{
		while (fast != NULL && fast->next != NULL)
		{
			slow = slow->next;
			fast = fast->next->next;
		}
	}
	if (fast != NULL)
		return (slow->num);
	else
		return ((slow->prev->num + slow->num) / 2);
}

void				ft_splitlist(t_stack_list *completelist, \
							t_stack_list **ahalf, t_stack_list **bhalf)
{
	int				len;
	int				split;
	t_stack_list	*splitnode;

	len = ft_stack_length(completelist);
	if (len % 2 == 0)
		split = len / 2;
	else
		split = (len / 2) + 1;
	if (len == 1)
	{
		// *ahalf = malloc(sizeof(t_stack_list));
		*ahalf = completelist;
		(*ahalf)->next = NULL;
		*bhalf = NULL;
	}
	else
	{
		// splitnode = malloc(sizeof(t_stack_list));
		splitnode = completelist;
		while (split - 1 > 0)
		{
			splitnode = splitnode->next;
			split--;
		}
		*ahalf = completelist;
		*bhalf = splitnode->next;
		(*bhalf)->prev = NULL;
		splitnode->next = NULL;
	}
}

t_stack_list		*ft_mergeback(t_stack_list **ahalf, t_stack_list **bhalf)
{
	t_stack_list	*result_list;

	result_list = NULL;
	// result_list = malloc(sizeof(t_stack_list));
	// ft_printf(ANSI_COLOR_BLUE"\n\n>>>>> START MERGEBACK COMPLETE LIST <<<<<<");
	// ft_printf(ANSI_COLOR_BLUE"\n>>>>>>> first half <<<<<<<");
	// ft_print_doublyll(*ahalf);
	// ft_printf(ANSI_COLOR_BLUE">>>>>>> second half <<<<<<<");
	// ft_print_doublyll(*bhalf);
	if (*ahalf == NULL)
		return (*bhalf);
	else if (*bhalf == NULL)
		return (*ahalf);
	else
	{
		if ((*ahalf)->num > (*bhalf)->num)
		{
			result_list = *bhalf;
			result_list->next = ft_mergeback(&((*bhalf)->next), ahalf);
			result_list->next->prev = *bhalf;
		}
		else
		{
			result_list = *ahalf;
			result_list->next = ft_mergeback(&((*ahalf)->next), bhalf);
			result_list->next->prev = *ahalf;
		}
	}
	return (result_list);
}

void				ft_mergesort(t_stack_list **completelist)
{
	t_stack_list	*first_half;
	t_stack_list	*second_half;

	first_half = NULL;
	second_half = NULL;
	// ft_printf(ANSI_COLOR_MAGENTA"\n\n>> MERGESORT SPLITTING COMPLETE LIST <<<");
	// ft_print_doublyll(*completelist);
	if ((*completelist)->next == NULL)
		return ;
	ft_splitlist(*completelist, &first_half, &second_half);
	// ft_printf(ANSI_COLOR_MAGENTA">>>>>>> first half <<<<<<<");
	// ft_print_doublyll(first_half);
	// ft_printf(ANSI_COLOR_MAGENTA">>>>>>> second half <<<<<<<");
	// ft_print_doublyll(second_half);
	ft_mergesort(&first_half);
	ft_mergesort(&second_half);
	*completelist = ft_mergeback(&first_half, &second_half);
	// ft_printf(ANSI_COLOR_CYAN"\n>>>>>>> MERGED BACK COMPLETE LIST <<<<<<<");
	// ft_print_doublyll(*completelist);
}

void				*ft_presort(t_stacks **stacks, t_stack_list **sorted_stacka)
{
	if (((*stacks)->stacka_lst == NULL) || \
	((*stacks)->stacka_lst->next == NULL))
		return (0);
	else
	{
		*sorted_stacka = ft_copy_list((*stacks)->stacka_lst);
		ft_mergesort(sorted_stacka);
		ft_printf("Median = %d \n", ft_find_median(sorted_stacka));
		// ft_printf(ANSI_COLOR_MAGENTA">>>>> SORTED -- <<<<<"ANSI_COLOR_RESET);
		// ft_print_doublyll(*sorted_stacka);
		ft_goalpos_calculation(stacks, *sorted_stacka);
		ft_printf(ANSI_COLOR_MAGENTA">>>>> Stack A ALL <<<<<"ANSI_COLOR_RESET);
		ft_print_doubly_all((*stacks)->stacka_lst);
	}
	return (0);
}
