/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_move_stacks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtian <mtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:21:36 by mtian             #+#    #+#             */
/*   Updated: 2024/08/19 15:39:57 by mtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move2_both_upwards(t_b_position positions, t_list *cheapest_b,
		t_list **stack_a, t_list **stack_b)
{
	while (ft_position(cheapest_b, *stack_b) != 0
		&& ft_position(positions.cible_of_b_in_a, *stack_a) != 0)
	{
		rr(stack_a, stack_b);
	}
	if (ft_position(cheapest_b, *stack_b) == 0
		&& ft_position(positions.cible_of_b_in_a, *stack_a) != 0)
	{
		while (ft_position(positions.cible_of_b_in_a, *stack_a) != 0)
		{
			ra(stack_a);
		}
	}
	else if (ft_position(cheapest_b, *stack_b) != 0
		&& ft_position(positions.cible_of_b_in_a, *stack_a) == 0)
	{
		while (ft_position(cheapest_b, *stack_b) != 0)
		{
			rb(stack_b);
		}
	}
}

void	move2_both_downwards(t_b_position positions, t_list *cheapest_b,
		t_list **stack_a, t_list **stack_b)
{
	while (ft_position(cheapest_b, *stack_b) != 0
		&& ft_position(positions.cible_of_b_in_a, *stack_a) != 0)
	{
		rrr(stack_a, stack_b);
	}
	if (ft_position(cheapest_b, *stack_b) == 0
		&& ft_position(positions.cible_of_b_in_a, *stack_a) != 0)
	{
		while (ft_position(positions.cible_of_b_in_a, *stack_a) != 0)
		{
			rra(stack_a);
		}
	}
	else if (ft_position(cheapest_b, *stack_b) != 0
		&& ft_position(positions.cible_of_b_in_a, *stack_a) == 0)
	{
		while (ft_position(cheapest_b, *stack_b) != 0)
		{
			rrb(stack_b);
		}
	}
}

void	move2_a_up_b_down(t_b_position positions, t_list *cheapest_b,
		t_list **stack_a, t_list **stack_b)
{
	while (ft_position(cheapest_b, *stack_b) != 0)
	{
		rrb(stack_b);
	}
	while (ft_position(positions.cible_of_b_in_a, *stack_a) != 0)
	{
		ra(stack_a);
	}
}

void	move2_a_down_b_up(t_b_position positions, t_list *cheapest_b,
		t_list **stack_a, t_list **stack_b)
{
	while (ft_position(cheapest_b, *stack_b) != 0)
	{
		rb(stack_b);
	}
	while (ft_position(positions.cible_of_b_in_a, *stack_a) != 0)
	{
		rra(stack_a);
	}
}
