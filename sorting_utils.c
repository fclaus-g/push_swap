/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 13:26:43 by fernandocla       #+#    #+#             */
/*   Updated: 2023/04/03 12:24:55 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	a_to_b(t_box *box)
{
	int	limit;

	limit = 0;
	while (box->alen > 6 && limit < box->alen)
	{
		if (box->stack_a[0] <= box->alen / 2)
			push_b(box);
		else
			rotate_a(box, 1);
		limit++;
	}
	while (box->alen > 3)
		push_b(box);
}

void	best_pusha(t_box *box)
{
	int	c;
	int	aux[2];

	box->cost[0] = box->alen;
	box->cost[1] = box->blen;
	c = 0;
	while (c <= box->blen - 1)
	{
		if (c <= box->blen / 2)
			aux[1] = c;
		if (c > box->blen / 2)
			aux[1] = (box->blen - c) * (-1);
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
		x = x * (-1);
	if (y < 0)
		y = y * (-1);
	return (x + y);
}

int	a_moves(t_box *box, int n)
{
	int	end;
	int	start;

	end = box->alen - 1;
	start = 0;
	if ((n > box->stack_a[end] && n < box->stack_a[0]))
		return (start);
	while (start < box->alen - 1)
	{
		if (n > box->stack_a[start] && n < box->stack_a[start + 1])
			return (start + 1);
		else if (n < box->stack_a[end] && n > box->stack_a[end - 1])
			return ((box->alen - end) * (-1));
		start++;
		end--;
	}
	start = ft_locate_max(box->stack_a, box->alen) + 1;
	if (start == (-1))
		return (0);
	if (start > (box->alen - start))
		return ((box->alen - start) * (-1));
	return (start);
}

int	ft_locate_max(int *array, int len)
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
			if (array[i] < array[c])
				flag++;
			c++;
		}
		if (flag == 0)
			return (i);
		i++;
	}
	return (0);
}
