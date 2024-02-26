/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-val <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:16:23 by gdel-val          #+#    #+#             */
/*   Updated: 2023/12/18 17:26:44 by gdel-val         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(int *a, size_t *size_a)
{
	int	num;

	if (*size_a < 2)
		return ;
	num = a[0];
	a[0] = a[1];
	a[1] = num;
	printf("sa\n");
}

void	sb(int *b, size_t *size_b)
{
	int	num;

	if (*size_b < 2)
		return ;
	num = b[0];
	b[0] = b[1];
	b[1] = num;
	printf("sb\n");
}

void	ss(int *a, int *b, size_t *size_a, size_t *size_b)
{
	int	num;

	if (*size_a < 2)
		return ;
	if (*size_b < 2)
		return ;
	num = a[0];
	a[0] = a[1];
	a[1] = num;
	num = b[0];
	b[0] = b[1];
	b[1] = num;
	printf("ss\n");
}
