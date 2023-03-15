/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 13:26:43 by fernandocla       #+#    #+#             */
/*   Updated: 2023/03/15 11:10:21 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

int	ft_locate_min(int *array, int len)
{
	int	c;
	int	i;
	int	flag;

	i = 0;
	while (i < len)
	{
		c = 0;
		flag = 0;
		while (c < len)
		{
			if (array[i] > array[c])
				flag++;
			c++;
		}
		if (flag == 0)
			return (i);
		i++;
	}
	return (0);
}
