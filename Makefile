# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: dsaripap <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/31 13:44:11 by dsaripap      #+#    #+#                  #
#    Updated: 2020/01/31 16:57:43 by dsaripap      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = checker
LIBFT = libft/libft.a
CC = gcc -Wall -Wextra -Werror -g
CHECKER_SRCDIR = checker_files
CHECKER_OBJDIR = .obj-checker
EXEDIR = ./

RED=\033[0;31m
GREEN=\033[0;32m
CYAN=\033[0;36m
NC=\033[0m # No Color

SRC =	\
		checker.c \
		ft_saveinput.c \
		ft_listfunctions.c \
		ft_freelist.c \
		ft_saveinstructions.c \
		ft_callinstructions.c \
		ft_stackoperations.c \
		ft_bitwise.c \

OBJ = $(SRC:%.c=$(CHECKER_OBJDIR)/%.o)

INCL = libft/libft.a

all: $(EXEDIR)$(NAME)

$(LIBFT):
	@echo "${CYAN} [ * ] ${NC}Calling libft makefile from push_swap"
	@$(MAKE) -C libft

$(EXEDIR)$(NAME): $(OBJ) $(LIBFT)
	@echo "${GREEN} [ + ] ${NC}Creating checker object files"
	@echo "${GREEN} [ + ] ${NC}Creating checker executable"
	@$(CC) $(OBJ) -o $(EXEDIR)$(NAME) $(INCL)

$(CHECKER_OBJDIR)/%.o: $(CHECKER_SRCDIR)/%.c $(INCL)
	@mkdir -p $(CHECKER_OBJDIR)
	@$(CC) -c -o $@ $<

.PHONY: clean

clean:
	@echo "${RED} [ - ] ${NC}Deleting checker object files"
	@rm -rf $(CHECKER_OBJDIR)
	@$(MAKE) clean -C libft

fclean: clean
	@echo "${RED} [ - ] ${NC}Deleting checker executable"
	@rm -f $(EXEDIR)$(NAME)
	@echo "${RED} [ - ] ${NC}Deleting the libft.a file"
	@rm -f $(LIBFT)

re: fclean all

lldb: re
	gcc -g main.c -L. -lft

norm:
	norminette $(SRC) $(INCL) | grep -e "Error" -e "Warning" -B 1
