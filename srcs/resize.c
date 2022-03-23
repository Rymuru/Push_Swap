/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcoenon <bcoenon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 18:11:13 by bcoenon           #+#    #+#             */
/*   Updated: 2022/03/11 18:35:38 by bcoenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_plusun(t_stack *st)
{
    int i;
    
    i = st->len;
    while (i > 0)
    {
        st->address[i] = st->address[i - 1]
        i--;
    }
    st->len++;
}

void    ft_moinsun(t_stack *st)
{
    int i;

    i = 0;
    while (i < st->len - 1)
    {
        st->address[i] = st->address[i + 1];
        i++;
    }
    st->len--;
}