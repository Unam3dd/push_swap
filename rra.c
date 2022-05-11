/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42.angouleme.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:59:01 by stales            #+#    #+#             */
/*   Updated: 2022/05/10 09:19:47 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	rra(t_pswap *p)
{
	if (!p)
		return ;
	algo_reverse_rotate(&p->a);
	ft_putstr_fd("rra\n", 1);
}
