/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleperei <aleperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 14:02:40 by aleperei          #+#    #+#             */
/*   Updated: 2023/10/19 12:07:20 by aleperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write(1, "ERROR\n", 6);
	exit(EXIT_FAILURE);
}

int	check_arg_2(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (1);
	while (str[i] != '\0')
	{
		if (str[i] == '-' || str[i] == '+' || str[i] == ' ')
			i++;
		else if (ft_is_digit(str[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	c_dup(long nb, char **argv, int i)
{
	i++;
	while (argv[i] != NULL)
	{
		if (ft_atoi(argv[i]) == nb)
			return (1);
		i++;
	}
	return (0);
}

void	check_arg(char **argv, t_stack **stack_a)
{
	long	nb;
	int		i;

	i = 1;
	while (argv[i] != NULL)
	{
		nb = ft_atoi(argv[i]);
		if (c_dup(nb, argv, i) == 1 || check_arg_2(argv[i]) == 1)
		{
			lst_free(stack_a);
			ft_error();
		}
		if (!(*stack_a))
			lst_adbeg(stack_a, nb);
		else
			lst_adend(stack_a, nb);
		i++;
	}
}
