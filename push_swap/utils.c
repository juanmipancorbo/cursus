/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpancorb <jpancorb@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 20:59:45 by jpancorb          #+#    #+#             */
/*   Updated: 2024/02/29 22:11:26 by jpancorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	re_rank(t_list	**stack)
{
	t_list	*iter;

	iter = *stack;
	iter->rank = 1;
	while (iter->next && iter->next->rank != 1)
	{
		iter->next->rank = iter->rank + 1;
		iter = iter->next;
	}
}

void	free_stack(t_list **stack)
{
	t_list	*temp;
	t_list	*curr;

	curr = *stack;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
	while (curr)
	{
		temp = curr->next;
		free(curr);
		curr = temp;
	}
	*stack = NULL;
}

t_list	*big_sma(t_list **stack, char b_s)
{
	t_list	*curr;
	t_list	*hold;
	int		i;

	curr = *stack;
	hold = curr;
	i = ft_lstsize(stack);
	if (curr->next)
	{
		while (i)
		{
			if ((b_s == 'b') && curr->next->ranked > hold->ranked)
				hold = curr->next;
			if ((b_s == 's') && curr->next->ranked < hold->ranked)
				hold = curr->next;
			curr = curr->next;
			i--;
		}
	}
	return (hold);
}

void	target_up(t_list **stack, t_list **target, char a_b)
{
	int		r_rr;
	int		t_rank;
	int		t_ranked;
	int		stack_size;

	stack_size = ft_lstsize(stack);
	t_rank = (*target)->rank;
	t_ranked = (*target)->ranked;
	if (stack_size > 2)
		r_rr = stack_size / 2;
	while ((*stack)->ranked != t_ranked)
	{
		if (t_rank > r_rr)
			to_rotate(stack, 1, a_b);
		else
			to_rotate(stack, 0, a_b);
	}
}
