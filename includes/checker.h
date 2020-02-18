/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 12:18:26 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/01/29 13:06:28 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "ft_printf.h"
// # include <stdio.h>
# include <fcntl.h>

# define INSTR_SA		(0)
# define INSTR_SB		(1 << 0)
# define INSTR_SS		(1 << 1)
# define INSTR_PA		(1 | (1 << 0) | (1 << 1))
# define INSTR_PB		(1 << 2)
# define INSTR_RA		(1 | (1 << 0) | (1 << 2))
# define INSTR_RB		((1 << 1) | (1 << 2))
# define INSTR_RR		(1 | (1 << 0) | (1 << 1) | (1 << 2))
# define INSTR_RRA		(1 << 3)
# define INSTR_RRB		(1 | (1 << 0) | (1 << 3))
# define INSTR_RRR		((1 << 1) | (1 << 3))

typedef struct			s_stack_prop
{
	char				stackprop_id;
	struct s_stack		*stack_lst;
}						t_stack_prop;

typedef struct			s_stack
{
	int					num;
	char				stack_id;
	struct s_stack		*next;
	struct s_stack		*prev;
}						t_stack;

typedef int		(*operation_func)(t_stack **stack_a, t_stack **stack_b);

int		ft_swap_a(t_stack **stack_a, t_stack **stack_b);
int		ft_swap_b(t_stack **stack_a, t_stack **stack_b);
int		ft_swap_both(t_stack **stack_a, t_stack **stack_b);
int		ft_push_a(t_stack **stack_a, t_stack **stack_b);
int		ft_push_b(t_stack **stack_a, t_stack **stack_b);
int		ft_rotate_a(t_stack **stack_a, t_stack **stack_b);
int		ft_rotate_b(t_stack **stack_a, t_stack **stack_b);
int		ft_rotate_both(t_stack **stack_a, t_stack **stack_b);
int		ft_reverserotate_a(t_stack **stack_a, t_stack **stack_b);
int		ft_reverserotate_b(t_stack **stack_a, t_stack **stack_b);
int		ft_reverserotate_both(t_stack **stack_a, t_stack **stack_b);

typedef struct			s_instr
{
	int					instruction;
	struct s_instr		*next;
}						t_instr;

/*
** Check User Input functions
*/

int			ft_build_stacka(int argc, char **argv, t_stack	**stack_lst);
int			ft_build_stackb(t_stack_prop **stack_b);
void		ft_print_stacktemp(t_stack_prop *stackp_lst);

/*
** Linked List (=Stack) functions
*/

t_stack		*ft_stack_newnode(int content);
void		ft_stack_addend(t_stack **lst, t_stack *new);
void		ft_print_stack(t_stack *lst);
int			ft_stack_length(t_stack *lst);
void		ft_free_list(t_stack **stack_lst);
int			ft_numexists(t_stack *lst, int num);

/*
** Linked List (=Instructions) functions
*/

int			ft_saveinstructions(t_instr	**instr_lst, char *operation);
void		ft_call_instructfunctions(t_instr *instr_lst, t_stack **stack_a, \
									t_stack **stack_b);
/*
** Auxiliary functions
*/

void		print_binary(int instr);
void		ft_print_instructions(t_instr *lst);

#endif
