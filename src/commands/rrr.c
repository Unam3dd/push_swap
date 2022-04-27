/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:59:59 by stales            #+#    #+#             */
/*   Updated: 2022/04/27 02:16:25 by sam              ###   ########.fr       */
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
	ft_putstr_fd("rrr\n", 1);
}
