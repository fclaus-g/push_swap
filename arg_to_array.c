/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_to_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:34:08 by fclaus-g          #+#    #+#             */
/*   Updated: 2023/04/03 11:51:13 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	ft_longatoi(const char *str, t_box *box)
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
		check_limits(result, box);
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
		box->stack_a[i] = ft_longatoi (box->arg[i], box);
		i++;
	}
	box->len = i;
	box->alen = i;
	box->blen = 0;
	free_matrix (box->arg);
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
	return (dst);
}

size_t	ft_mtrlen(char **matriz)
{
	size_t	i;

	i = 0;
	if (matriz == NULL)
		return (0);
	while (matriz[i] != NULL)
		i++;
	return (i);
}

void	*free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i] != NULL)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
	return (0);
}
