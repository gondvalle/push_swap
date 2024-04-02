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

#include "../include/push_swap.h"

int	*idx(int i, int j)
{
	int	*num;

	num = ft_calloc(2, sizeof(int));
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
	while (i < *size_b - 1)
	{
		if (b[i] < b[i + 1])
			return (i);
		i++;
	}
	return (*size_b - 1);
}

long	ex(long n)
{
	exit(EXIT_FAILURE);
	return (n);
}

long	ft_atol(char *str)
{
	long	n;
	int		i;
	int		sign;

	n = 0;
	i = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!str[i])
		return (ft_putstr_fd("Error", 2), ex(n));
	while (str[i])
	{
		if (str[i] && !ft_isdigit(str[i]))
			return (ft_putstr_fd("Error", 2), ex(n));
		n = (n * 10) + (str[i++] - '0');
	}
	n *= sign;
	if (INT_MIN > n || n > INT_MAX)
		return (ft_putstr_fd("Error", 2), ex(n));
	return (n);
}

void	ft_free_ps(char **src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		free(src[i]);
		src[i] = NULL;
		i++;
	}
	free(src);
}
