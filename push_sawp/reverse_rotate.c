/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-val <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:19:25 by gdel-val          #+#    #+#             */
/*   Updated: 2023/12/18 17:25:20 by gdel-val         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(int *a, size_t *size_a)
{
	int	i;
	int	num;

	if (*size_a < 2)
		return ;
	num = a[*size_a - 1];
	i = (int)*size_a;
	while (i > 0)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[0] = num;
	printf("rra\n");
}

void	rrb(int *b, size_t *size_b)
{
	int	i;
	int	num;

	if (*size_b < 2)
		return ;
	num = b[*size_b - 1];
	i = (int)*size_b;
	while (i > 0)
	{
		b[i] = b[i - 1];
		i--;
	}
	b[0] = num;
	printf("rrb\n");
}

void	rrr(int *a, int *b, size_t *size_a, size_t *size_b)
{
	int	i;
	int	num;

	if (*size_b < 2)
		return ;
	if (*size_a < 2)
		return ;
	num = a[*size_a - 1];
	i = (int)*size_a;
	while (i > 0)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[0] = num;
	num = b[*size_b - 1];
	i = (int)*size_b;
	while (i > 0)
	{
		b[i] = b[i - 1];
		i--;
	}
	b[0] = num;
	printf("rrr\n");
}
