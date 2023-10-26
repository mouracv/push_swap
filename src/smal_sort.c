/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smal_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleperei <aleperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:15:53 by aleperei          #+#    #+#             */
/*   Updated: 2023/08/30 15:59:19 by aleperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2_num(t_stack **stack_a)
{
	if ((*stack_a)->value > (*stack_a)->next->value)
	{
		sa(stack_a);
	}
}

void	sort_3_num(t_stack **stack_a)
{
	while (check_stack_sort(stack_a) != 0)
	{
		if (look_max(stack_a) == 0)
		{
			ra(stack_a);
		}
		else if (look_max(stack_a) == 1)
		{
			rra(stack_a);
		}
		if ((*stack_a)->value > (*stack_a)->next->value)
			sa(stack_a);
	}
}

void	sort_4_num(t_stack **stack_a, t_stack **stack_b)
{
	move_a_top(stack_a, look_mini(stack_a));
	if (check_stack_sort(stack_a) == 0)
		return ;
	pb(stack_a, stack_b);
	sort_3_num(stack_a);
	pa(stack_b, stack_a);
}

void	sort_5_num(t_stack **stack_a, t_stack **stack_b)
{
	while (stack_size(stack_a) > 3)
	{
		move_a_top(stack_a, look_mini(stack_a));
		pb(stack_a, stack_b);
	}
	if (check_stack_sort(stack_a) == 1)
		sort_3_num(stack_a);
	if ((*stack_b)->value < (*stack_b)->next->value)
	{
		sb(stack_b);
	}
	pa(stack_b, stack_a);
	pa(stack_b, stack_a);
}
