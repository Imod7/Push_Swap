/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_aux_functions.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/08 21:57:49 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/03/08 21:57:53 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int					ft_exitprogram(t_stack_list **stacklst_ref)
{
	ft_free_list(stacklst_ref);
	return (0);
}

int					check_v_option(char *argv, t_prgm_props *prgm_sets)
{
	if (prgm_sets == NULL)
		return (0);
	if ((argv[0] == '-') && (argv[1] == 'v'))
		prgm_sets->debug_mode = 1;
	prgm_sets->number_operations = 0;
	return (0);
}

t_stack_list		*ft_copy_list(t_stack_list *stacklst)
{
	t_stack_list	*newnode;
	t_stack_list	*newlist;

	// newlist = ft_memalloc(sizeof(t_stack_list));
	newlist = NULL;
	if (stacklst == NULL)
	{
		// ft_printf("\n NULL \n");
		return (NULL);
	}
	else
	{
		while (stacklst != NULL)
		{
			newnode = ft_stack_newnode(stacklst->num);
			ft_stack_addend(&newlist, newnode);
			stacklst = stacklst->next;
			// ft_printf("\nprinting current list");
			// ft_print_doublyll(newlist);
		}
	}
	return (newlist);
}
