/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcoenon <bcoenon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 16:02:30 by bcoenon           #+#    #+#             */
/*   Updated: 2022/06/15 21:48:18 by bcoenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	solver(t_stack *a)
{
	t_stack	*b;
	t_stack	*easy;

	b = malloc(sizeof(t_stack));
	easy = malloc(sizeof(t_stack));
	stack_init(b, a->len, 'b');
	stack_init(easy, a->len, 'a');
	if (b->len == 0 || easy->len == 0)
		error_manager(a);
	simplifier(a, easy);
	b->len = 0;
	radix(easy, b);
	return (0);
}

int	is_solved(t_stack *st)
{
	long int	i;

	i = 0;
	while (i < st->len)
	{
		if (st->address[i] > st->address[i + 1])
			return (1);
		++i;
	}
	return (0);
}

/*
c[0] = lowest value
c[1] = location of this value
c[2] = value to write in new stack
c[3] = precedent minimum value
*/

void	simplifier(t_stack *a, t_stack *easy)
{
	long int	c[4];
	long int	i;

	c[0] = a->address[0];
	c[1] = 0;
	c[2] = 0;
	c[3] = -2147483648;
	i = 0;

	while (c[2] < a->len)
	{
		while (i < a->len)
		{
			if (a->address[i] < c[0] && a->address[i] >= c[3])
			{
				c[0] = a->address[i];
				c[1] = i;
			}
			++i;
		}
		easy->address[c[1]] = c[2];
		c[3] = a->address[c[1]];
		i = 0;
		++c[2];
	}
	put_tab(easy);
}

void put_tab(t_stack *st)
{
	long int i;

	i = 0;
	while (i <= st->len)
	{
		ft_putnbr(st->address[i]);
		i++;
	}
	ft_putchar('\n');
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(n * -1);
	}
	else if (n >= 0 && n <= 9)
		ft_putchar(n + '0');
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}