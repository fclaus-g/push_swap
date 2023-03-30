/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 10:05:52 by fclaus-g          #+#    #+#             */
/*   Updated: 2023/03/30 13:55:52 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_checknumber(t_box *box)
{
	int	c;
	int	i;

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
				return (0);
			}
			c++;
		}
		i++;
	}
	return (1);
}

int	check_repeat(t_box *box)
{
	int	i;
	int	c;
	int	x;

	x = box->len;
	i = 0;
	c = 0;
	while (i < x)
	{
		c = i + 1;
		while (c < x)
		{
			if (box->stack_a[c] == box->stack_a[i])
			{
				//free(box->stack_a);
				return (0);
			}	
			c++;
		}
		i++;
	}
	return (1);
}

int	*simplifier(t_box *box)
{
	size_t	c;
	size_t	i;
	size_t	num;
	int		*aux;

	i = 0;
	aux = malloc(sizeof(int) * box->len);
	while (i < (size_t)box->len)
	{
		num = 1;
		c = 0;
		while (c < (size_t)box->len)
		{
			if (box->stack_a[i] > box->stack_a[c])
				num++;
			c++;
		}
		aux[i] = num;
		i++;
	}	
	free (box->stack_a);
	return (aux);
}

int	in_order(t_box *box)
{
	int	i;
	int	c;

	i = 0;
	while (i < box->len)
	{
		c = i + 1;
		while (c < box->len)
		{
			if (box->stack_a[i] > box->stack_a[c])
			{
				return (0);
			}
			c++;
		}
		i++;
	}
	return (1);
}
