/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:27:55 by usuario42         #+#    #+#             */
/*   Updated: 2023/03/24 18:16:47 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>

//definimos una estructura donde alojaremos los int 
typedef struct s_box
{
	char	**arg;
	int		*stack_a;
	int		*stack_b;
	int		len;
	int		alen;
	int		blen;
	int		cost[2];

}t_box;

void	ft_exit(void);
void		printa(int *array, int len);
void	checkab(t_box *box);
//-----CHEQUEO DE ENTRADA------

//check_input_utils.c 
int			ft_isdigit(int c);
size_t		ft_strlen(const char *s);
void		write_error(void);

//check_input.c
int			ft_checknumber(t_box *box);
int			check_repeat(t_box *box);
int			*simplifier(t_box *box);
int			in_order(t_box *box);

//arg_to_array.c
long int	ft_longatoi(const char *str);
void		arg_to_array(t_box *box);
int			*ft_arraycpy(int *dst, int *array, int len);
size_t		ft_mtrlen(char **matriz);
void		*free_matrix(char **matrix);

//save_args.c
int			save_args(t_box *box, int ac, char **av);
//count-words y copywords
char		**ft_split(char const *s, char c);
char		*ft_strcpy(char *dst, const char *src);

//------OPERACIONES-----

//push.c
void		push_a(t_box *box);
void		push_b(t_box *box);

//swap.c
void		swap_a(t_box *box, int n);
void		swap_b(t_box *box, int n);
void		swap_ab(t_box *box);

//rotate.c
void		rotate_a(t_box *box, int n);
void		rotate_b(t_box *box, int n);
void		rotate_ab(t_box *box);

//reverse.c
void		reverse_a(t_box *box, int n);
void		reverse_b(t_box *box, int n);
void		reverse_ab(t_box *box);

//sorting.c
void		sort2(t_box *box);
void		sort3(t_box *box);
void		sort4y5(t_box *box);
void		bigsort(t_box *box);
void		ft_sorting(t_box *box);

//sorting_utils.c
int			ft_locate_min(int *array, int len);
void	a_to_b(t_box *box);
void	best_pusha(t_box *box);
int	a_moves(t_box *box, int n);
int	suma_abs(int x, int y);
int	ft_locate_max(int *array, int len);

//exec_rotates.c
void	exec_rotates(t_box *box);
void	rr_up(t_box *box, int x, int y);
void	rrr_down(t_box *box, int x, int y);

#endif
