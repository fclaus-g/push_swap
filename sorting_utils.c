/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernandoclaus <fernandoclaus@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 13:26:43 by fernandocla       #+#    #+#             */
/*   Updated: 2023/03/23 18:10:46 by fernandocla      ###   ########.fr       */
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

void	a_to_b(t_box *box)
{
	int limit;
	int in_b;

	limit = 0;
	in_b = 0;
	while (box->alen > 6 && limit < box->alen )
	{
		if (box->stack_a[0] <= box->alen / 2)
		{
			push_b(box);
			in_b++;
		}	
		else 
			rotate_a(box);
		limit++;
	}
	while (box->alen > 3)
	{
		push_b(box);
		in_b++;
	}
}

void	best_pusha(t_box *box)
{
	int	c;
	int	aux[2];

	box->cost[0] = box->alen;
	box->cost[1] = box->blen;
	c = 0;
	while (c < box->blen)
	{
		if (c <= box->blen / 2)
			aux[1] = c;
		if (c > box->blen / 2)
			aux[1] = -(box->blen - c);
		aux[0] = a_moves(box, box->stack_b[c]);
		if (suma_abs(box->cost[0], box->cost[1]) 
			> suma_abs(aux[0], aux[1]))
		{
			box->cost[0] = aux[0];
			box->cost[1] = aux[1];
		}
		c++;
	}
}

int	suma_abs(int x, int y)
{
	if (x < 0)
		x *= -1;
	if (y < 0)
		y *= -1; 
	return (x + y);
}

int	a_moves(t_box *box, int n)
{
	int	end;
	int	start;

	end = box->alen - 1;
	start = 0;
	if (n > box->stack_a[end] && n < box->stack_a[0])
		return (start);
	while (start < box->alen)
	{
		if (n > box->stack_a[start] && n < box->stack_a[start + 1])
			return (start + 1);
		else if (n > box->stack_a[end] && n < box->stack_a[end - 1])
			return (-(box->alen - end));
		start++;
		end--;
	}
	start = ft_locate_min(box->stack_a, box->alen) - 1;
	if (start == -1)
		return (0);
	if (start > (box->alen - start))
		return (-(box->alen - start));
	return (start);
}
