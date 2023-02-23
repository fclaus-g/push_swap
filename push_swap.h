/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario42 <usuario42@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:27:55 by usuario42         #+#    #+#             */
/*   Updated: 2023/02/23 09:58:33 by usuario42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft-main/libft.h"

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


# endif