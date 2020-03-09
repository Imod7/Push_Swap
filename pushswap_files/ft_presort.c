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

// int					ft__find_median()
// {

// }

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

void				*ft_presort(t_stack_list *stack_a, t_stack_list **sorted_stacka)
{
	if ((stack_a == NULL) || (stack_a->next == NULL))
		return (stack_a);
	else
	{
		// &(*stack_a)->stack_lst
		// (*sorted_stacka)->stack_id = 'C';
		*sorted_stacka = ft_copy_list(stack_a);
		ft_mergesort(sorted_stacka);
	}
	return (0);
}
