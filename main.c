/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:35:51 by usuario42         #+#    #+#             */
/*   Updated: 2023/02/28 11:02:34 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


/*int	ft_checkinput(char **av)
{
	if (!ft_checknumber(av))
		return(0);
	return(1);
}

static int	ft_countwords(const char *str, char c)
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
	t_box	box;
	int i;

	i = 0;
	if (ac < 2)
		return(write_error(),0);
	if (ac == 2)
	{
		box.arg = ft_split(av[1], ' ');
		printf("%d\n", ac);
	}
	else 
	{
		box.arg = malloc(sizeof(char*) * ac);
		if (!box.arg)
			return(0);
		while (av[i + 1] != NULL)
		{
			box.arg[i] = ft_strcpy(box.arg[i], av[i + 1]);
			i++;
		}
		box.arg[i] = NULL;
	}
	if (!ft_checknumber(&box))
		return (write_error() ,0);
	box.stack_a = malloc(sizeof(int) * ac);
	box.stack_b = malloc(sizeof(int) * ac);
	box.stack_b = 0;
	arg_to_array(&box);
	simplifier(&box);
	
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