/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42.angouleme.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:59:59 by stales            #+#    #+#             */
/*   Updated: 2022/04/27 13:18:01 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	rrr(t_pswap *p)
{
	if (!p)
		return ;
	algo_reverse_rotate(&p->a);
	algo_reverse_rotate(&p->b);
	p->op += 2;
	ft_putstr_fd("rrr\n", 1);
}
