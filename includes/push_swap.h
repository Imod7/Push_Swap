/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 12:18:26 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/04/16 19:04:54 by dominique     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include <fcntl.h>

typedef enum			e_instruction
{
	INSTR_SA = (1 << 0),
	INSTR_SB = (1 << 1),
	INSTR_SS = (1 << 2),
	INSTR_PA = (1 << 3),
	INSTR_PB = (1 << 4),
	INSTR_RA = (1 << 5),
	INSTR_RB = (1 << 6),
	INSTR_RR = (1 << 7),
	INSTR_RRA = (1 << 8),
	INSTR_RRB = (1 << 9),
	INSTR_RRR = (1 << 10)
}						t_instruction;

typedef enum			e_option
{
	OPTION_U = (1 << 0),
	OPTION_V = (1 << 1),
	OPTION_C = (1 << 2),
	OPTION_N = (1 << 3),
	OPTION_F = (1 << 4)
}						t_option;

typedef struct			s_instr
{
	t_instruction		instruction;
	struct s_instr		*next;
}						t_instr;

typedef struct			s_stack_list
{
	int					num;
	struct s_stack_list	*next;
	struct s_stack_list	*prev;
	size_t				pos_index;
	int					bucket;
	int					dis_from_top;
}						t_stack_list;

/*
** The struct t_stacks contains the 2 stacks (A, B) inside
** and their corresponding id
*/

typedef struct			s_stacks
{
	char				stacka_id;
	t_stack_list		*stacka_lst;
	char				stackb_id;
	t_stack_list		*stackb_lst;
}						t_stacks;

typedef struct			s_prgm
{
	t_stacks			*stacks;
	t_stack_list		*sorted_stack;
	t_instr				*instr_lst;
	t_option			options;
	size_t				stack_len;
	size_t				stack_middle;
	t_stack_list		*top;
	t_stack_list		*bottom;
	size_t				exec;
	int					number_operations;
	int					buckets;
	int					bucket_size;
}						t_prgm;

typedef int				(*t_operation_func)(t_prgm *prgm);

int						ft_swap_b(t_prgm *prgm);
int						ft_swap_a(t_prgm *prgm);
int						ft_swap_both(t_prgm *prgm);
int						ft_push_a(t_prgm *prgm);
int						ft_push_b(t_prgm *prgm);
int						ft_rotate_a(t_prgm *prgm);
int						ft_rotate_b(t_prgm *prgm);
int						ft_rotate_both(t_prgm *prgm);
int						ft_reverserotate_a(t_prgm *prgm);
int						ft_reverserotate_b(t_prgm *prgm);
int						ft_reverserotate_both(t_prgm *prgm);

/*
** Program Checks
*/

void					prgm_initialize(t_prgm *prgm, size_t flag);
// int					ft_exitprogram(int signal, t_stack_list **stacklst_ref);
int						ft_exitprogram(t_prgm *prgm);
int						set_prgm_options(char *argv, t_prgm *prgm);
size_t					check_prgm_options(t_prgm *prgm);

/*
** Check User Input functions
*/

int						ft_build_stacka(int argc, char **argv, t_prgm *prgm);
// int						ft_build_stackb(t_stacks **stacks);
int						ft_build_stackb(t_stacks *stacks);

/*
** Linked List functions related to the Stack List
*/

t_stack_list			*ft_stack_newnode(int content);
void					ft_stack_addend(t_stack_list **lst, t_stack_list *new);
int						ft_stack_len(t_stack_list *lst);
void					ft_free_list(t_stack_list *stack_lst);
int						ft_numexists_instack(t_stack_list *lst, int num);
t_stack_list			*ft_copy_list(t_stack_list *stacklst);

/*
** Printing functions
*/

void					ft_print_doublyll(t_stack_list *temp);
void					ft_print_doubly_all(t_stack_list *temp);
void					ft_print_stacks(t_stacks *stacks);
// void					ft_print_instructions(t_prgm *prgm);

/*
** Linked List functions related to the Instructions List
*/

int						ft_saveinstructions(t_prgm *prgm, char *operation);
// void					ft_call_operations(t_instr *instr_lst, \
// 										t_stacks **stacks, t_prgm *prgm_sets);
void					ft_call_operations(t_instr *instr_lst, t_prgm *prgm);
void					ft_checkinstruction(size_t instruction);
/*
** Auxiliary functions
*/

// void		print_binary(int instr);

/*
** Sorting functions
*/

void					ft_sorting(t_prgm *prgm);
// void					ft_presort(t_prgm *prgm, t_stacks **stacks);
void					ft_presort(t_prgm *prgm);
// int					ft_find_median(t_stack_list **stacklst);
int						ft_sort_small(t_prgm *prgm);

/*
** Algorithm functions
*/

void					ft_metrics_calculation(t_prgm *prgm, int init);
void					ft_sort_three(t_prgm *prgm);
void					ft_calculate_buckets(t_prgm *prgm);
void					ft_update_buckets(t_prgm *prgm);
void					ft_algorithm(t_prgm *prgm);
int						ft_check_ifsorted(t_prgm *prgm);
void					ft_move_num_to_top_of_stack(t_prgm *prgm, size_t flag);

/*
** Bonus options & descriptive function
*/

void					print_number_of_oper(t_prgm *prgm);
void					ft_operation_descr(t_prgm *prgm);

/*
** Functions related to instruction/operations list
*/

void					ft_setinstruction(char *operation, t_instr *instr);
// void					ft_instr_addend(t_prgm **prgm, t_instr *new);
void					ft_instr_addend(t_instr **instr_lst, t_instr *new);

#endif
