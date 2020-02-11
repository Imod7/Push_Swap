/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bitwise.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/10 09:55:39 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/02/10 09:55:41 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	print_binary(int instr)
{
	unsigned short	mask;
	int				bit;

	bit = 16;
	while (bit >= 0)
	{
		mask = instr >> bit;
		if (mask & 1)
		{
			ft_printf(ANSI_COLOR_CYAN);
			ft_printf("1 ");
			ft_printf(ANSI_COLOR_RESET);
		}
		else
			ft_printf("0 ");
		//printf("\n");
		bit--;
	}
	ft_printf("\n");
}
