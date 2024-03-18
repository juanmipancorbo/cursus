/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpancorb <jpancorb@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:04:58 by jpancorb          #+#    #+#             */
/*   Updated: 2024/02/13 21:04:43 by jpancorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	to_swap(t_list **stack, char a_b)
{
	size_t	temp;

	temp = (*stack)->ranked;
	(*stack)->ranked = (*stack)->next->ranked;
	(*stack)->next->ranked = temp;
	write(1, "s", 1);
	write(1, &a_b, 1);
	write(1, "\n", 1);
	re_rank(stack);
}
