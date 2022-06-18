/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcoenon <bcoenon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:25:12 by bcoenon           #+#    #+#             */
/*   Updated: 2022/06/18 18:31:13 by bcoenon          ###   ########.fr       */
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

int	dejavu(long int *tab, int size, long int n)
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

	if (ac == 1)
		return (0);
	a = malloc(sizeof(t_stack));
	if (!a)
		error_manager(a);
	if (safe(ac, av) == 1)
	{
		free(a);
		write(2, "Error\n", 6);
		return (1);
	}
	stack_init(a, ac - 1, 'a');
	if (fill_tab(ac, av, a) == 1)
	{
		free(a);
		return (1);
	}
	if (ac <= 6)
		quick_init(a);
	else
		solver(a);
	free_stack(a);
	return (0);
}
