/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 12:08:15 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/04/04 17:22:32 by dominique     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int					main(int argc, char **argv)
{
	t_prgm			*prgm;
	t_stacks		*stacks;
	// char			operation[BUFFER_SIZE + 1];
	// int				buffer_read;
	int				i;
	char 			*returned_line;

	stacks = ft_memalloc(sizeof(t_stacks));
	stacks->stacka_lst = NULL;
	// stacks->stackb_lst = ft_memalloc(sizeof(t_stack_list));
	prgm = ft_memalloc(sizeof(t_prgm));
	prgm->instr_lst = NULL;
	prgm->exec = 0;
	if (argc < 2)
		return (0);
	else
	{
		if (set_prgm_options(argv[1], prgm) == -1)
			return (0);
		// print_binary(prgm_settings->debug_mode);
		if (ft_build_stacka(argc, argv, &stacks, prgm) == -1)
			return (ft_exitprogram(&(stacks->stacka_lst)));
	}
	ft_build_stackb(&stacks);
	// ft_bzero(operation, BUFFER_SIZE + 1);
	// buffer_read = read(0, operation, BUFFER_SIZE);
	// while (buffer_read != 0)
	i = 1;
	while (i > 0)
	{
		i = get_next_line(0, &returned_line);
		// ft_printf("buffer = %s\n", returned_line);
		if (i != 0)
		{
			if (ft_saveinstructions(prgm, stacks, returned_line) == -1)
				return (ft_exitprogram(&(stacks->stacka_lst)));
		}
		// ft_bzero(returned_line, BUFFER_SIZE + 1);
		// buffer_read = read(0, operation, BUFFER_SIZE);
	}
	// ft_print_instructions(instr_lst);
	// ft_printf("\nStack A");
	// ft_print_doublyll(stacks->stacka_lst);
	// ft_printf("\nStack B");
	// ft_print_doublyll(stacks->stackb_lst);
	ft_presort(prgm, &stacks);
	// ft_printf("sorted stack\n");
	// ft_print_doublyll(prgm->sorted_stack);
	// ft_print_instructions(prgm);
	ft_call_operations(prgm->instr_lst, &stacks, prgm);
	if (prgm->options & OPTION_N)
		print_number_of_oper(prgm);
	// ft_print_stacks(stacks);
	if (ft_check_ifsorted(prgm, stacks) == -1)
		return (-1);
	// ft_printf("Number of Operations : %d", prgm->number_operations);
	ft_exitprogram(&(stacks->stacka_lst));
	ft_exitprogram(&(stacks->stackb_lst));
	// while (1)
	// 	;
	return (0);
}
