/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_prgm_functions.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/08 21:57:49 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/04/10 16:41:38 by dominique     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int					ft_exitprogram(t_stack_list **stacklst_ref)
{
	ft_free_list(stacklst_ref);
	return (0);
}

void				print_usage(t_prgm *prgm)
{
	prgm->options |= OPTION_U;
	ft_printf("usage: ./program_name [-u | -vcnf] [num1] [num2] [num3] ...\n");
	ft_printf("program_name can be push_swap or checker\n");
}

void				print_number_of_oper(t_prgm *prgm)
{
	ft_printf(ANSI_COLOR_YELLOW);
	ft_printf("Total number of operations %d\n", prgm->number_operations);
	ft_printf(ANSI_COLOR_RESET);
}

int					set_prgm_options(char *argv, t_prgm *prgm)
{
	size_t			i;

	i = 0;
	// if (prgm == NULL)
	// 	return (0);
	if (argv[i] == '-')
	{
		i += 1;
		// ft_printf("%d = %c \n", argv[i], argv[i]);
		while (argv[i] != 0)
		{
			if (argv[i] == 'u')
			{
				print_usage(prgm);
				return (-1);
			}
			if (argv[i] == 'v')
				prgm->options |= OPTION_V;
			if (argv[i] == 'c')
				prgm->options |= OPTION_C;
			if (argv[i] == 'n')
				prgm->options |= OPTION_N;
			if (argv[i] == 'f')
				prgm->options |= OPTION_F;
			i += 1;
		}
	}
	prgm->number_operations = 0;
	return (0);
}

size_t				check_prgm_options(t_prgm *prgm)
{
	size_t			i;

	i = 0;
	if (prgm->options != 0)
		i = 1;
	return (i);
}

t_stack_list		*ft_copy_list(t_stack_list *stacklst)
{
	t_stack_list	*newnode;
	t_stack_list	*newlist;

	// newlist = ft_memalloc(sizeof(t_stack_list));
	newlist = NULL;
	if (stacklst == NULL)
	{
		return (NULL);
	}
	else
	{
		while (stacklst != NULL)
		{
			newnode = ft_stack_newnode(stacklst->num);
			ft_stack_addend(&newlist, newnode);
			stacklst = stacklst->next;
		}
	}
	return (newlist);
}
