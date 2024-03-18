/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpancorb <jpancorb@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 20:51:06 by jpancorb          #+#    #+#             */
/*   Updated: 2024/02/29 22:12:40 by jpancorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	algo_3(t_list **stack)
{
	if ((*stack)->ranked > (*stack)->next->ranked)
	{
		if ((*stack)->ranked < (*stack)->prev->ranked)
			to_swap(stack, 'a');
		else if ((*stack)->next->ranked < (*stack)->prev->ranked)
			to_rotate(stack, 0, 'a');
		else
		{
			to_swap(stack, 'a');
			to_rotate(stack, 1, 'a');
		}
	}
	else
	{
		if ((*stack)->next->ranked > (*stack)->prev->ranked
			&& (*stack)->ranked < (*stack)->prev->ranked)
		{
			to_swap(stack, 'a');
			to_rotate(stack, 0, 'a');
		}
		if ((*stack)->next->ranked > (*stack)->prev->ranked
			&& (*stack)->ranked > (*stack)->prev->ranked)
			to_rotate(stack, 1, 'a');
	}
}

static void	algo_5(t_list **stack_a, t_list **stack_b)
{
	while ((*stack_a)->prev->rank > 3)
		to_push(stack_b, stack_a, 'b');
	algo_3(stack_a);
	while (*stack_b)
		to_place(stack_a, stack_b, 'a');
	while ((*stack_a)->ranked != 1)
		to_rotate(stack_a, 0, 'a');
}

static void	back_to_a(t_list **a, t_list **b)
{
	t_list	*target;

	while (*b)
	{
		target = big_sma(b, 'b');
		target_up(b, &target, 'b');
		to_push(a, b, 'a');
	}
}

void	to_sort(t_list **stack_a, t_list **stack_b)
{
	if ((*stack_a) && ft_lstsize(stack_a) > 499)
		algo_500(stack_a, stack_b);
	if ((*stack_a) && ft_lstsize(stack_a) > 99)
		algo_100(stack_a, stack_b);
	if ((*stack_a) && ft_lstsize(stack_a) > 10)
		algo_random(stack_a, stack_b);
	if ((*stack_a) && ft_lstsize(stack_a) > 3)
		algo_5(stack_a, stack_b);
	if ((*stack_a) && ft_lstsize(stack_a) > 2)
		algo_3(stack_a);
	if ((*stack_a) && ft_lstsize(stack_a) < 3)
		if ((*stack_a)->ranked > (*stack_a)->next->ranked)
			to_rotate(stack_a, 0, 'a');
	if (*stack_b)
		back_to_a(stack_a, stack_b);
	if (*stack_b)
		*stack_b = NULL;
}
