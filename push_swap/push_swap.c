/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpancorb <jpancorb@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:04:26 by jpancorb          #+#    #+#             */
/*   Updated: 2024/02/29 22:12:03 by jpancorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(t_list **stack_a)
{
	t_list	*curr;

	curr = *stack_a;
	while (curr->next->ranked != 1)
	{
		if (curr->ranked > curr->next->ranked)
			return (1);
		curr = curr->next;
	}
	return (0);
}

static int	to_stack_a(int nbr, t_list **stack_a)
{
	t_list	*new_node;
	t_list	*current;

	current = *stack_a;
	new_node = ft_calloc(1, sizeof(t_list));
	if (!new_node)
		return (1);
	new_node->content = nbr;
	new_node->next = NULL;
	if (!*stack_a)
	{
		new_node->rank = 1;
		new_node->init = 1;
		*stack_a = new_node;
	}
	else
	{
		while (current->next)
			current = current->next;
		new_node->rank = current->rank + 1;
		new_node->init = current->init + 1;
		current->next = new_node;
		new_node->prev = current;
	}
	return (0);
}

static int	error_check(char *argv)
{
	char	*ptr;

	ptr = argv;
	if (*ptr == '-' || *ptr == '+')
		if (!*++ptr)
			return (1);
	while (*ptr)
	{
		if (!(*ptr >= '0' && *ptr <= '9'))
			return (1);
		ptr++;
	}
	return (0);
}

static int	to_pars(char *argv, t_list **stack_a)
{
	long	nbr;
	t_list	*current;

	current = *stack_a;
	if (error_check(argv))
		return (1);
	nbr = ft_atol(argv);
	if (nbr < INT_MIN || nbr > INT_MAX)
		return (1);
	while (current)
	{
		if (nbr == current->content)
			return (1);
		current = current->next;
	}
	if (to_stack_a((int)nbr, stack_a))
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	size_t	i;

	i = 1;
	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	while (argv[i])
	{
		if (to_pars(argv[i], &stack_a))
		{
			write(2, "Error\n", 6);
			return (1);
		}
		i++;
	}
	argc--;
	to_ranked(&stack_a, argc);
	if (is_sorted(&stack_a))
		to_sort(&stack_a, &stack_b);
	if (stack_a)
		free_stack(&stack_a);
	return (0);
}
