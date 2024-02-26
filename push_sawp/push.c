/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-val <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:17:28 by gdel-val          #+#    #+#             */
/*   Updated: 2023/12/18 17:23:34 by gdel-val         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(int *a, int *b, size_t *size_a, size_t *size_b)
{
	int	i;

	if (*size_b == 0)
		return ;
	i = (int)*size_a;
	while (i > 0)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[0] = b[0];
	i = 0;
	while (i < (int)*size_b - 1)
	{
		b[i] = b[i + 1];
		i++;
	}
	(*size_a)++;
	(*size_b)--;
	printf("pa\n");
}

void	pb(int *a, int *b, size_t *size_a, size_t *size_b)
{
	int	i;

	if (*size_a == 0)
		return ;
	i = (int)*size_b;
	while (i > 0)
	{
		b[i] = b[i - 1];
		i--;
	}
	b[0] = a[0];
	i = 0;
	while (i < (int)*size_a - 1)
	{
		a[i] = a[i + 1];
		i++;
	}
	(*size_b)++;
	(*size_a)--;
	printf("pb\n");
}
