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
OBJDIR = checker_files
EXEDIR = ./

RED=\033[0;31m
GREEN=\033[0;32m
CYAN=\033[0;36m
NC=\033[0m # No Color

SRC =	\
		checker.c \
		ft_checkinput.c \
		ft_listfunctions.c \
		ft_freelist.c \
		ft_instructions.c \
		ft_stackoperations.c \
		ft_bitwise.c \

OBJ = $(SRC:%.c=$(OBJDIR)/%.o)

INCL = libft/libft.a

all: $(EXEDIR)$(NAME)

$(LIBFT):
	@echo "${CYAN}Calling libft makefile from push_swap${NC}"
	@$(MAKE) -C libft

$(EXEDIR)$(NAME): $(OBJ) $(LIBFT)
	@echo "${GREEN}Making checker${NC}"
	$(CC) $(OBJ) -o $(EXEDIR)$(NAME) $(INCL) 

$(OBJDIR)/%.o: %.c $(INCL)
	@$(CC) -c -o $@ $<

.PHONY: clean

clean:
	@echo "${RED}Cleaning all object files of checker${NC}"
	@rm -f $(OBJ)
	@$(MAKE) clean -C libft

fclean: clean
	@echo "${RED}Deleting checker executable${NC}"
	@rm -f $(EXEDIR)$(NAME)
	@echo "${CYAN}Calling fclean of libft${NC}"
	@$(MAKE) fclean -C libft

re: fclean all

lldb: re
	gcc -g main.c -L. -lft

norm:
	norminette $(SRC) $(INCL) | grep -e "Error" -e "Warning" -B 1
