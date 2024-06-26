/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42.angouleme.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 16:50:15 by stales            #+#    #+#             */
/*   Updated: 2022/04/27 13:18:24 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	pa(t_pswap *p)
{
	if (!p)
		return ;
	algo_push(&p->a, &p->b);
	p->op++;
	ft_putstr_fd("pa\n", 1);
}
