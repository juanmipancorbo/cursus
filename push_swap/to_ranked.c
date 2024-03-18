/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_ranked.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpancorb <jpancorb@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 21:23:51 by jpancorb          #+#    #+#             */
/*   Updated: 2024/02/19 21:08:45 by jpancorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	to_circular(t_list **stack)
{
	t_list	*current;

	current = *stack;
	while (current->next)
		current = current->next;
	current->next = *stack;
	current->next->prev = current;
}

void	to_ranked(t_list **stack, int argc)
{
	t_list	*min;
	t_list	*iter;
	int		ranked_nbr;

	to_circular(stack);
	ranked_nbr = 0;
	iter = *stack;
	min = iter;
	while (min->ranked != argc)
	{
		while (iter->next->rank != 1)
		{
			while (min->ranked)
				min = min->next;
			if (!iter->ranked && !min->ranked && iter->content < min->content)
				min = iter;
			iter = iter->next;
		}
		if (!iter->ranked && !min->ranked && iter->content < min->content)
			min = iter;
		ranked_nbr++;
		iter = *stack;
		min->ranked = ranked_nbr;
	}
}
