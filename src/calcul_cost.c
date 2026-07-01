/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_cost.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:28:29 by mtian             #+#    #+#             */
/*   Updated: 2024/08/16 16:28:32 by mtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calcul_cost_total(t_position positions, int cost_a, int cost_b)
{
	int	cost_total;

	cost_total = INT_MAX;
	if ((positions.position_node_in_a < positions.medium_a
			&& positions.position_cible_in_b < positions.medium_b)
		|| (positions.position_node_in_a >= positions.medium_a
			&& positions.position_cible_in_b >= positions.medium_b))
	{
		if (cost_a >= cost_b)
		{
			cost_total = cost_a;
		}
		else
		{
			cost_total = cost_b;
		}
	}
	else
	{
		cost_total = cost_a + cost_b;
	}
	return (cost_total);
}

int	push_cost_a_to_b(t_list *node_a, t_list *stack_a, t_list *stack_b)
{
	t_position	positions;
	int			cost_a;
	int			cost_b;

	positions.size_a = ft_lstsize(stack_a);
	positions.size_b = ft_lstsize(stack_b);
	positions.medium_a = positions.size_a / 2;
	positions.medium_b = positions.size_b / 2;
	positions.cible_of_a_in_b = find_cible_of_a(node_a, stack_b);
	positions.position_node_in_a = ft_position(node_a, stack_a);
	positions.position_cible_in_b = ft_position(positions.cible_of_a_in_b,
			stack_b);
	cost_a = INT_MAX;
	cost_b = INT_MAX;
	if (positions.position_node_in_a < positions.medium_a)
		cost_a = positions.position_node_in_a;
	else if (positions.position_node_in_a >= positions.medium_a)
		cost_a = positions.size_a - positions.position_node_in_a;
	if (positions.position_cible_in_b < positions.medium_b)
		cost_b = positions.position_cible_in_b;
	else if (positions.position_cible_in_b >= positions.medium_b)
		cost_b = positions.size_b - positions.position_cible_in_b;
	return (calcul_cost_total(positions, cost_a, cost_b));
}
