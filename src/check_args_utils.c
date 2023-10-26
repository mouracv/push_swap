/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleperei <aleperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 14:06:46 by aleperei          #+#    #+#             */
/*   Updated: 2023/09/09 15:32:16 by aleperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_limits(long int nb)
{
	if (nb > INT_MAX || nb < INT_MIN)
		ft_error();
}

int	ft_is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int			sn;
	long int	num;

	sn = 1;
	num = 0;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		sn = (*str == '+') - (*str == '-');
		str++;
	}
	if (!(*str && ft_is_digit(*str)))
		ft_error();
	while (*str)
	{
		if (ft_is_digit(*str) == 1)
			num = num * 10 + *str - '0';
		else
			ft_error();
		str++;
	}
	check_limits(num * sn);
	return (num * sn);
}
