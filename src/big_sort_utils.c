/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleperei <aleperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 13:34:52 by aleperei          #+#    #+#             */
/*   Updated: 2023/08/30 16:49:17 by aleperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_b_top(t_stack **stack_t, int pos)
{
	if (pos == 0)
		return ;
	if (pos >= (stack_size(stack_t) / 2))
	{
		pos = stack_size(stack_t) - pos;
		while (pos > 0)
		{
			rrb(stack_t);
			pos--;
		}
	}
	else
	{
		while (pos > 0)
		{
			rb(stack_t);
			pos--;
		}
	}
}

void	move_a_top(t_stack **stack_t, int pos)
{
	if (pos == 0)
		return ;
	if (pos >= (stack_size(stack_t) / 2))
	{
		pos = stack_size(stack_t) - pos;
		while (pos > 0)
		{
			rra(stack_t);
			pos--;
		}
	}
	else
	{
		while (pos > 0)
		{
			ra(stack_t);
			pos--;
		}
	}
}

int	move_count(t_stack **stack_m, int num)
{
	t_stack	*head;
	int		counter;

	head = *stack_m;
	counter = 0;
	while (head != NULL && head->value != num)
	{
		counter++;
		head = head->next;
	}
	if (counter > (stack_size(stack_m) / 2))
		return (stack_size(stack_m) - counter);
	return (counter);
}

int	look_bf(int num, t_stack **stack_a)
{
	t_stack	*head;
	int		bf;

	head = *stack_a;
	bf = INT_MAX;
	while (head != NULL)
	{
		if (head->value > num && bf > head->value)
		{
			bf = head->value;
		}
		head = head->next;
	}
	return (bf);
}

void	brain(t_stack **stack_a, t_stack **stack_b, t_table *box)
{
	t_stack	*head;
	int		bf;
	int		less_moves;

	head = *stack_b;
	less_moves = INT_MAX;
	while (head != NULL)
	{
		bf = look_bf(head->value, stack_a);
		(box)->move_cost = move_count(stack_a, bf) + move_count(stack_b,
				head->value);
		if ((box)->move_cost < less_moves)
		{
			(box)->num = head->value;
			(box)->bf = bf;
			less_moves = (box)->move_cost;
		}
		head = head->next;
	}
	move_a_top(stack_a, look_pos(stack_a, (box)->bf));
	move_b_top(stack_b, look_pos(stack_b, (box)->num));
}
