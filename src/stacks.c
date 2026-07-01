/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:29:07 by mtian             #+#    #+#             */
/*   Updated: 2024/08/16 16:29:08 by mtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_a_to_b(t_list **l, t_list **l_b)
{
	t_list	*current;
	t_list	*cheapest_node_in_a;
	int		cost_node_in_a;
	int		cost_temp_node_in_a;

	*l_b = NULL;
	ft_2_pb(l, l_b);
	while (ft_lstsize(*l) > 3)
	{
		cost_node_in_a = INT_MAX;
		current = *l;
		cheapest_node_in_a = NULL;
		while (current != NULL)
		{
			cost_temp_node_in_a = push_cost_a_to_b(current, *l, *l_b);
			if (cost_temp_node_in_a < cost_node_in_a)
			{
				cost_node_in_a = cost_temp_node_in_a;
				cheapest_node_in_a = current;
			}
			current = current->next;
		}
		push_cheapest_a_to_b(cheapest_node_in_a, l, l_b);
	}
}

void	ft_push_b_to_a(t_list **l, t_list **l_b)
{
	int	nb;

	sort_3_element(l);
	nb = ft_lstsize(*l_b);
	while (nb > 0)
	{
		push_element_b_to_a(*l_b, l, l_b);
		nb--;
	}
	sort_stack_after_push(l);
}
