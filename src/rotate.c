/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-val <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:18:42 by gdel-val          #+#    #+#             */
/*   Updated: 2023/12/18 17:25:50 by gdel-val         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ra(int *a, size_t *size_a)
{
	int	i;
	int	num;

	if (*size_a < 2)
		return ;
	i = 0;
	num = a[0];
	while (i < (int)*size_a - 1)
	{
		a[i] = a[i + 1];
		i++;
	}
	a[*size_a - 1] = num;
	ft_putstr_fd("ra\n", 1);
}

void	rb(int *b, size_t *size_b)
{
	int	i;
	int	num;

	if (*size_b < 2)
		return ;
	i = 0;
	num = b[0];
	while (i < (int)*size_b - 1)
	{
		b[i] = b[i + 1];
		i++;
	}
	b[*size_b - 1] = num;
	ft_putstr_fd("rb\n", 1);
}

void	rr(int *a, int *b, size_t *size_a, size_t *size_b)
{
	int	i;
	int	num;

	if (*size_b < 2)
		return ;
	if (*size_a < 2)
		return ;
	i = 0;
	num = b[0];
	while (i < (int)*size_b - 1)
	{
		b[i] = b[i + 1];
		i++;
	}
	b[*size_b - 1] = num;
	i = 0;
	num = a[0];
	while (i < (int)*size_a - 1)
	{
		a[i] = a[i + 1];
		i++;
	}
	a[*size_a - 1] = num;
	ft_putstr_fd("rr\n", 1);
}
