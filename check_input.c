/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernandoclaus <fernandoclaus@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 10:05:52 by fclaus-g          #+#    #+#             */
/*   Updated: 2023/03/05 13:48:28 by fernandocla      ###   ########.fr       */
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

int check_repeat(t_box *box)
{
	int	i;
	int	c;
	int	x;

	x = box->len;
	i = 0;
	while (i < x)
	{
		c = 0;
		while (c < x)
		{
			if (box->stack_a[c] == box->stack_a[i])
			{
				write_error();
				free(box->stack_a);
				return(0);	
			}	
			c++;
		}
		i++;
	}
	return (1);
}

int	*simplifier(t_box *box)
{
	int	c;
	int	i;
	int	num;
	int	*aux;

	i = 0;
	num = 0;
	aux = malloc(sizeof(int) * box ->len);
	while (box->stack_a[i] < box->len)
	{
		c = 0;
		while(box->stack_a[c] < box->len)
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
	
