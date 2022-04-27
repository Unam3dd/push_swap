/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42.angouleme.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 15:48:45 by stales            #+#    #+#             */
/*   Updated: 2022/04/27 13:17:42 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	sa(t_pswap *p)
{
	if (!p)
		return ;
	algo_swap(&p->a);
	p->op++;
	ft_putstr_fd("sa\n", 1);
}
