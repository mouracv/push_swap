/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleperei <aleperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 14:00:01 by aleperei          #+#    #+#             */
/*   Updated: 2023/09/08 10:49:55 by aleperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_free(t_stack **node)
{
	t_stack	*tmp;

	if (!(*node))
		return ;
	while ((*node) != NULL)
	{
		tmp = (*node)->next;
		free(*node);
		(*node) = tmp;
	}
}

void	lst_adbeg(t_stack **head, int nb)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
	{
		lst_free(head);
		ft_error();
		return ;
	}
	node->prev = NULL;
	node->value = nb;
	node->next = *head;
	if ((*head) != NULL)
	{
		(*head)->prev = node;
	}
	(*head) = node;
}

void	lst_adend(t_stack **head, int nb)
{
	t_stack	*node;
	t_stack	*tmp;

	tmp = *head;
	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
	{
		lst_free(head);
		ft_error();
		return ;
	}
	node->value = nb;
	node->next = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = node;
	node->prev = tmp;
}
