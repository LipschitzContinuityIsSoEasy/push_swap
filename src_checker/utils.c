/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:33:20 by mtian             #+#    #+#             */
/*   Updated: 2024/08/16 16:33:21 by mtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_list	*ft_lst_penultimate(t_list *lst)
{
	if (lst == NULL || lst->next == NULL)
	{
		return (NULL);
	}
	while ((lst->next)->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

int	ft_position(t_list *node, t_list *lst)
{
	int	i;

	i = 0;
	if (lst == NULL)
	{
		return (-1);
	}
	while (lst != NULL)
	{
		if (*(int *)lst->content == *(int *)node->content)
		{
			return (i);
		}
		lst = lst->next;
		i++;
	}
	return (-1);
}
