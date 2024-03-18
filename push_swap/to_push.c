/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpancorb <jpancorb@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 20:01:27 by jpancorb          #+#    #+#             */
/*   Updated: 2024/02/24 20:54:30 by jpancorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	new_stack(t_list **to, t_list **from)
{
	void	*temp_from;

	temp_from = (*from)->next;
	(*from)->next->prev = (*from)->prev;
	(*from)->prev->next = (*from)->next;
	(*from)->next = NULL;
	(*from)->prev = NULL;
	*to = *from;
	*from = temp_from;
	(*to)->rank = 1;
	re_rank(from);
}

static void	not_alone(t_list **from)
{
	if ((*from)->next)
	{
		(*from)->next->prev = (*from)->prev;
		(*from)->prev->next = (*from)->next;
	}
}

static void	to_be_alone(t_list **stack)
{
	(*stack)->next = NULL;
	(*stack)->prev = NULL;
}

static void	change_stack(t_list **to, t_list **from)
{
	void	*temp_to;
	void	*new_from;

	if ((*to)->prev)
		temp_to = (*to)->prev;
	else
		temp_to = (*to)->next;
	new_from = (*from)->next;
	not_alone(from);
	(*from)->next = *to;
	(*to)->prev = *from;
	if ((*to)->next)
	{
		(*from)->prev = temp_to;
		(*from)->prev->next = (*from);
	}
	else
	{
		(*from)->prev = *to;
		(*to)->next = (*from);
	}
	*to = *from;
	*from = new_from;
	if ((*to)->next)
		(*to)->next->rank = 2;
}

void	to_push(t_list **to, t_list **from, char a_b)
{
	if (!*to)
		new_stack(to, from);
	else
	{
		change_stack(to, from);
		if ((*from) && (*from)->next == (*from))
			to_be_alone(from);
		if (*from)
			re_rank(from);
		re_rank(to);
	}
	write(1, "p", 1);
	write(1, &a_b, 1);
	write(1, "\n", 1);
}
