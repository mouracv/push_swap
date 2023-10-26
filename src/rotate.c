/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleperei <aleperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:38:33 by aleperei          #+#    #+#             */
/*   Updated: 2023/08/31 12:06:31 by aleperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	delete_first_node(t_stack **stack_d)
{
	t_stack	*head;

	head = *stack_d;
	if (head->next == NULL)
	{
		free(head);
		(*stack_d) = NULL;
		return ;
	}
	head = head->next;
	free(head->prev);
	head->prev = NULL;
	*stack_d = head;
}

void	rotate(t_stack **stack_r)
{
	t_stack	*head;
	int		num;

	if (!(*stack_r) || !(*stack_r)->next)
		return ;
	head = *stack_r;
	num = head->value;
	lst_adend(stack_r, num);
	delete_first_node(stack_r);
}

void	ra(t_stack **stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_stack **stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}
