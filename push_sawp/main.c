/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-val <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:43:17 by gdel-val          #+#    #+#             */
/*   Updated: 2024/02/26 20:00:43 by gdel-val         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*arraytoint(int argn, char**argv)
{
	int	i;
	int	j;
	int	*a;

	a = (int *)malloc((argn - 1) * sizeof(int));
	if (a == NULL)
		return (NULL);
	i = 0;
	while (++i < argn)
	{
		j = -1;
		while (argv[i][++j])
		{
			if (((argv[i][j] != '-') && !('0' <= argv[i][j] && argv[i][j] <= '9')) ||
					(!('0' <= argv[i][j + 1] && argv[i][j + 1] <= '9') && argv[i][j + 1]))
			{
				free(a);
				return (printf("Error"), NULL);
			}
		}
		a[i - 1] = atoi(argv[i]);
	}
	return (a);
}

int	*start(int *a, int *b, size_t *size_a, size_t *size_b)
{
	size_t	i;
	size_t	j;
	size_t	c;
	size_t	d;

	i = 0;
	c = 0;
	d = *size_b;
	while (i < *size_a)
	{
		j = 0;
		if (a[i] < b[0]) 
			j = middle(b, size_b) + 1;

		while (j < *size_b)
		{	
			if (a[i] < b[j] && j + i < d + c)
			{
				d = j;
				c = i;
			}
			j++;
		}
		if (a[i] > b[middle(b, size_b)] && middle(b, size_b) + 1 < d)
		{
			c = i;
			d = middle(b, size_b) + 1;
		}
		i++;
	}
	if (d == *size_b)
		d = 0;
	return (idx(c, d));
}

int	*finish(int *a, int *b, size_t *size_a, size_t *size_b)
{
	size_t	i;
	size_t	j;
	size_t	c;
	size_t	d;

	i = 0;
	c = 0;
	d = 0;
	while (i < *size_a)
	{
		j = 0;
		if (a[i] < b[0]) 
			j = middle(b, size_b) + 1;
		while (j < *size_b)
		{	
			if (a[i] < b[j] && (-1 * (int)j + (int)i) <= (-1 * (int)d + (int)c))
			{
				d = j;
				c = i;
				printf("\npito\n");
				printf("\n\ni: %zu\n", i);
				printf("\nj: %zu\n", j); 
				printf("\nc: %zu\n", c);
				printf("\nd: %zu\n\n", d);
				break ;
			}
			j++;
		}
		if (a[i] > b[middle(b, size_b)] && middle(b, size_b) < d)
		{
			c = i;
			d = middle(b, size_b);
			if (d == 0)
				d = 1;
		}
		i++;
	}
	if (d == *size_b) // Esto hay que quitarlo
		d = *size_b; // Poner en la funcionn test que si pasa esto no haga movimiento ya que lo hace igual
	printf("\nfinal c: %zu\n", c);
	printf("\nfinal d: %zu\n\n", d);
	return (idx(c, *size_b - d));
}

int	*finish2(int *a, int *b, size_t *size_a, size_t *size_b)
{
	size_t	i;
	size_t	j;
	size_t	c;
	size_t	d;

	i = 0;
	c = 0;
	d = 0;
	while (i < *size_a)
	{
		j = 0;
		if (a[i] > b[0]) 
			j = middle2(b, size_b) + 1;
		while (j < *size_b)
		{	
			if (a[i] > b[j] && ((int)i - (int)j) < (int)c - (int)d)
			{
				d = j;
				c = i;
			}
			if (a[i] > b[j])
				break ;
			j++;
		}
		if (a[i] < b[middle2(b, size_b)] && (middle2(b, size_b) < d || c == 0))
		{
			c = i;
			d = middle2(b, size_b);
			if (d == 0)
			    d = 1;
			else if (d == *size_b - 1)
				d = 0;
			break ;
		}
		i++;
	}
	printf("\nc:%zu ", c);
	printf("\nsize:%lu \n", *size_b - d);
	return (idx(c, *size_b - d));
}

void	test(int *a, int *b, size_t *size_a, size_t *size_b)
{
	int	*num;

	while (*size_a > 0)
	{	
		num = start(a, b, size_a, size_b);
		/*
		printf("a: ");
		for (unsigned int j = 0; j < *size_a; ++j) 
        	printf("%d ", a[j]);
		printf("\nb: ");
		for (unsigned int j = 0; j < *size_b; ++j)
        	printf("%d ", b[j]);
		printf("\n");*/
		/*while (num[0]-- > 0 && num[1]-- > 0)
			rr(a, b, size_a, size_b);*/
		while (num[0]-- > 0)
			ra(a, size_a);
		while (num[1]-- > 0)
			rb(b, size_b);
		pb(a, b, size_a, size_b);
		free(num);
	}
}

void	test2(int *a, int *b, size_t *size_a, size_t *size_b)
{
	int	*num;

	while (*size_a > 0)
	{
		num = finish(a, b, size_a, size_b);
		printf("a: ");
		for (unsigned int j = 0; j < *size_a; ++j)
        	printf("%d ", a[j]);
		printf("\nb: ");
		for (unsigned int j = 0; j < *size_b; ++j)
        	printf("%d ", b[j]);
		printf("\n");
		while (num[0]-- > 0)
			ra(a, size_a);
		while (num[1]-- > 0)
			rrb(b, size_b); 
		pb(a, b, size_a, size_b);
		free(num);
	}
}

void	test3(int *a, int *b, size_t *size_a, size_t *size_b)
{
	int	*numS;
	int	*numF;

	while (*size_a > 0)
	{
		numS = start2(a, b, size_a, size_b);
		numF = finish2(a, b, size_a, size_b);
		if (numF[0] + numF[1] < numS[0] + numS[1])
		{
			while (numF[0]-- > 0)
				ra(a, size_a);
			while (numF[1]-- > 0)
				rrb(b, size_b);
		}
		else
		{
			while (numS[0] > 0 && numS[1] > 0)
			{
				rr(a, b, size_a, size_b);
				numS[0]--;
				numS[1]--;
			}
			while (numS[0]--  > 0)
				ra(a, size_a);
			while (numS[1]-- > 0)
				rb(b, size_b);
		}
		pb(a, b, size_a, size_b);
		free(numS);
		free(numF);
	}
}

void    last(int *a, int *b, size_t *size_a, size_t *size_b)
{
	int     fer;
	
    fer = middle2(b, size_b) + 1;
	while(fer > 0)
	{
	    rb(b, size_b);
	    fer--;
	}
	while(*size_b > 0)
	    pa(a, b, size_a, size_b);
}

int	main(int argn, char **argv)
{
	int		*a;
	int		*b;
	size_t	size_a;
	size_t	size_b;

	a = arraytoint(argn, argv);
	if (!a)
		return (0);
	size_a = argn - 1;
	b = (int *)calloc((argn - 1), sizeof(int));
	if (!b)
		return (0);
	size_b = 0;
	for (unsigned int j = 0; j < size_a; ++j) 
        printf("%d ", a[j]);
	printf("\nb: ");
	for (unsigned int j = 0; j < size_b; ++j)
        printf("%d ", b[j]);
	pb(a, b, &size_a, &size_b);
	pb(a, b, &size_a, &size_b);
	test3(a, b, &size_a, &size_b);
	last(a, b, &size_a, &size_b);
	printf("\na: ");
	for (unsigned int j = 0; j < size_a; ++j) 
        printf("%d ", a[j]);
	printf("\nb: ");
	for (unsigned int j = 0; j < size_b; ++j)
        printf("%d ", b[j]);
	printf("\n");
	free(a);
	free(b);
	
	return (0);
}
