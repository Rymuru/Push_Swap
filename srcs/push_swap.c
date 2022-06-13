/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcoenon <bcoenon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:25:12 by bcoenon           #+#    #+#             */
/*   Updated: 2022/06/13 16:31:05 by bcoenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_arg(char *o)
{
	int	i;

	i = 0;
	if (o[0] == '\0' || ft_strlen(o) > 11)
		return (1);
	while (o[i] && ((o[i] >= '0' && o[i] <= '9') || o[i] == '-'))
	{
		i++;
		if (o[i] == '\0')
			return (0);
	}
	return (1);
}

int	safe(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac == 1)
	{
		return (1);
	}
	while (i < ac)
	{
		if (check_arg(av[i]) != 0)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	dejavu(int *tab, int size, long int n)
{
	int	i;

	i = 0;
	if (size == 0)
		return (0);
	while (i < size)
	{
		if (n == tab[i])
			return (1);
		i++;
	}
	return (0);
}

int	fill_tab(int ac, char **av, t_stack *a)
{
	int			i;
	long int	temp;
	int			twin;

	i = 1;
	twin = 0;
	while (i < ac && twin == 0)
	{
		temp = ft_atoi(av[i]);
		if (temp > 2147483647 || temp < -2147483648)
			return (error_manager(a));
		twin = dejavu(a->address, i - 1, temp);
		a->address[i - 1] = temp;
		i++;
	}
	if (twin == 1)
		return (error_manager(a));
	return (0);
}

int	main(int ac, char **av)
{
	t_stack	*a;

	a = malloc(sizeof(t_stack));
	if (safe(ac, av) == 1)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	stack_init(a, ac, 'a');
	if (fill_tab(ac, av, a) == 1)
		return (1);
	solver(a);
	return (0);
}
