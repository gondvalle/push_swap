/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-val <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:30:32 by gdel-val          #+#    #+#             */
/*   Updated: 2024/02/19 20:58:12 by gdel-val         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*idx(int i,int j)
{
	int	*num;

	num = calloc(2, sizeof(int));
	if (!num)
		return (NULL);
	num[0] = i;
	num[1] = j;
	return (num);
}

size_t	middle(int *b, size_t *size_b)
{
	size_t	i;

	i = 0;
	while (i < *size_b)
	{
		if (b[i] > b[i + 1])
			return (i);
		i++;
	}
	return (*size_b - 1);
}

int	abs(int num)
{
	if (num < 0)
		num = -num;
	return(num);
}

int	*rotate(int *b, size_t *size_b)
{
	int		*a;
	size_t	i;

	i = 0;
	a = calloc(*size_b, sizeof(int));
	if (!a)
		return (NULL);
	while (i < *size_b)
	{
		a[i] = b[*size_b - 1 - i];
		i++;
	}
	return (a);
}

