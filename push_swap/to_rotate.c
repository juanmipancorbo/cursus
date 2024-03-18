/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpancorb <jpancorb@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:14:45 by jpancorb          #+#    #+#             */
/*   Updated: 2024/02/28 18:04:02 by jpancorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_rotate(int reverse, char a_b)
{
	if (reverse)
		write(1, "rr", 2);
	else
		write(1, "r", 1);
	write(1, &a_b, 1);
	write(1, "\n", 1);
}

void	to_rotate(t_list **stack, int reverse, char a_b)
{
	t_list	*c;
	size_t	temp;

	c = *stack;
	temp = c->ranked;
	if (reverse)
	{
		while (c->prev->rank != 1)
		{
			c->ranked = c->prev->ranked;
			c = c->prev;
		}
	}
	else
	{
		while (c->next->rank != 1)
		{
			c->ranked = c->next->ranked;
			c = c->next;
		}
	}
	c->ranked = temp;
	print_rotate(reverse, a_b);
	re_rank(stack);
}
