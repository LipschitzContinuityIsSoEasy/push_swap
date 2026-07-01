/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_a_to_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtian <mtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:21:20 by mtian             #+#    #+#             */
/*   Updated: 2024/08/19 15:23:37 by mtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	one_chunk_a_to_b(int indice, t_list **l, t_list **l_b)
{
	int		count;
	t_list	*current;

	count = ft_lstsize(*l);
	while (count > 0)
	{
		current = *l;
		if (*(int *)current->content < indice)
		{
			pb(l, l_b);
		}
		else
		{
			ra(l);
		}
		count--;
	}
}

void	four_chunks_a_to_b(int *tableau, int size_a, t_list **l, t_list **l_b)
{
	int	indice1;
	int	indice2;
	int	indice3;

	indice1 = tableau[size_a / 4];
	indice2 = tableau[size_a / 2];
	indice3 = tableau[3 * size_a / 4];
	one_chunk_a_to_b(indice1, l, l_b);
	one_chunk_a_to_b(indice2, l, l_b);
	one_chunk_a_to_b(indice3, l, l_b);
	while (ft_lstsize(*l) > 2)
	{
		pb(l, l_b);
	}
}

void	ft_chunk_a_to_b(t_list **l, t_list **l_b)
{
	int		size_a;
	t_list	*current;
	int		*tableau;
	int		i;

	if (*l == NULL)
		return ;
	size_a = ft_lstsize(*l);
	tableau = (int *)malloc(size_a * sizeof(int));
	if (tableau == NULL)
		return ;
	i = 0;
	current = *l;
	while (current != NULL)
	{
		tableau[i] = *(int *)current->content;
		current = current->next;
		i++;
	}
	ft_sort_int_tab(tableau, size_a);
	four_chunks_a_to_b(tableau, size_a, l, l_b);
	free(tableau);
}
