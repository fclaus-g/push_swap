/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:35:51 by usuario42         #+#    #+#             */
/*   Updated: 2023/02/27 11:47:49 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	write_error(void)
{
	write (1, "Error\n", 6);
}

int ft_checknumber(char **av)
{
	int	c;
	int i;

	i = 1;
	while (av[i] != NULL)
	{
		c = 0;
		if (av[i][c] == '-' || av[i][c] == '+')
			c++;
		while (av[i][c] != '\0')
		{
			if (!ft_isdigit(av[i][c]))
			{
				return(0);
			}	
			c++;	
		}
		i++;
	}
	return (1);
}
int	ft_checkinput(char **av)
{
	if (!ft_checknumber(av))
		return(0);
	return(1);
}

/*static int	ft_countwords(const char *str, char c)
{
	int	nword;
	int	flag;
	int	count;

	nword = 0;
	flag = -1;
	count = 0;
	while (str[count])
	{
		if (str[count] != c && flag < 0)
		{
			flag = 0;
			nword++;
		}
		else if (str[count] == c)
			flag = -1;
		count++;
	}
	return (nword);
*/

int	main(int ac, char **av)
{
	char **str;
	int i;

	i = 0;
	if (ac < 2)
		return(write_error(),0);
	if (ac == 2)
	{
		str = ft_split(av[1], ' ');
		printf("%d\n", ac);
	}
	else 
	{
		str = malloc(sizeof(char*) * ac);
		if (!str)
			return(0);
		while (av[i + 1] != NULL)
		{
			str[i] = ft_strcpy(str[i], av[i + 1]);
			i++;
		}
		str[i] = NULL;
	}
	if (!ft_checknumber(str))
		return (write_error() ,0);
	
	/*printf("%s\n", str[0]);
	printf("%s\n", str[1]);
	printf("%s\n", str[2]);
	if (!ft_checkinput(str))
	{
		printf("%d\n",ft_checkinput(ac, av));
		write_error();
	}*/	
	return (0);
		
}