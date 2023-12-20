#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

int	*arraytoint(int argn, char**argv)
{
	int	i;
	int	j;
	int	*a;

	a = (int *)malloc((argn - 1) * sizeof(int));
    if (a == NULL)
		return (NULL);
	i = 0;
	while(++i < argn)
	{
		j = -1;
		while(argv[i][++j])
		{			
			if (((argv[i][j] != '-') && !('0' <= argv[i][j] && argv[i][j] <= '9')) ||
					(!('0' <= argv[i][j + 1] && argv[i][j + 1] <= '9') && argv[i][j + 1]))
			{
				free(a);
				return(printf("Error"), NULL);
			}
		}
		a[i - 1] = atoi(argv[i]);
	}
	return (a);
}

void sa(int *a, size_t *size_a)
{
	int num;

	if (*size_a < 2)
		return ;
	num = a[0];
	a[0] = a[1];
	a[1] = num;
	printf("sa\n");
}

void sb(int *b, size_t *size_b)
{
	int num;

	if (*size_b < 2)
		return ;
	num = b[0];
	b[0] = b[1];
	b[1] = num;
	printf("sb\n");
}

void ss(int *a, int *b, size_t *size_a, size_t *size_b)
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

void pa(int *a, int *b, size_t *size_a, size_t *size_b)
{
	int	i;

	if (*size_b == 0)
		return ;
	i = (int)*size_a;
	while(i > 0)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[0] = b[0];
	i = 0;
	while(i < (int)*size_b - 1)
	{
		b[i] = b[i + 1];
		i++;
	}
	(*size_a)++;
	(*size_b)--;
	printf("pa\n");
}

void pb(int *a, int *b, size_t *size_a, size_t *size_b)
{
	int	i;

	if (*size_a == 0)
		return ;
	i = (int)*size_b;
	while(i > 0)
	{
		b[i] = b[i - 1];
		i--;
	}
	b[0] = a[0];
	i = 0;
	while(i < (int)*size_a - 1)
	{
		a[i] = a[i + 1];
		i++;
	}
	(*size_b)++;
	(*size_a)--;
	printf("pb\n");
}

void ra(int *a, size_t *size_a)
{
	int	i;
	int	num;

	if (*size_a < 2)
		return ;
	i = 0;
	num = a[0];
	while(i < (int)*size_a - 1)
	{
		a[i] = a[i + 1];
		i++;
	}
	a[*size_a - 1] = num;
	printf("ra\n");
}

void rb(int *b, size_t *size_b)
{
	int	i;
	int	num;

	if (*size_b < 2)
		return ;
	i = 0;
	num = b[0];
	while(i < (int)*size_b - 1)
	{
		b[i] = b[i + 1];
		i++;
	}
	b[*size_b - 1] = num;
	printf("rb\n");
}

void rr(int *a, int *b, size_t *size_a, size_t *size_b)
{
	int	i;
	int	num;

	if (*size_b < 2)
		return ;
	if (*size_a < 2)
		return ;
	i = 0;
	num = b[0];
	while(i < (int)*size_b - 1)
	{
		b[i] = b[i + 1];
		i++;
	}
	b[*size_b - 1] = num;
	i = 0;
	num = a[0];
	while(i < (int)*size_a - 1)
	{
		a[i] = a[i + 1];
		i++;
	}
	a[*size_a - 1] = num;
	printf("rr\n");
}


void rra(int *a, size_t *size_a)
{
	int	i;
	int	num;

	if (*size_a < 2)
		return ;
	num = a[*size_a - 1];
	i = (int)*size_a;
	while(i > 0)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[0] = num;
	printf("rra\n");
}

void rrb(int *b, size_t *size_b)
{
	int	i;
	int	num;

	if (*size_b < 2)
		return ;
	num = b[*size_b - 1];
	i = (int)*size_b;
	while(i > 0)
	{
		b[i] = b[i - 1];
		i--;
	}
	b[0] = num;
	printf("rrb\n");
}

void rrr(int *a, int *b, size_t *size_a, size_t *size_b)
{
	int	i;
	int	num;

	if (*size_b < 2)
		return ;
	if (*size_a < 2)
		return ;
	num = a[*size_a - 1];
	i = (int)*size_a;
	while(i > 0)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[0] = num;

	num = b[*size_b - 1];
	i = (int)*size_b;
	while(i > 0)
	{
		b[i] = b[i - 1];
		i--;
	}
	b[0] = num;
	printf("rrr\n");
}

int	*idx(i, j)
{
	int	*num;

	num = calloc(2, sizeof(int));
	if (!num)
		return (NULL);
	num[0] = i;
	num[1] = j;
	return (num);
}

int	*start(int *a, int *b, size_t *size_a, size_t *size_b)
{
	int	move;
	int	i;
	int	j;
	int	c;
	int	d;

	i = 0;
	move = -1;
	while (i < *size_a && (move < 0 || i < move))
	{
		c = i;
		j = 0;
		while (j < *size_b && (move < 0 || i + j < move))
		{
			d = j + 1;
			if (j == *size_b || (b[j] > b[j + 1] && (a[i] > b[j] || a[i] < b[j + 1]))
					|| (b[j] < a[i] && a[i] < b[j + 1]))
				move = c + d;
			j++;
		}
		i++;
	}
	return (idx(c, d));
}

int	*finish(int *a, int *b, size_t *size_a, size_t *size_b)
{
	int	move;
	int	i;
	int	j;
	int	c;
	int	d;

	i = *size_a;
	move = -1;
	while (0 < i && (move < 0 || i < move))
	{
		c = i;
		j = *size_b;
		while (0 < j && (move < 0 || i + j < move))
		{
			d = j;
			if (j == 0 || (b[j] < b[j - 1] && (a[i] < b[j] || a[i] > b[j - 1]))
					|| (b[j] > a[i] && a[i] > b[j - 1]))
				move = c + d;
			j--;
		}
		i--;
	}
	return (idx(c, d));
}

int main(int argn, char **argv)
{
	int	*a;
	int *b;
	size_t size_a;
	size_t size_b;
	int	*num1;
	int	*num2;

	a = arraytoint(argn, argv);
	if (!a)
		return(0);
	size_a = argn - 1;
	b = (int *)calloc((argn - 1), sizeof(int));
    if (!b)
		return (0);
	size_b = 0;
	pb(a, b, &size_a, &size_b);
	pb(a, b, &size_a, &size_b);
	printf("a: ");
	for (unsigned int j = 0; j < size_a; ++j) {
        printf("%d ", a[j]);
		}
	printf("\nb: ");
	for (unsigned int j = 0; j < size_b; ++j) {
        printf("%d ", b[j]);
		}
	printf("\n");
	num1 = start(a, b, &size_a, &size_b);
	num2 = finish(a, b, &size_a, &size_b);
	printf("start:\n");
	for (unsigned int j = 0; j < 2; ++j) {
        printf("%d ", num1[j]);
		}
	printf("\nfinish:\n");
	for (unsigned int j = 0; j < 2; ++j) {
        printf("%d ", num2[j]);
		}
	free(a);
	free(b);
	free(num1);
	free(num2);

	return(0);
}
