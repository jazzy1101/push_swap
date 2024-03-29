/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 09:14:40 by dabae             #+#    #+#             */
/*   Updated: 2024/02/22 17:34:45 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

static void	init_properties(t_stack *a)
{
	while (a)
	{
		a->cheapest = false;
		a->cost = 0;
		a->target = NULL;
		a = a->next;
	}
}

long	ft_atol(const char *nptr)
{
	int		sign;
	long	res;
	int		i;

	sign = 1;
	res = 0;
	i = 0;
	while (nptr[i] && (nptr[i] == '\t' || nptr[i] == '\n'
			|| nptr[i] == '\v' || nptr[i] == '\f'
			|| nptr[i] == '\r' || nptr[i] == ' '))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - 48);
		i++;
	}
	return (res * sign);
}

void	error_msg(t_stack **stack)
{
	free_stack(stack);
	write(2, "Error\n", 6);
	exit(1);
}

void	init_stack(t_stack **a, char **av)
{
	int	i;

	i = 0;
	if (check_num(av) && check_double(av) && check_int(av))
	{
		while (av[i])
		{
			add_node_end(a, (int)ft_atol(av[i]));
			i++;
		}
		init_properties(*a);
	}
	else
		error_msg(a);
}
