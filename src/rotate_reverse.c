/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:31:00 by mtian             #+#    #+#             */
/*   Updated: 2024/08/16 16:31:02 by mtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_reverse(t_list **stack_a)
{
	t_list	*new_last_a;
	t_list	*new_first_a;

	if (*stack_a != NULL && (*stack_a)->next != NULL)
	{
		new_last_a = ft_lst_penultimate(*stack_a);
		new_first_a = new_last_a -> next;
		new_last_a->next = NULL;
		new_first_a->next = *stack_a;
		*stack_a = new_first_a;
	}
}

void	ft_rotate_reverse_2_stacks(t_list **stack_a, t_list **stack_b)
{
	ft_rotate_reverse(stack_a);
	ft_rotate_reverse(stack_b);
}

void	rra(t_list **stack_a)
{
	ft_rotate_reverse(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_list **stack_b)
{
	ft_rotate_reverse(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	ft_rotate_reverse_2_stacks(stack_a, stack_b);
	write(1, "rrr\n", 4);
}
