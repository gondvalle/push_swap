/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-val <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 22:02:04 by gdel-val          #+#    #+#             */
/*   Updated: 2024/03/12 22:02:06 by gdel-val         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	threenum(int *a, size_t *size_a)
{
	size_t	new;

	new = 0;
	while (big(a, size_a) != *size_a - 1)
		ra(a, size_a);
	new = *size_a - 1;
	if (big(a, &new) != *size_a - 2)
		sa(a, size_a);
}

void	reversemoves(int *a, int *b, size_t *size_a, size_t *size_b)
{
	int	*num_f;

	num_f = start_finish(a, b, size_a, size_b);
	if (!num_f)
		return ;
	if (num_f[0] == a[big(a, size_a)])
	{
		ra(a, size_a);
		return ;
	}
	while (num_f[0]-- > 0)
		ra(a, size_a);
	while (num_f[1]-- > 0)
		rrb(b, size_b);
	free(num_f);
}

void	normalmoves(int *a, int *b, size_t *size_a, size_t *size_b)
{
	int	*num_s;

	num_s = start_start(a, b, size_a, size_b);
	if (!num_s)
		return ;
	while (num_s[0] > 0 && num_s[1] > 0 && *size_a > 1 && *size_b > 1)
	{
		rr(a, b, size_a, size_b);
		num_s[0]--;
		num_s[1]--;
	}
	while (num_s[0]-- > 0)
		ra(a, size_a);
	while (num_s[1]-- > 0)
		rb(b, size_b);
	free(num_s);
}

void	moves(int *a, int *b, size_t *size_a, size_t *size_b)
{
	int	*num_f;
	int	*num_s;

	while (*size_a > 3)
	{
		num_f = start_finish(a, b, size_a, size_b);
		if (!num_f)
			return ;
		num_s = start_start(a, b, size_a, size_b);
		if (!num_s)
		{
			free(num_f);
			return ;
		}
		if ((int)(num_f[0] + num_f[1]) < num_s[0] + num_s[1])
			reversemoves(a, b, size_a, size_b);
		else
			normalmoves(a, b, size_a, size_b);
		pb(a, b, size_a, size_b);
		free(num_f);
		free(num_s);
	}
	threenum(a, size_a);
}

void	last(int *a, int *b, size_t *size_a, size_t *size_b)
{
	size_t	ord;

	ord = middle(b, size_b) + 1;
	if (ord >= *size_b / 2)
	{
		ord = *size_b - ord;
		while (ord > 0)
		{
			rrb(b, size_b);
			ord--;
		}
	}
	while (ord > 0)
	{
		rb(b, size_b);
		ord--;
	}
	while (*size_b > 0)
	{
		while (a[0] < b[0] && b[0] < a[big(a, size_a)])
			ra(a, size_a);
		pa(a, b, size_a, size_b);
		while (big(a, size_a) != *size_a - 1 && a[*size_a - 1] > b[0])
			rra(a, size_a);
	}
}
