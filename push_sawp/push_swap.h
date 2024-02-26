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
# include <unistd.h>
# include <stdio.h>
# include <string.h>

int		tabsize(int *tab);
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
int		*idx(int i,int j);
size_t	middle(int *b, size_t *size_b);

#endif
