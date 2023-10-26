/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleperei <aleperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 13:58:11 by aleperei          #+#    #+#             */
/*   Updated: 2023/08/31 11:41:20 by aleperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **stack_org, t_stack **stack_dest)
{
	int		num;

	num = (*stack_org)->value;
	delete_first_node(stack_org);
	lst_adbeg(stack_dest, num);
}

/* from b to a*/
void	pa(t_stack **stack_b, t_stack **stack_a)
{
	if (!(*stack_b))
		return ;
	push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

/* from a to b*/
void	pb(t_stack **stack_a, t_stack **stack_b)
{
	if (!(*stack_a))
		return ;
	push(stack_a, stack_b);
	write(1, "pb\n", 3);
}
