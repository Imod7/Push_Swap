# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: dsaripap <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/31 13:44:11 by dsaripap      #+#    #+#                  #
#    Updated: 2020/02/24 14:00:58 by dsaripap      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME_CHECKER = checker
NAME_PUSHSWAP = push_swap
LIBFT = libft/libft.a
CC = gcc -Wall -Wextra -Werror -g
CHECKER_SRCDIR = checker_files
CHECKER_OBJDIR = .obj-checker
PUSHSWAP_SRCDIR = pushswap_files
PUSHSWAP_OBJDIR = .obj-pushswap
SHARED_SRCDIR = shared_files
SHARED_OBJDIR = .obj-shared
EXEDIR = ./

RED=\033[0;31m
GREEN=\033[0;32m
CYAN=\033[0;36m
NC=\033[0m # No Color

SRC_CHECKER =	\
		checker.c \
		ft_save_instructions.c \
		ft_bitwise.c \

SRC_PUSHSWAP =	\
		push_swap.c \
		sorting.c \
		ft_presort.c \

SRC_SHARED =	\
		ft_save_input.c \
		ft_list_functions.c \
		ft_program_checks.c \
		ft_call_instructions.c \
		ft_freelist.c \
		ft_stack_operations.c \

OBJ_CHECKER = $(SRC_CHECKER:%.c=$(CHECKER_OBJDIR)/%.o)
OBJ_PUSHSWAP = $(SRC_PUSHSWAP:%.c=$(PUSHSWAP_OBJDIR)/%.o)
OBJ_SHARED = $(SRC_SHARED:%.c=$(SHARED_OBJDIR)/%.o)

INCL = libft/libft.a

all: $(EXEDIR)$(NAME_CHECKER) $(EXEDIR)$(NAME_PUSHSWAP) 

$(LIBFT):
	@echo "${CYAN} [ * ] ${NC}Calling libft makefile from push_swap"
	@$(MAKE) -C libft

$(EXEDIR)$(NAME_CHECKER): $(OBJ_CHECKER) $(OBJ_SHARED) $(LIBFT)
	@echo "${GREEN} [ + ] ${NC}Creating checker object files"
	@echo "${GREEN} [ + ] ${NC}Creating shared object files"
	@echo "${GREEN} [ + ] ${NC}Creating checker executable"
	@$(CC) $(OBJ_CHECKER) $(OBJ_SHARED) -o $(EXEDIR)$(NAME_CHECKER) $(INCL)

$(EXEDIR)$(NAME_PUSHSWAP): $(OBJ_PUSHSWAP) $(LIBFT)
	@echo "${GREEN} [ + ] ${NC}Creating push_swap object files"
	@echo "${GREEN} [ + ] ${NC}Creating push_swap executable"
	@$(CC) $(OBJ_PUSHSWAP) $(OBJ_SHARED) -o $(EXEDIR)$(NAME_PUSHSWAP) $(INCL)

$(SHARED_OBJDIR)/%.o: $(SHARED_SRCDIR)/%.c $(INCL)
	@mkdir -p $(SHARED_OBJDIR)
	@$(CC) -c -o $@ $<

$(CHECKER_OBJDIR)/%.o: $(CHECKER_SRCDIR)/%.c $(INCL)
	@mkdir -p $(CHECKER_OBJDIR)
	@$(CC) -c -o $@ $<

$(PUSHSWAP_OBJDIR)/%.o: $(PUSHSWAP_SRCDIR)/%.c $(INCL)
	@mkdir -p $(PUSHSWAP_OBJDIR)
	@$(CC) -c -o $@ $<

.PHONY: clean

clean:
	@echo "${RED} [ - ] ${NC}Deleting checker object files"
	@rm -rf $(CHECKER_OBJDIR)
	@echo "${RED} [ - ] ${NC}Deleting push_swap object files"
	@rm -rf $(PUSHSWAP_OBJDIR)
	@echo "${RED} [ - ] ${NC}Deleting shared object files"
	@rm -rf $(SHARED_OBJDIR)
	@$(MAKE) clean -C libft

fclean: clean
	@echo "${RED} [ - ] ${NC}Deleting checker executable"
	@rm -f $(EXEDIR)$(NAME_CHECKER)
	@echo "${RED} [ - ] ${NC}Deleting push_swap executable"
	@rm -f $(EXEDIR)$(NAME_PUSHSWAP)
	@echo "${RED} [ - ] ${NC}Deleting the libft.a file"
	@rm -f $(LIBFT)

re: fclean all

lldb: re
	gcc -g main.c -L. -lft

norm:
	norminette $(SRC) $(INCL) | grep -e "Error" -e "Warning" -B 1
