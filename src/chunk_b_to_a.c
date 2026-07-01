/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_b_to_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtian <mtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:21:28 by mtian             #+#    #+#             */
/*   Updated: 2024/08/19 15:42:06 by mtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calcul_cost_total_b(t_b_position positions, int cost_a, int cost_b)
{
	int	cost_total;

	cost_total = INT_MAX;
	if ((positions.position_node_in_b < positions.medium_b
			&& positions.position_cible_in_a < positions.medium_a)
		|| (positions.position_node_in_b >= positions.medium_b
			&& positions.position_cible_in_a >= positions.medium_a))
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

int	push_cost_b_to_a(t_list *node_b, t_list *stack_a, t_list *stack_b)
{
	t_b_position	positions;
	int				cost_a;
	int				cost_b;

	positions.size_a = ft_lstsize(stack_a);
	positions.size_b = ft_lstsize(stack_b);
	positions.medium_a = positions.size_a / 2;
	positions.medium_b = positions.size_b / 2;
	positions.cible_of_b_in_a = find_cible_of_b(node_b, stack_a);
	positions.position_node_in_b = ft_position(node_b, stack_b);
	positions.position_cible_in_a = ft_position(positions.cible_of_b_in_a,
			stack_a);
	cost_a = INT_MAX;
	cost_b = INT_MAX;
	if (positions.position_node_in_b < positions.medium_b)
		cost_b = positions.position_node_in_b;
	else if (positions.position_node_in_b >= positions.medium_b)
		cost_b = positions.size_b - positions.position_node_in_b;
	if (positions.position_cible_in_a < positions.medium_a)
		cost_a = positions.position_cible_in_a;
	else if (positions.position_cible_in_a >= positions.medium_a)
		cost_a = positions.size_a - positions.position_cible_in_a;
	return (calcul_cost_total_b(positions, cost_a, cost_b));
}

void	push_cheapest_b_to_a(t_list *cheapest_b,
		t_list **stack_a, t_list **stack_b)
{
	t_b_position	positions;

	positions.size_a = ft_lstsize(*stack_a);
	positions.size_b = ft_lstsize(*stack_b);
	positions.medium_a = positions.size_a / 2;
	positions.medium_b = positions.size_b / 2;
	positions.cible_of_b_in_a = find_cible_of_b(cheapest_b, *stack_a);
	positions.position_node_in_b = ft_position(cheapest_b, *stack_b);
	positions.position_cible_in_a = ft_position(positions.cible_of_b_in_a,
			*stack_a);
	if (positions.position_node_in_b < positions.medium_b
		&& positions.position_cible_in_a < positions.medium_a)
		move2_both_upwards(positions, cheapest_b, stack_a, stack_b);
	else if (positions.position_node_in_b >= positions.medium_b
		&& positions.position_cible_in_a >= positions.medium_a)
		move2_both_downwards(positions, cheapest_b, stack_a, stack_b);
	else if (positions.position_node_in_b < positions.medium_b
		&& positions.position_cible_in_a >= positions.medium_a)
		move2_a_down_b_up(positions, cheapest_b, stack_a, stack_b);
	else if (positions.position_node_in_b >= positions.medium_b
		&& positions.position_cible_in_a < positions.medium_a)
		move2_a_up_b_down(positions, cheapest_b, stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	ft2_push_b_to_a(t_list **l, t_list **l_b)
{
	t_list	*current;
	t_list	*cheapest_node_in_b;
	int		cost_node_in_b;
	int		cost_temp_node_in_b;

	while (ft_lstsize(*l_b) > 0)
	{
		cost_node_in_b = INT_MAX;
		current = *l_b;
		cheapest_node_in_b = NULL;
		while (current != NULL)
		{
			cost_temp_node_in_b = push_cost_b_to_a(current, *l, *l_b);
			if (cost_temp_node_in_b < cost_node_in_b)
			{
				cost_node_in_b = cost_temp_node_in_b;
				cheapest_node_in_b = current;
			}
			current = current->next;
		}
		push_cheapest_b_to_a(cheapest_node_in_b, l, l_b);
	}
}

void	ft_sort_grand_nb(t_list **l)
{
	t_list	*l_b;

	l_b = NULL;
	ft_chunk_a_to_b(l, &l_b);
	if (*(int *)(*l)->content > *(int *)((*l)->next)->content)
	{
		sa(l);
	}
	ft2_push_b_to_a(l, &l_b);
	sort_stack_after_push(l);
}
