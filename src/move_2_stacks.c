/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_2_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtian <mtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:28:43 by mtian             #+#    #+#             */
/*   Updated: 2024/08/19 15:40:13 by mtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_both_upwards(t_position positions, t_list *cheapest_a,
		t_list **stack_a, t_list **stack_b)
{
	while (ft_position(cheapest_a, *stack_a) != 0
		&& ft_position(positions.cible_of_a_in_b, *stack_b) != 0)
	{
		rr(stack_a, stack_b);
	}
	if (ft_position(cheapest_a, *stack_a) == 0
		&& ft_position(positions.cible_of_a_in_b, *stack_b) != 0)
	{
		while (ft_position(positions.cible_of_a_in_b, *stack_b) != 0)
		{
			rb(stack_b);
		}
	}
	else if (ft_position(cheapest_a, *stack_a) != 0
		&& ft_position(positions.cible_of_a_in_b, *stack_b) == 0)
	{
		while (ft_position(cheapest_a, *stack_a) != 0)
		{
			ra(stack_a);
		}
	}
}

void	move_both_downwards(t_position positions, t_list *cheapest_a,
		t_list **stack_a, t_list **stack_b)
{
	while (ft_position(cheapest_a, *stack_a) != 0
		&& ft_position(positions.cible_of_a_in_b, *stack_b) != 0)
	{
		rrr(stack_a, stack_b);
	}
	if (ft_position(cheapest_a, *stack_a) == 0
		&& ft_position(positions.cible_of_a_in_b, *stack_b) != 0)
	{
		while (ft_position(positions.cible_of_a_in_b, *stack_b) != 0)
		{
			rrb(stack_b);
		}
	}
	else if (ft_position(cheapest_a, *stack_a) != 0
		&& ft_position(positions.cible_of_a_in_b, *stack_b) == 0)
	{
		while (ft_position(cheapest_a, *stack_a) != 0)
		{
			rra(stack_a);
		}
	}
}

void	move_a_up_b_down(t_position positions, t_list *cheapest_a,
		t_list **stack_a, t_list **stack_b)
{
	while (ft_position(cheapest_a, *stack_a) != 0)
	{
		ra(stack_a);
	}
	while (ft_position(positions.cible_of_a_in_b, *stack_b) != 0)
	{
		rrb(stack_b);
	}
}

void	move_a_down_b_up(t_position positions, t_list *cheapest_a,
		t_list **stack_a, t_list **stack_b)
{
	while (ft_position(cheapest_a, *stack_a) != 0)
	{
		rra(stack_a);
	}
	while (ft_position(positions.cible_of_a_in_b, *stack_b) != 0)
	{
		rb(stack_b);
	}
}
