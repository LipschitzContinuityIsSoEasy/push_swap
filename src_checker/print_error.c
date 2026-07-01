/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtian <mtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:33:36 by mtian             #+#    #+#             */
/*   Updated: 2024/08/19 15:07:14 by mtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
