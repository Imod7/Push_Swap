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

typedef struct 			s_prgm_props
{
	int					debug_mode;
	int					number_operations;
}						t_prgm_props;

typedef struct			s_stack
{
	char				stack_id;
	struct s_stack_list	*stack_lst;
}						t_stack;

typedef struct			s_stack_list
{
	int					num;
	struct s_stack_list	*next;
	struct s_stack_list	*prev;
}						t_stack_list;

typedef int		(*operation_func)(t_stack_list **stack_a, t_stack_list **stack_b);

int		ft_swap_a(t_stack_list **stack_a, t_stack_list **stack_b);
int		ft_swap_b(t_stack_list **stack_a, t_stack_list **stack_b);
int		ft_swap_both(t_stack_list **stack_a, t_stack_list **stack_b);
int		ft_push_a(t_stack_list **stack_a, t_stack_list **stack_b);
int		ft_push_b(t_stack_list **stack_a, t_stack_list **stack_b);
int		ft_rotate_a(t_stack_list **stack_a, t_stack_list **stack_b);
int		ft_rotate_b(t_stack_list **stack_a, t_stack_list **stack_b);
int		ft_rotate_both(t_stack_list **stack_a, t_stack_list **stack_b);
int		ft_reverserotate_a(t_stack_list **stack_a, t_stack_list **stack_b);
int		ft_reverserotate_b(t_stack_list **stack_a, t_stack_list **stack_b);
int		ft_reverserotate_both(t_stack_list **stack_a, t_stack_list **stack_b);

typedef struct			s_instr
{
	int					instruction;
	struct s_instr		*next;
}						t_instr;

/*
** Program Checks
*/

int					ft_exitprogram(int signal, t_stack_list **stacklst_ref);
int					check_v_option(char *argv, t_prgm_props *prgm_sets);

/*
** Check User Input functions
*/

int			ft_build_stacka(int argc, char **argv, t_stack **stack_lst, \
							t_prgm_props *prgm_sets);
int			ft_build_stackb(t_stack **stack_b);

/*
** Linked List (=Stack) functions
*/

t_stack_list		*ft_stack_newnode(int content);
void				ft_stack_addend(t_stack_list **lst, t_stack_list *new);
void				ft_print_stack(t_stack *lst);
void				ft_print_doublyll(t_stack_list *temp);
int					ft_stack_length(t_stack_list *lst);
void				ft_free_list(t_stack_list **stack_lst);
int					ft_numexists(t_stack_list *lst, int num);

/*
** Linked List (=Instructions) functions
*/

int			ft_saveinstructions(t_instr	**instr_lst, char *operation);
void		ft_call_instructfunctions(t_instr *instr_lst, \
								t_stack **stack_a, t_stack **stack_b, \
								t_prgm_props *prgm_sets);
/*
** Auxiliary functions
*/

void		print_binary(int instr);
void		ft_print_instructions(t_instr *lst);

/*
** Sorting functions
*/

void		ft_sorting(t_prgm_props *prgm_sets, t_stack **stack_a, \
						t_stack **stack_b);

#endif
