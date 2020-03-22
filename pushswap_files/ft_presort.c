/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_presort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/05 13:06:40 by dsaripap       #+#    #+#                */
/*   Updated: 2020/03/21 17:12:49 by dominique     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

/*
** Calculation of median in a sorted linked list
*/

int					ft_find_median(t_stack_list **stacklst)
{
	t_stack_list	*slow;
	t_stack_list	*fast;

	slow = *stacklst;
	fast = *stacklst;
	if (stacklst != NULL)
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

/*
** The splitting part of merge sort 
*/

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
		*ahalf = completelist;
		(*ahalf)->next = NULL;
		*bhalf = NULL;
	}
	else
	{
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

/*
** The merging part of merge sort 
*/

t_stack_list		*ft_mergeback(t_stack_list **ahalf, t_stack_list **bhalf)
{
	t_stack_list	*result_list;

	result_list = NULL;
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

/*
** Merge Sort 
*/

void				ft_mergesort(t_stack_list **completelist)
{
	t_stack_list	*first_half;
	t_stack_list	*second_half;

	first_half = NULL;
	second_half = NULL;
	if ((*completelist)->next == NULL)
		return ;
	ft_splitlist(*completelist, &first_half, &second_half);
	ft_mergesort(&first_half);
	ft_mergesort(&second_half);
	*completelist = ft_mergeback(&first_half, &second_half);
}

void				ft_update_buckets(t_prgm **prgm)
{
	t_stack_list	*sorted;
	int				i;
	int				j;

	sorted = (*prgm)->sorted_stack;
	i = 0;
	j = -1;
	while (sorted != NULL)
	{
		if ((i % (*prgm)->bucket_size) == 0)
		{
			// ft_printf("%d, %d \n", i, (*prgm)->bucket_size);
			j += 1;
		}
		sorted->bucket = j;
		sorted = sorted->next;
		i += 1;
	}
}

void				*ft_presort(t_stacks **stacks, t_prgm *prgm)
{
	int				len;

	len = ft_stack_length((*stacks)->stacka_lst);
	if (((*stacks)->stacka_lst == NULL) || \
	((*stacks)->stacka_lst->next == NULL))
		return (0);
	else
	{
		ft_calculate_buckets(prgm, len);
		ft_printf("Buckets = %d \n", prgm->buckets);
		ft_printf("Bucket Size = %d \n", prgm->bucket_size);
		prgm->sorted_stack = ft_copy_list((*stacks)->stacka_lst);
		ft_mergesort(&(prgm->sorted_stack));
		ft_update_buckets(&prgm);
		ft_metrics_calculation(stacks, prgm, 1);
		ft_printf(ANSI_COLOR_MAGENTA">>>>> Stack A ALL <<<<<"ANSI_COLOR_RESET);
		ft_print_doubly_all((*stacks)->stacka_lst);
		// ft_printf(ANSI_COLOR_MAGENTA">>>>> Sorted Stack <<<<<"ANSI_COLOR_RESET);
		// ft_print_doubly_all(prgm->sorted_stack);
		ft_algorithm(stacks, prgm);
		// ft_printf(ANSI_COLOR_CYAN);
		// ft_printf("Median = %d \n", ft_find_median(&(prgm->sorted_stack)));
		// ft_printf("Length = %d \n", len);
		ft_print_stacks(*stacks);
	}
	return (0);
}
