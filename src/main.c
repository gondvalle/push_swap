/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-val <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:43:17 by gdel-val          #+#    #+#             */
/*   Updated: 2024/03/04 19:18:59 by gdel-val         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	*arraytoint(int argn, char**argv)
{
	int		i;
	int		j;
	int		*a;
	char	c;
	char	d;

	a = (int *)ft_calloc(argn, sizeof(int));
	if (a == NULL)
		return (NULL);
	i = -1;
	while (++i < argn)
	{
		j = -1;
		while (argv[i][++j])
		{
			c = argv[i][j];
			d = argv[i][j + 1];
			if (((c != '-') && !('0' <= c && c <= '9') && (c != '+'))
				|| (!('0' <= d && d <= '9') && d))
				return (free(a), ft_putstr_fd("Error", 2), NULL);
		}
		a[i] = ft_atol(argv[i]);
	}
	return (a);
}

char	*concatenate_arguments(int argc, char **argv)
{
	size_t	total_length;
	char	*result;
	int		i;

	i = 0;
	total_length = 0;
	while (++i < argc)
		total_length = total_length + ft_strlen(argv[i]);
	result = (char *)ft_calloc(total_length + argc, sizeof(char));
	if (!result)
		return (NULL);
	result[0] = '\0';
	i = 1;
	while (i < argc)
	{
		ft_strlcat(result, argv[i], total_length + argc);
		if (i < argc - 1)
			ft_strlcat(result, " ", total_length + argc);
		i++;
	}
	return (result);
}

int	*stack(int argn, char **argv)
{
	char	**arg;
	char	*src;
	int		*stack;

	stack = 0;
	if (argn > 0)
	{
		src = concatenate_arguments(argn, argv);
		if (!src)
			return (NULL);
		arg = ft_split(src, ' ');
		if (!arg)
			return (free(src), NULL);
		stack = arraytoint(strlendouble(arg), arg);
		if (!stack)
			return (free(src), ft_free_ps(arg), NULL);
		return (free(src), ft_free_ps(arg), stack);
	}
	return (stack);
}

void	push_swap(int *a, int *b, size_t *size_a, size_t *size_b)
{
	if (*size_a <= 3)
	{
		threenum(a, size_a);
		return ;
	}
	pb(a, b, size_a, size_b);
	pb(a, b, size_a, size_b);
	moves(a, b, size_a, size_b);
	last(a, b, size_a, size_b);
	while (big(a, size_a) != *size_a - 1)
		rra(a, size_a);
}

int	main(int argn, char **argv)
{
	int		*a;
	int		*b;
	size_t	size_a;
	size_t	size_b;

	a = stack(argn, argv);
	if (!a)
		return (0);
	size_a = len_size(argn, argv);
	if (!size_a)
		return (0);
	if (repeated(a, &size_a) == 1)
		return (free(a), ft_putstr_fd("Error", 2), 0);
	if (sorted(a, &size_a) == 1)
		return (free(a), 0);
	b = (int *)ft_calloc(size_a, sizeof(int));
	if (!b)
		return (free(a), 0);
	size_b = 0;
	push_swap(a, b, &size_a, &size_b);
	free(a);
	free(b);
	return (0);
}
