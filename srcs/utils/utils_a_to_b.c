/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_a_to_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:30:01 by dabae             #+#    #+#             */
/*   Updated: 2024/02/15 16:30:03 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void  find_target_in_b(t_stack *stack_a, t_stack *stack_b)
{
    t_stack *target;
    t_stack *curr_b;
    long closest_smaller;

    while(stack_a)
    {
        closest_smaller = LONG_MIN;
        curr_b = stack_b;
        while (curr_b)
        {
            if (curr_b->num < stack_a->num && curr_b->num > closest_smaller)
            {
                closest_smaller = curr_b->num;
                target = curr_b;
            }
            curr_b = curr_b->next;
        }
        if (closest_smaller == LONG_MIN)
            stack_a->target = ft_max_node(stack_b);
        else
            stack_a->target = target;
        stack_a = stack_a->next;
    }
}

void  calcul_cost_a(t_stack *stack_a, t_stack *stack_b)
{
    int cost;

    while (stack_a)
    {
        cost = 0;
        if (stack_a->before_median && stack_a->target->before_median)
            cost = is_smaller(stack_a->index, stack_a->target->index) + absolute(stack_a->index, stack_a->target->index);
        else if (!(stack_a->before_median) && !(stack_a->target->before_median))
            cost = is_smaller((stack_size(stack_a) - stack_a->index), (stack_size(stack_b) - stack_a->target->index)) + absolute(stack_a->index, stack_a->target->index);
        else if (stack_a->before_median && !(stack_a->target->before_median))
            cost = stack_a->index + stack_size(stack_b) - stack_a->target->index;
        else
            cost = stack_size(stack_a) - stack_a->index + stack_a->target->index;
        stack_a->cost = cost;
        stack_a = stack_a->next;
    }
}

void    set_cheapest(t_stack *stack_a)
{
    long min_cost;
    t_stack *cheapest_node;

    if (!stack_a)
        return ;
    min_cost = LONG_MAX;
    while (stack_a)
    {
        if (stack_a->cost < min_cost)
        {
            min_cost = stack_a->cost;
            cheapest_node = stack_a;
        }
        stack_a = stack_a->next;
    }
    cheapest_node->cheapest = true;
}

static t_stack *get_cheapest_node(t_stack *stack)
{
    if (!stack)
        return (NULL);
    while (stack)
    {
        if (stack->cheapest)
            return (stack);
        stack = stack->next;
    }
    return (NULL); 
}

void    push_cheapest_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *cheapest;

    cheapest = get_cheapest_node(*stack_a);
    if (cheapest->before_median && cheapest->target->before_median)
    {
        while (*stack_a != cheapest && *stack_b != cheapest->target)
            rr(stack_a, stack_b);
        set_index_median(*stack_a);
        set_index_median(*stack_b);
    }
    else if (!(cheapest->before_median) && !(cheapest->target->before_median))
    {
        while (*stack_a != cheapest && *stack_b != cheapest->target)
            rrr(stack_a, stack_b);
        set_index_median(*stack_a);
        set_index_median(*stack_b);
    }
    to_top(stack_a, cheapest, 'a');
    to_top(stack_b, cheapest->target, 'b');
    pb(stack_a, stack_b);
}
