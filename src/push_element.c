/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_element.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meiling <meiling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:28:56 by mtian             #+#    #+#             */
/*   Updated: 2024/08/18 01:20:40 by meiling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_2_pb(t_list **stack_a, t_list **stack_b)
{
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	if (*stack_b != NULL && (*stack_b)->next != NULL)
	{
		if (*(int *)(*stack_b)->content > *(int *)((*stack_b)->next)->content)
		{
			sb(stack_b);
		}
	}
}

void	push_cheapest_a_to_b(t_list *cheapest_a,
		t_list **stack_a, t_list **stack_b)
{
	t_position	positions;

	positions.size_a = ft_lstsize(*stack_a);
	positions.size_b = ft_lstsize(*stack_b);
	positions.medium_a = positions.size_a / 2;
	positions.medium_b = positions.size_b / 2;
	positions.cible_of_a_in_b = find_cible_of_a(cheapest_a, *stack_b);
	positions.position_node_in_a = ft_position(cheapest_a, *stack_a);
	positions.position_cible_in_b = ft_position(positions.cible_of_a_in_b,
			*stack_b);
	if (positions.position_node_in_a < positions.medium_a
		&& positions.position_cible_in_b < positions.medium_b)
		move_both_upwards(positions, cheapest_a, stack_a, stack_b);
	else if (positions.position_node_in_a >= positions.medium_a
		&& positions.position_cible_in_b >= positions.medium_b)
		move_both_downwards(positions, cheapest_a, stack_a, stack_b);
	else if (positions.position_node_in_a < positions.medium_a
		&& positions.position_cible_in_b >= positions.medium_b)
		move_a_up_b_down(positions, cheapest_a, stack_a, stack_b);
	else if (positions.position_node_in_a >= positions.medium_a
		&& positions.position_cible_in_b < positions.medium_b)
		move_a_down_b_up(positions, cheapest_a, stack_a, stack_b);
	pb(stack_a, stack_b);
}

void	push_element_b_to_a(t_list *node_b, t_list **stack_a, t_list **stack_b)
{
	t_list	*cible_of_b_in_a;
	int		size_a;
	int		medium_a;
	int		position_cible_in_a;

	size_a = ft_lstsize(*stack_a);
	medium_a = size_a / 2;
	cible_of_b_in_a = find_cible_of_b(node_b, *stack_a);
	position_cible_in_a = ft_position(cible_of_b_in_a, *stack_a);
	if (position_cible_in_a < medium_a)
	{
		while (ft_position(cible_of_b_in_a, *stack_a) > 0)
		{
			ra(stack_a);
		}
	}
	else if (position_cible_in_a >= medium_a)
	{
		while (ft_position(cible_of_b_in_a, *stack_a) > 0)
		{
			rra(stack_a);
		}
	}
	pa(stack_a, stack_b);
}
