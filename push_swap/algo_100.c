/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpancorb <jpancorb@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 20:07:01 by jpancorb          #+#    #+#             */
/*   Updated: 2024/02/28 18:07:48 by jpancorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	to_hold(t_list **stack, int chunks)
{
	int		rot;
	t_list	*curr;

	rot = 0;
	curr = *stack;
	while (++rot && (curr->next->rank != 1))
	{
		if (curr->ranked > 0 && curr->ranked < chunks)
			break ;
		curr = curr->next;
	}
	while (--rot)
		to_rotate(stack, 0, 'a');
}

static void	to_insert(t_list **to, t_list **from, char a_b)
{
	int		i;
	t_list	*target;

	i = ft_lstsize(to);
	target = *to;
	while (i--)
	{
		if ((*from)->ranked < target->ranked)
			if ((*from)->ranked > target->prev->ranked)
				break ;
		target = target->next;
	}
	target_up(to, &target, a_b);
}

void	to_place(t_list **to, t_list **from, char a_b)
{
	t_list	*bigger;
	t_list	*smaller;

	if (*to)
	{
		bigger = big_sma(to, 'b');
		smaller = big_sma(to, 's');
		if ((*from)->ranked > bigger->ranked
			|| (*from)->ranked < smaller->ranked)
			target_up(to, &smaller, a_b);
		else
			to_insert(to, from, a_b);
	}
	to_push(to, from, a_b);
}

void	algo_random(t_list **stack_a, t_list **stack_b)
{
	int	iter;
	int	chunks;

	iter = 0;
	chunks = ft_lstsize(stack_a) / 3;
	while (*stack_a)
	{
		if ((*stack_a)->next)
			to_hold(stack_a, chunks * 2);
		to_push(stack_b, stack_a, 'b');
		if ((*stack_b)->next)
			if ((*stack_b)->ranked < chunks
				&& (*stack_b)->next->ranked > chunks)
				to_rotate(stack_b, 0, 'b');
		if ((*stack_a) && ++iter == chunks * 2)
			chunks += ft_lstsize(stack_a) / 3;
	}
}

void	algo_100(t_list **stack_a, t_list **stack_b)
{
	int	iter;

	iter = 0;
	while (iter < 49)
	{
		to_hold(stack_a, 50);
		to_push(stack_b, stack_a, 'b');
		if (iter++ && (*stack_b)->next)
			if ((*stack_b)->ranked < 26 && (*stack_b)->next->ranked > 25)
				to_rotate(stack_b, 0, 'b');
	}
	while (iter < 74)
	{
		to_hold(stack_a, 75);
		to_push(stack_b, stack_a, 'b');
		if (iter++ && (*stack_b)->ranked < 63)
			to_rotate(stack_b, 0, 'b');
	}
	while (*stack_a)
	{
		to_push(stack_b, stack_a, 'b');
		if ((*stack_b)->ranked < 86)
			to_rotate(stack_b, 0, 'b');
	}
}
