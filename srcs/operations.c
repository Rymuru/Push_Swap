/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcoenon <bcoenon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 16:29:52 by bcoenon           #+#    #+#             */
/*   Updated: 2022/01/31 16:42:14 by bcoenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	sa_sb(t_stack st)
{
	int	temp;

	temp = st.address[0];
	st.address[0] = st.address[1];
	st.address[1] = st.address[temp];
	if (st.name == 'a')
		write(1, "sa\n", 3);
	else if (st.name == 'b')
		write(1, "sb\n", 3);
	return (st);
}

t_stack	ss(t_stack st, t_stack st2)
{
	
}