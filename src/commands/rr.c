/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42.angouleme.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 18:46:36 by stales            #+#    #+#             */
/*   Updated: 2022/04/27 13:18:12 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	rr(t_pswap *p)
{
	if (!p)
		return ;
	algo_rotate(&p->a);
	algo_rotate(&p->b);
	p->op += 2;
	ft_putstr_fd("rr\n", 1);
}
