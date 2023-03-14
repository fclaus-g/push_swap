/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernandoclaus <fernandoclaus@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 13:26:43 by fernandocla       #+#    #+#             */
/*   Updated: 2023/03/13 09:24:47 by fernandocla      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

//localiza la posicion del valor mas bajo
int	ft_locate_min(int *array, int len)
{
	int	c;
	int	i;
	int	flag;
//hay que usar el array de manera circular
//para conseguir que el programa devuelva i
//en el momento que flag no haya aumentado en la 
//vuelta anterior del array
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
