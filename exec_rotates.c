/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_rotates.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:32:29 by fernandocla       #+#    #+#             */
/*   Updated: 2023/04/03 12:24:43 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_rotates(t_box *box)
{
	int	x;
	int	y;

	x = box->cost[0];
	y = box->cost[1];
	if (x == 0 && y == 0)
		return ;
	else if (x >= 0 && y >= 0)
		rr_up(box, x, y);
	else if (x < 0 && y < 0)
		rrr_down(box, -x, -y);
	else if (x >= 0 && y < 0)
	{
		while (x-- > 0)
			rotate_a(box, 1);
		while (y++ < 0)
			reverse_b(box, 1);
	}
	else if (x < 0 && y >= 0)
	{
		while (x++ < 0)
			reverse_a(box, 1);
		while (y-- > 0)
			rotate_b(box, 1);
	}
}

void	rr_up(t_box *box, int x, int y)
{
	if (x == y)
	{
		while (x-- > 0)
			rotate_ab(box);
	}
	else if (x > y)
	{
		x = x - y;
		while (x-- > 0)
			rotate_a(box, 1);
		while (y-- > 0)
			rotate_ab(box);
	}
	else if (y > x)
	{
		y = y - x;
		while (y-- > 0)
			rotate_b(box, 1);
		while (x-- > 0)
			rotate_ab(box);
	}	
}

void	rrr_down(t_box *box, int x, int y)
{
	if (x == y)
	{
		while (x-- > 0)
			reverse_ab(box);
	}
	else if (x > y)
	{
		x = x - y;
		while (x-- > 0)
			reverse_a(box, 1);
		while (y-- > 0)
			reverse_ab(box);
	}
	else if (y > x)
	{
		y = y - x;
		while (y-- > 0)
			reverse_b(box, 1);
		while (x-- > 0)
			reverse_ab(box);
	}	
}

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
