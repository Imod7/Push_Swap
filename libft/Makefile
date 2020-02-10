# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: dsaripap <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/03/27 14:38:43 by dsaripap      #+#    #+#                  #
#    Updated: 2020/02/08 10:25:28 by dsaripap      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

PROG = prog
NAME = libft.a
CC = gcc
FLAGS = -Wall -Wextra -Werror -g
OBJDIR = ft_printf

RED=\033[0;31m
GREEN=\033[0;32m
NC=\033[0m # No Color

SRC = ft_atoi.c \
	  ft_bzero.c \
	  ft_del.c \
	  ft_itoa.c \
	  ft_isalpha.c \
	  ft_isdigit.c \
	  ft_isalnum.c \
	  ft_isascii.c \
	  ft_isprint.c \
	  ft_lstlen.c \
	  ft_lstfindelem.c \
	  ft_lstsort.c \
	  ft_lstnew.c \
	  ft_lstdelone.c \
	  ft_lstdel.c \
	  ft_lstadd.c \
	  ft_lstiter.c \
	  ft_lstmap.c \
	  ft_lstaddend.c \
	  ft_memalloc.c \
	  ft_memdel.c \
	  ft_memset.c \
	  ft_memcpy.c \
	  ft_memccpy.c \
	  ft_memmove.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_putchar.c \
	  ft_putstr.c \
	  ft_putendl.c \
	  ft_putnbr.c \
	  ft_putchar_fd.c \
	  ft_putstr_fd.c \
	  ft_putendl_fd.c \
	  ft_putnbr_fd.c \
	  ft_strlen.c \
	  ft_strdup.c \
	  ft_strcpy.c \
	  ft_strncpy.c \
	  ft_strcat.c \
	  ft_strncat.c \
	  ft_strlcat.c \
	  ft_strchr.c \
	  ft_strrchr.c \
	  ft_strstr.c \
	  ft_strnstr.c \
	  ft_strcmp.c \
	  ft_strncmp.c \
	  ft_strnew.c \
	  ft_strdel.c \
	  ft_strclr.c \
	  ft_striter.c \
	  ft_striteri.c \
	  ft_strmap.c \
	  ft_strmapi.c \
	  ft_strequ.c \
	  ft_strnequ.c \
	  ft_strsub.c \
	  ft_strjoin.c \
	  ft_strtrim.c \
	  ft_strsplit.c \
	  ft_strarrtolst.c \
	  ft_strreplace.c \
	  ft_toupper.c \
	  ft_tolower.c \
	  get_next_line.c \

SRCPRINTF = ft_printf.c \
	  		ft_printf_genericfunc.c \
			ft_clear_all.c \
			ft_save_flags.c \
			ft_check_specifier.c \
			ft_checks_unsigned.c \
			ft_common_functions.c \
			ft_print_integer.c \
			ft_print_unsigned.c \
			ft_print_float.c \
			ft_print_alpha_other.c \
			ft_print_memory.c \
			ft_print_number.c \
			ft_print_format.c \
			ft_print_binary.c \
			ft_putnbr_base.c \
			ft_number_len.c \
			ft_float.c \
			ft_float_str_addmultiply.c \
			ft_float_str_division.c \
			ft_float_round.c \
			ft_float_auxfunctions.c \
			ft_float_inf_nan.c \
			ft_float_len.c \
			ft_writer_manager.c \
			ft_zero_arg.c \

OBJLIBFT = $(SRC:%.c=%.o) 
OBJPRINTF = $(SRCPRINTF:%.c=$(OBJDIR)/%.o)

INCL = ../includes/

all: $(NAME)

$(NAME): $(OBJLIBFT) $(OBJPRINTF)
	@echo "${GREEN}Created all object files of libft & ft_printf${NC}"
	@echo "${GREEN}Making libft.a${NC}"
	@ar crs $(NAME) $(OBJLIBFT) $(OBJPRINTF)

# Object Files of printf
$(OBJDIR)/%.o: %.c $(INCL)
	@$(CC) $(FLAGS) -c -o $@ $<

# Object Files of libft
%.o: %.c $(INCL)
	@$(CC) $(FLAGS) -c -o $@ $<

.PHONY: clean

clean:
	@echo "${RED}Cleaning all object files of libft & ft_printf${NC}"
	@rm -f $(OBJLIBFT) $(OBJPRINTF)

fclean: clean
	@echo "${RED}Deleting the libft.a file${NC}"
	@rm -f $(NAME)

re: fclean all

test:
	@$(CC) $(FLAGS) main.c -L. -lft -o test.exe

lldb: re
	gcc -g main.c -L. -lft

$(PROG): $(NAME)
	$(CC) $(FLAGS) -o $(PROG) main.c -L. -lft

norm:
	norminette $(SRC) $(INCL) | grep -e "Error" -e "Warning" -B 1
