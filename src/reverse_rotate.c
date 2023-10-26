/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleperei <aleperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:39:13 by aleperei          #+#    #+#             */
/*   Updated: 2023/08/25 16:40:28 by aleperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	delete_last_node(t_stack **stack_d)
{
	t_stack	*head;

	head = *stack_d;
	if ((*stack_d)->next == NULL)
	{
		(*stack_d) = NULL;
		return ;
	}
	while ((*stack_d)->next != NULL)
		(*stack_d) = (*stack_d)->next;
	(*stack_d) = (*stack_d)->prev;
	free((*stack_d)->next);
	(*stack_d)->next = NULL;
	*stack_d = head;
}

void	reverse_rotate(t_stack **stack_rr)
{
	t_stack	*head;
	int		num;

	if (!(*stack_rr) || !(*stack_rr)->next)
		return ;
	head = *stack_rr;
	while (head->next != NULL)
		head = head->next;
	num = head->value;
	lst_adbeg(stack_rr, num);
	delete_last_node(stack_rr);
}

void	rra(t_stack **stack_a)
{
	reverse_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **stack_b)
{
	reverse_rotate(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
