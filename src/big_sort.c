/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleperei <aleperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 14:25:35 by aleperei          #+#    #+#             */
/*   Updated: 2023/09/08 10:49:06 by aleperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	med_a(t_stack **stack_a)
{
	t_stack	*tmp;
	int		med;
	int		num;

	tmp = *stack_a;
	num = 0;
	while (tmp != NULL)
	{
		num = num + tmp->value;
		tmp = tmp->next;
	}
	med = num / stack_size(stack_a);
	return (med);
}

void	big_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_table	box;

	while (stack_size(stack_a) > 5)
	{
		if ((*stack_a)->value < med_a(stack_a))
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	sort_5_num(stack_a, stack_b);
	while ((*stack_b) != NULL)
	{
		brain(stack_a, stack_b, &box);
		pa(stack_b, stack_a);
	}
	move_a_top(stack_a, look_mini(stack_a));
}
