/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:29:24 by dabae             #+#    #+#             */
/*   Updated: 2024/02/23 12:04:15 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

char	**ft_free_tab(char **tab)
{
	int	i;

	if (!tab)
		return (NULL);
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*curr_node;

	if (!*stack)
		return ;
	curr_node = *stack;
	while (curr_node)
	{
		tmp = curr_node->next;
		free(curr_node);
		curr_node = tmp;
	}
	*stack = NULL;
}

bool	check_num(char **av)
{
	int	i;
	int	j;

	i = -1;
	while (av[++i])
	{
		j = 0;
		if (av[i][0] == '-' || av[i][0] == '+')
		{
			while (ft_isdigit(av[i][j + 1]) && av[i][j + 1])
				j++;
			if (av[i][j + 1])
				return (false);
		}
		else
		{
			while (av[i][j])
			{
				if (!ft_isdigit(av[i][j]))
					return (false);
				j++;
			}
		}
	}
	return (true);
}

bool	check_int(char **av)
{
	long	num;

	while (*av)
	{
		num = ft_atol(*av);
		if (num < INT_MIN || num > INT_MAX)
			return (false);
		av++;
	}
	return (true);
}

bool	check_double(char **av)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (av[i])
	{
		if (ft_strcmp(av[i], "") == 0)
			return (false);
		j = i + 1;
		while (av[j])
		{
			if (ft_atol(av[i]) == ft_atol(av[j]))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}
