/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-val <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:34:16 by gdel-val          #+#    #+#             */
/*   Updated: 2024/03/14 19:34:26 by gdel-val         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	strlendouble(char **arr)
{
	int	length;

	length = 0;
	while (arr[length] != NULL)
		length++;
	return (length);
}

size_t	len_size(int argn, char **argv)
{
	char	**arg;
	char	*src;
	int		*stack;
	size_t	len;

	stack = 0;
	len = 0;
	if (argn > 0)
	{
		src = concatenate_arguments(argn, argv);
		if (!src)
			return (0);
		arg = ft_split(src, ' ');
		if (!arg)
			return (free(src), 0);
		len = strlendouble(arg);
		return (free(src), ft_free_ps(arg), len);
	}
	return (len);
}

size_t	big(int *a, size_t *size_a)
{
	size_t	i;
	size_t	pos;

	i = 0;
	pos = 0;
	while (i < *size_a)
	{
		if (a[i] > a[pos])
			pos = i;
		i++;
	}
	return (pos);
}

int	sorted(int *a, size_t *size_a)
{
	int	i;

	i = 0;
	while (i < (int)*size_a - 1)
	{
		if (a[i] > a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	repeated(int *a, size_t *size_a)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < *size_a)
	{
		j = 0;
		while (j < *size_a - 1)
		{
			if (i == j)
				j++;
			if (a[i] == a[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
