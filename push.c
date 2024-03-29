/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 09:15:25 by dabae             #+#    #+#             */
/*   Updated: 2024/02/23 13:35:16 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

static void	push(t_stack **a, t_stack **b)
{
	t_stack	*node_to_be_pushed;

	if (!*a)
		return ;
	node_to_be_pushed = *a;
	*a = (*a)->next;
	if (*a)
		(*a)->prev = NULL;
	node_to_be_pushed->prev = NULL;
	if (!*b)
	{
		*b = node_to_be_pushed;
		node_to_be_pushed->next = NULL;
	}
	else
	{
		node_to_be_pushed->next = *b;
		node_to_be_pushed->next->prev = node_to_be_pushed;
		*b = node_to_be_pushed;
	}
}

void	pa(t_stack **a, t_stack **b, bool print)
{
	push(b, a);
	if (print)
		write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b, bool print)
{
	push(a, b);
	if (print)
		write(1, "pb\n", 3);
}
