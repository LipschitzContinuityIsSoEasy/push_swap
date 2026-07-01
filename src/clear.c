/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:29:19 by mtian             #+#    #+#             */
/*   Updated: 2024/08/16 16:29:21 by mtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab != NULL)
	{
		while (tab[i] != NULL)
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
}

void	clear_list(t_list **lst)
{
	t_list	*temp;
	t_list	*current;

	current = *lst;
	while (current != NULL)
	{
		temp = current->next;
		free(current->content);
		free(current);
		current = temp;
	}
	*lst = NULL;
}
