/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:27:55 by usuario42         #+#    #+#             */
/*   Updated: 2023/02/27 11:25:31 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft/libft.h"

//definimos una estructura donde alojaremos los int 
typedef struct s_pila
{
	int	content;
	int	indice;
	int	posicion;
	int	target;
	int	cost_a;
	int cost_b;
	
}t_pila;
char	*ft_strcpy(char *dst, const char *src);


# endif