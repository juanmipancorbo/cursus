/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_500.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpancorb <jpancorb@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 21:53:11 by jpancorb          #+#    #+#             */
/*   Updated: 2024/02/27 21:59:59 by jpancorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	algo_500_aux(t_list **stack_a, t_list **stack_b)
{
	int	iter;

	iter = 284;
	while (iter < 427)
	{
		iter++;
		to_hold(stack_a, 428);
		to_push(stack_b, stack_a, 'b');
		if ((*stack_b)->ranked < 358)
			to_rotate(stack_b, 0, 'b');
	}
	while (*stack_a)
	{
		iter++;
		to_push(stack_b, stack_a, 'b');
		if ((*stack_b)->ranked < 465)
			to_rotate(stack_b, 0, 'b');
	}
}

void	algo_500(t_list **stack_a, t_list **stack_b)
{
	int	iter;

	iter = 0;
	while (iter < 141)
	{
		iter++;
		to_hold(stack_a, 142);
		to_push(stack_b, stack_a, 'b');
		if ((*stack_b)->next)
			if ((*stack_b)->ranked < 72 && (*stack_b)->next->ranked > 71)
				to_rotate(stack_b, 0, 'b');
	}
	while (iter < 284)
	{
		iter++;
		to_hold(stack_a, 285);
		to_push(stack_b, stack_a, 'b');
		if ((*stack_b)->ranked < 215)
			to_rotate(stack_b, 0, 'b');
	}
	algo_500_aux(stack_a, stack_b);
}
