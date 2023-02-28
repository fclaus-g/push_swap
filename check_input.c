/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 10:05:52 by fclaus-g          #+#    #+#             */
/*   Updated: 2023/02/28 10:07:04 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	write_error(void)
{
	write (1, "Error\n", 6);
}

int ft_checknumber(t_box *box)
{
	int	c;
	int i;

	i = 1;
	while (box->arg[i] != NULL)
	{
		c = 0;
		if (box->arg[i][c] == '-' || box->arg[i][c] == '+')
			c++;
		while (box->arg[i][c] != '\0')
		{
			if (!ft_isdigit(box->arg[i][c]))
			{
				return(0);
			}	
			c++;	
		}
		i++;
	}
	return (1);
}