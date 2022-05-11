/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42.angouleme.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:59:31 by stales            #+#    #+#             */
/*   Updated: 2022/05/10 09:19:44 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	rrb(t_pswap *p)
{
	if (!p)
		return ;
	algo_reverse_rotate(&p->b);
	ft_putstr_fd("rrb\n", 1);
}
