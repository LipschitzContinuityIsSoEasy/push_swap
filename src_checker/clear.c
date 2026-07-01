/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:32:54 by mtian             #+#    #+#             */
/*   Updated: 2024/08/16 16:32:55 by mtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	clear_all_lists(t_list **l, t_list **l_b, t_list **list_instruction)
{
	clear_list(l);
	clear_list(l_b);
	clear_list(list_instruction);
}
