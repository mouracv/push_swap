/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleperei <aleperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:37:48 by aleperei          #+#    #+#             */
/*   Updated: 2023/08/30 16:00:14 by aleperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack_sw)
{
	t_stack	*head;
	t_stack	*tmp;
	int		num;

	if (!(*stack_sw) || (*stack_sw)->next == NULL)
		return ;
	head = *stack_sw;
	tmp = head->next;
	num = tmp->value;
	if (tmp->next != NULL)
	{
		(*stack_sw)->next = tmp->next;
		tmp->next->prev = (*stack_sw);
		free(tmp);
		tmp = NULL;
	}
	else
	{
		(*stack_sw)->next = NULL;
		free(tmp);
		tmp = NULL;
	}
	*stack_sw = head;
	lst_adbeg(stack_sw, num);
}

void	sa(t_stack **stack_a)
{
	swap(stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_stack **stack_b)
{
	swap(stack_b);
	write(1, "sb\n", 3);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a);
	sb(stack_b);
}
