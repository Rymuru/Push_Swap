/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcoenon <bcoenon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 12:22:31 by bcoenon           #+#    #+#             */
/*   Updated: 2022/01/31 17:38:10 by bcoenon          ###   ########.fr       */
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
int			fill_tab(int ac, char **av, t_stack *a);
int			stack_init(t_stack *st, int nb, char n);
int			error_manager(t_stack *st);
int			is_solved(t_stack *st);
int			check_arg(char *o);
int			solver(t_stack *a);
long int	ft_atoi(char *str);

size_t		ft_strlen(const char *s);

#endif
