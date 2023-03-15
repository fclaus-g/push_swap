/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:35:35 by fernandocla       #+#    #+#             */
/*   Updated: 2023/03/15 11:09:26 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort2(t_box *box)
{
	if (box->alen == 2)
	{
		swap_a(box);
		printa(box->stack_a, 2);
	}
}

void	sort3(t_box *box)
{
	int	a;
	int	b;
	int	c;

	if (box->alen == 3)
	{
		a = box->stack_a[0];
		b = box->stack_a[1];
		c = box->stack_a[2];
		if (a < b && b > c && c > a)
			return (swap_a(box), rotate_a(box));
		if (a < b && b > c && c < a)
			return (reverse_a(box));
		if (a > b && b > c && c < a)
			return (rotate_a(box), swap_a(box));
		if (a > b && b < c && c > a)
			return (swap_a(box));
		if (a > b && b < c && c < a)
			return (rotate_a(box));
	}
}

void	sort4y5(t_box *box)
{
	int	min_pos;
	int	target_pos;

	while (box->alen > 3)
	{
		min_pos = ft_locate_min(box->stack_a, box->alen);
		target_pos = box->stack_a[min_pos];
		if (min_pos <= box->alen / 2)
		{
			while (box->stack_a[0] != target_pos)
				rotate_a(box);
			push_b(box);
		}
		else if (min_pos > box->alen / 2)
		{
			while (box->stack_a[0] != target_pos)
				reverse_a(box);
			push_b(box);
		}
	}
	sort3(box);
	return (push_a(box), push_a(box));
}

void	ft_sorting(t_box *box)
{
	if (box->alen == 2)
		return (sort2(box));
	if (box->alen == 3)
		return (sort3(box));
	if (box->alen > 3 && box->alen < 6)
		return (sort4y5(box));
}
