/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 12:18:26 by dsaripap       #+#    #+#                */
/*   Updated: 2020/03/26 14:33:57 by dominique     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "ft_printf.h"
# include <fcntl.h>

# define INSTR_SA		(1 << 0)
# define INSTR_SB		(1 << 1)
# define INSTR_SS		(1 << 2)
# define INSTR_PA		(1 << 3)
# define INSTR_PB		(1 << 4)
# define INSTR_RA		(1 << 5)
# define INSTR_RB		(1 << 6)
# define INSTR_RR		(1 << 7)
# define INSTR_RRA		(1 << 8)
# define INSTR_RRB		(1 << 9)
# define INSTR_RRR		(1 << 10)

typedef struct			s_prgm
{
	int					debug_mode;
	size_t				exec;
	int					number_operations;
	int					buckets;
	int					bucket_size;
	struct s_instr		*instr_lst;
	struct s_stack_list	*sorted_stack;
}						t_prgm;

typedef struct			s_instr
{
	size_t				instruction;
	struct s_instr		*next;
}						t_instr;

/*
** Testing on using the 1 struct t_stacks with my 2 stacks (A, B) inside
*/

typedef struct			s_stacks
{
	char				stacka_id;
	struct s_stack_list	*stacka_lst;
	char				stackb_id;
	struct s_stack_list	*stackb_lst;
}						t_stacks;

typedef struct			s_stack_list
{
	int					num;
	struct s_stack_list	*next;
	struct s_stack_list	*prev;
	int					cur_pos;
	int					goal_pos;
	int					bucket;
	int					dis_from_goal;
	int					dis_from_top;
}						t_stack_list;

typedef int			(*operation_func)(t_prgm *prgm, t_stacks **stacks);

int		ft_swap_a(t_prgm *prgm, t_stacks **stacks);
int		ft_swap_b(t_prgm *prgm, t_stacks **stacks);
int		ft_swap_both(t_prgm *prgm, t_stacks **stacks);
int		ft_push_a(t_prgm *prgm, t_stacks **stacks);
int		ft_push_b(t_prgm *prgm, t_stacks **stacks);
int		ft_rotate_a(t_prgm *prgm, t_stacks **stacks);
int		ft_rotate_b(t_prgm *prgm, t_stacks **stacks);
int		ft_rotate_both(t_prgm *prgm, t_stacks **stacks);
int		ft_reverserotate_a(t_prgm *prgm, t_stacks **stacks);
int		ft_reverserotate_b(t_prgm *prgm, t_stacks **stacks);
int		ft_reverserotate_both(t_prgm *prgm, t_stacks **stacks);

/*
** Program Checks
*/

// int					ft_exitprogram(int signal, t_stack_list **stacklst_ref);
int					ft_exitprogram(t_stack_list **stacklst_ref);
int					check_v_option(char *argv, t_prgm *prgm_sets);

/*
** Check User Input functions
*/

int			ft_build_stacka(int argc, char **argv, t_stacks **stacks, \
							t_prgm *prgm_sets);
int			ft_build_stackb(t_stacks **stacks);

/*
** Linked List functions related to the Stack List
*/

t_stack_list		*ft_stack_newnode(int content);
void				ft_stack_addend(t_stack_list **lst, t_stack_list *new);
int					ft_stack_length(t_stack_list *lst);
void				ft_free_list(t_stack_list **stack_lst);
int					ft_numexists(t_stack_list *lst, int num);
t_stack_list		*ft_copy_list(t_stack_list *stacklst);

/*
** Printing functions
*/

void				ft_print_doublyll(t_stack_list *temp);
void				ft_print_doubly_all(t_stack_list *temp);
void				ft_print_stacks(t_stacks *stacks);
void				ft_print_instructions(t_prgm *prgm);

/*
** Linked List functions related to the Instructions List
*/

int			ft_saveinstructions(t_prgm *prgm, char *operation);
void		ft_call_instructfunctions(t_instr *instr_lst, t_stacks **stacks, \
										t_prgm *prgm_sets);
/*
** Auxiliary functions
*/

// void		print_binary(int instr);

/*
** Sorting functions
*/

void		ft_sorting(t_prgm *prgm, t_stacks **stacks);
void		ft_presort(t_prgm *prgm, t_stacks **stacks);
// int			ft_find_median(t_stack_list **stacklst);

/*
** Algorithm functions
*/

void		ft_metrics_calculation(t_prgm *prgm, t_stacks **stacks, int init);
void		ft_sort_three(t_prgm *prgm, t_stacks **stacks);
void		ft_calculate_buckets(t_prgm *prgm, int len);
void		ft_update_buckets(t_prgm **prgm);
void		ft_algorithm(t_prgm *prgm, t_stacks **stacks);
int			ft_check_ifsorted(t_prgm *prgm, t_stacks *stacks);

#endif
