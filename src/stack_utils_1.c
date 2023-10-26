/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleperei <aleperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 11:18:36 by aleperei          #+#    #+#             */
/*   Updated: 2023/08/30 13:26:22 by aleperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack **node)
{
	t_stack	*head;
	int		i;

	head = *node;
	i = 0;
	while (head != NULL)
	{
		head = head->next;
		i++;
	}
	return (i);
}

int	check_stack_sort(t_stack **stack_sort)
{
	t_stack	*prev_val;
	t_stack	*next_val;

	prev_val = *stack_sort;
	next_val = (*stack_sort)->next;
	while (next_val != NULL)
	{
		if (prev_val->value > next_val->value)
			return (1);
		prev_val = next_val;
		next_val = next_val->next;
	}
	return (0);
}

int	look_max(t_stack **stack_m)
{
	t_stack	*head;
	int		max;
	int		i;
	int		pos;

	head = *stack_m;
	max = INT_MIN;
	i = 0;
	pos = -1;
	while (head != NULL)
	{
		if (head->value > max)
		{
			pos = i;
			max = head->value;
		}
		head = head->next;
		i++;
	}
	return (pos);
}

int	look_mini(t_stack **stack_m)
{
	t_stack	*head;
	int		mini;
	int		pos;
	int		counter_pos;

	head = (*stack_m);
	mini = (*stack_m)->value;
	pos = 0;
	counter_pos = 0;
	while (head != NULL)
	{
		if (head->value < mini)
		{
			mini = head->value;
			pos = counter_pos;
		}
		head = head->next;
		counter_pos++;
	}
	return (pos);
}

int	look_pos(t_stack **stack_p, int num)
{
	t_stack	*head;
	int		pos;

	head = *stack_p;
	pos = 0;
	while (head != NULL && head->value != num)
	{
		pos++;
		head = head->next;
	}
	return (pos);
}
