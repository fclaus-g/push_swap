/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_rotates.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernandoclaus <fernandoclaus@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:32:29 by fernandocla       #+#    #+#             */
/*   Updated: 2023/03/23 18:04:49 by fernandocla      ###   ########.fr       */
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
		while(x-- > 0)
			rotate_a(box);
		while (y++ < 0)
			reverse_b(box);
	}
	else if (x < 0 && y >= 0)
	{
		while (x++ < 0)
			reverse_a(box);
		while (y-- > 0)
			rotate_b(box);
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
			rotate_a(box);
		while (y-- > 0)
			rotate_ab(box);
	}
	else if(y > x)
	{
		y = y - x;
		while (y-- > 0)
			rotate_b(box);
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
			reverse_a(box);
		while (y-- > 0)
			reverse_ab(box);
	}
	else if(y > x)
	{
		y = y - x;
		while (y-- > 0)
			reverse_b(box);
		while (x-- > 0)
			reverse_ab(box);
	}	
}