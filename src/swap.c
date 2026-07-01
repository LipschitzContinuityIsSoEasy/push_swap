/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:30:26 by mtian             #+#    #+#             */
/*   Updated: 2024/08/16 16:30:30 by mtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **stack_a)
{
	t_list	*first;
	t_list	*second;

	if (*stack_a != NULL && (*stack_a)->next != NULL)
	{
		first = *stack_a;
		second = first->next;
		first->next = second->next;
		second->next = first;
		*stack_a = second;
	}
}

void	ft_swap_2_stacks(t_list **stack_a, t_list **stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
}

void	sa(t_list **stack_a)
{
	ft_swap(stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_list **stack_b)
{
	ft_swap(stack_b);
	write(1, "sb\n", 3);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	ft_swap_2_stacks(stack_a, stack_b);
	write(1, "ss\n", 3);
}
