/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:31:30 by mtian             #+#    #+#             */
/*   Updated: 2024/08/16 16:32:36 by mtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_2_to_1(t_list **stack_a, t_list **stack_b)
{
	t_list	*first_b;

	if (*stack_b != NULL)
	{
		first_b = *stack_b;
		*stack_b = first_b->next;
		first_b->next = *stack_a;
		*stack_a = first_b;
	}
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	ft_push_2_to_1(stack_a, stack_b);
	write(1, "pa\n", 3);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	ft_push_2_to_1(stack_b, stack_a);
	write(1, "pb\n", 3);
}
