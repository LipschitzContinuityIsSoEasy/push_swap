/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meiling <meiling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:30:50 by mtian             #+#    #+#             */
/*   Updated: 2024/08/18 01:01:48 by meiling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void)
{
	write (2, "Error\n", 6);
}

void	print_error_exit(t_list **l)
{
	print_error();
	if (l != NULL && *l != NULL)
	{
		clear_list(l);
	}
	exit(1);
}
