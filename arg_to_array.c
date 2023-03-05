/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_to_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernandoclaus <fernandoclaus@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 10:15:12 by fclaus-g          #+#    #+#             */
/*   Updated: 2023/03/04 14:05:22 by fernandocla      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	ft_longatoi(const char *str)
{
	size_t	count;
	long	result;
	int		sign;

	count = 0;
	result = 0;
	sign = 1;
	while ((str[count] >= 9 && str[count] <= 13) || str[count] == 32)
		count++;
	if (str[count] == '-' || str[count] == '+')
	{
		if (str[count] == '-')
			sign = -1;
		count++;
	}
	while (ft_isdigit(str[count]))
	{
		result = result * 10 + str[count] - 48;
		//if (result > INT_MAX || result < INT_MIN)
			//return (write_error(), 0);
		count++;
	}
	return (sign * result);
}

void	arg_to_array(t_box *box)
{
	int	i;

	i = 0;
	while (box->arg[i] != NULL)
	{
		box->stack_a[i] = ft_longatoi(box->arg[i]);
		i++;
	}
	box->len = i;
	box->alen = i;
	box->blen = 0;
	printa(box->stack_a, box->len);
}

int	*ft_arraycpy(int *dst, int *array, int len)
{
	int	c;

	c = 0;
	if (!array || len == 0)
		return (NULL);
	while (c < len)
	{
		dst[c] = array[c];
		c++;
	}
	return(dst);
}
