/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-val <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:23:59 by gdel-val          #+#    #+#             */
/*   Updated: 2024/02/19 20:27:29 by gdel-val         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stddef.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <string.h>

void	sa(int *a, size_t *size_a);
void	sb(int *b, size_t *size_b);
void	ss(int *a, int *b, size_t *size_a, size_t *size_b);
void	pa(int *a, int *b, size_t *size_a, size_t *size_b);
void	pb(int *a, int *b, size_t *size_a, size_t *size_b);
void	rra(int *a, size_t *size_a);
void	rrb(int *b, size_t *size_b);
void	rrr(int *a, int *b, size_t *size_a, size_t *size_b);
void	ra(int *a, size_t *size_a);
void	rb(int *b, size_t *size_b);
void	rr(int *a, int *b, size_t *size_a, size_t *size_b);
int		*idx(int i, int j);
size_t	middle(int *b, size_t *size_b);
int		*start_start(int *a, int *b, size_t *size_a, size_t *size_b);
int		*start_finishparttwo(int i, int *b, size_t *size_b);
int		*start_finish(int *a, int *b, size_t *size_a, size_t *size_b);
void	reversemoves(int *a, int *b, size_t *size_a, size_t *size_b);
void	normalmoves(int *a, int *b, size_t *size_a, size_t *size_b);
void	moves(int *a, int *b, size_t *size_a, size_t *size_b);
void	last(int *a, int *b, size_t *size_a, size_t *size_b);
long	ft_atol(char *str);
int		strlendouble(char **arr);
char	*concatenate_arguments(int argc, char **argv);
size_t	len_size(int argn, char **argv);
size_t	big(int *a, size_t *size_a);
void	threenum(int *a, size_t *size_a);
void	ft_free_ps(char **src);
int		sorted(int *a, size_t *size_a);
int		repeated(int *a, size_t *size_a);
char	*concatenate_arguments(int argc, char **argv);
int		*arraytoint(int argn, char**argv);
int		*stack(int argn, char **argv);
void	push_swap(int *a, int *b, size_t *size_a, size_t *size_b);

#endif