/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpancorb <jpancorb@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:06:59 by jpancorb          #+#    #+#             */
/*   Updated: 2024/02/29 22:10:25 by jpancorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

/* ************************************************************************** */
/*                                 STRUCT                                     */
/* ************************************************************************** */

typedef struct s_list
{
	int				content;
	size_t			init;
	int				rank;
	int				ranked;
	int				moves;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

/* ************************************************************************** */
/*                                FUNCTIONS                                   */
/* ************************************************************************** */

long	ft_atol(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	to_ranked(t_list **stack, int argc);
void	to_sort(t_list **stack_a, t_list **stack_b);
int		ft_lstsize(t_list **lst);
void	free_stack(t_list **stack);
void	re_rank(t_list	**stack);
void	to_place(t_list **to, t_list **from, char a_b);
t_list	*big_sma(t_list **stack, char b_s);
void	target_up(t_list **stack, t_list **target, char a_b);
void	to_hold(t_list **stack, int chunks);
void	algo_500(t_list **stack_a, t_list **stack_b);
void	algo_100(t_list **stack_a, t_list **stack_b);
void	algo_random(t_list **stack_a, t_list **stack_b);

/* ************************************************************************** */
/*                               OPERATIONS                                   */
/* ************************************************************************** */

void	to_push(t_list **to, t_list **from, char a_b);
void	to_swap(t_list **stack, char a_b);
void	to_rotate(t_list **stack, int reverse, char a_b);

#endif
