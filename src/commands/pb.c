/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42.angouleme.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 16:52:34 by stales            #+#    #+#             */
/*   Updated: 2022/04/27 13:18:20 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	pb(t_pswap *p)
{
	if (!p)
		return ;
	algo_push(&p->b, &p->a);
	p->op++;
	ft_putstr_fd("pb\n", 1);
}
