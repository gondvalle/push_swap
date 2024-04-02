/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-val <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:57:27 by gdel-val          #+#    #+#             */
/*   Updated: 2024/03/12 21:57:30 by gdel-val         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	*start_start(int *a, int *b, size_t *size_a, size_t *size_b)
{
	size_t	i;
	size_t	j;
	size_t	c;
	size_t	d;

	i = -1;
	c = 0;
	d = *size_b;
	while (++i < *size_a)
	{
		j = -1;
		if (a[i] > b[0])
			j = middle(b, size_b);
		while (++j < *size_b)
			if (a[i] > b[j] && j + i < d + c && i != big(a, size_a))
				d = ((c = i, j));
		if (a[i] < b[middle(b, size_b)] && middle(b, size_b) + 1 < d)
			c = ((d = middle(b, size_b) + 1, i));
	}
	if (d == *size_b)
		d = 0;
	return (idx(c, d));
}

int	*start_finishparttwo(int i, int *b, size_t *size_b)
{
	size_t	d;

	d = middle(b, size_b) + 1;
	if (d == 0)
		d = 1;
	else if (d == *size_b - 1)
		d = 0;
	return (idx(i, *size_b - d));
}

int	*start_finish(int *a, int *b, size_t *size_a, size_t *size_b)
{
	size_t	i;
	size_t	j;
	size_t	c;
	size_t	d;

	i = -1;
	c = 0;
	d = 0;
	while (++i < *size_a)
	{
		j = -1;
		if (a[i] > b[0])
			j = middle(b, size_b);
		while (++j < *size_b)
		{
			if (a[i] > b[j] && ((int)i - (int)j) < (int)c - (int)d
				&& i != big(a, size_a))
				d = ((c = i, j));
			if (a[i] > b[j])
				break ;
		}
		if (a[i] < b[middle(b, size_b)] && (middle(b, size_b) < d || c == 0))
			return (start_finishparttwo(i, b, size_b));
	}
	return (idx(c, *size_b - d));
}
