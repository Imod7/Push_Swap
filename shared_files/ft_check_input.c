/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_check_input.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <dsaripap@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/04 17:22:24 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/06/07 10:05:42 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** This function calculates the length of the string represented as a number so
** If there is a plus sign in the beginning is NOT added to the length
** If there is a minus sign in the beginning it is added to the length
** If there are leading zeros they are omitted in the calculation of the
** length
*/

static size_t		ft_calculate_length(char *str)
{
	int				i;
	size_t			len;

	i = 0;
	len = 0;
	while (str[i] != '\0')
	{
		if (i == 0 && str[i] == '-')
			len += 1;
		else if (i == 0 && str[i] == '+')
			;
		else if ((i == 0 || i == 1) && str[i] == '0')
		{
			while (str[i] == '0')
				i++;
			i--;
		}
		else if (str[i] >= 48 || str[i] <= 57)
		{
			len += 1;
		}
		i++;
	}
	return (len);
}

/*
** We call first the ft_calculate_length function which
** calculates the length of the string represented as a number.
** Then checks if the length of the string is :
** <= 10 digits if 1st digit is a plus sign
** <= 11 digits if 1st digit is a minus sign
** <= 10 digits if there are no signs in front
*/

int					ft_check_str_length(char *str)
{
	size_t			len;

	len = ft_calculate_length(str);
	if (str[0] == '+' && len > 10)
		return (ERROR);
	else if (str[0] == '-' && len > 11)
		return (ERROR);
	else if (str[0] != '+' && str[0] != '-' && len > 10)
		return (ERROR);
	return (SUCCESS);
}

static int			ft_isnum(char *str)
{
	int				i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((i == 0) && (str[0] == '+' || str[0] == '-'))
			;
		else if (str[i] < 48 || str[i] > 57)
			return (-1);
		i++;
	}
	return (SUCCESS);
}

int					ft_isvalid(char *argv, long long num)
{
	if ((ft_isnum(argv) == -1) || (num > 2147483647) || (num < -2147483648))
		return (ERROR);
	else
		return (SUCCESS);
}
