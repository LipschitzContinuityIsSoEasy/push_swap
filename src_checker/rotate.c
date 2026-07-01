/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:33:12 by mtian             #+#    #+#             */
/*   Updated: 2024/08/16 16:33:13 by mtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_rotate(t_list **stack_a)
{
	t_list	*old_first_a;

	if (*stack_a != NULL && (*stack_a)->next != NULL)
	{
		old_first_a = *stack_a;
		*stack_a = old_first_a->next;
		old_first_a->next = NULL;
		ft_lstadd_back(stack_a, old_first_a);
	}
}

void	ft_rotate_2_stacks(t_list **stack_a, t_list **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
}

void	ra(t_list **stack_a)
{
	ft_rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_list **stack_b)
{
	ft_rotate(stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	ft_rotate_2_stacks(stack_a, stack_b);
	write(1, "rr\n", 3);
}
