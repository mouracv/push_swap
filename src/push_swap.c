/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleperei <aleperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 14:01:24 by aleperei          #+#    #+#             */
/*   Updated: 2023/10/19 12:07:12 by aleperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	esc_sort(int len, t_stack **stack_a, t_stack **stack_b)
{
	if (len == 2)
	{
		sort_2_num(stack_a);
	}
	else if (len == 3)
	{
		sort_3_num(stack_a);
	}
	else if (len == 4)
	{
		sort_4_num(stack_a, stack_b);
	}
	else if (len == 5)
	{
		sort_5_num(stack_a, stack_b);
	}
	else
		big_sort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		len;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
	{
		exit(EXIT_FAILURE);
	}
	check_arg(argv, &stack_a);
	if (check_stack_sort(&stack_a) == 0)
	{
		lst_free(&stack_a);
		lst_free(&stack_b);
		exit(EXIT_SUCCESS);
	}
	len = stack_size(&stack_a);
	esc_sort(len, &stack_a, &stack_b);
	lst_free(&stack_a);
	lst_free(&stack_b);
	return (0);
}
