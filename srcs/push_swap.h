/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcoenon <bcoenon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 12:22:31 by bcoenon           #+#    #+#             */
/*   Updated: 2022/01/31 16:23:03 by bcoenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_stack
{
	char	name;
	size_t	len;
	int		*address;
}	t_stack;

int			main(int ac, char **av);
int			safe(int ac, char **av);
int			dejavu(int *tab, int size, long int n);
int			is_solved(t_stack st);
int			check_arg(char *o);
long int	ft_atoi(char *str);

size_t		ft_strlen(const char *s);

t_stack		fill_tab(int ac, char **av, t_stack a);
t_stack		stack_init(t_stack a, int nb, char n);
t_stack		error_manager(t_stack str);
t_stack		solver(t_stack a);

#endif
