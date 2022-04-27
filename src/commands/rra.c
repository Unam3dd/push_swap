/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:59:01 by stales            #+#    #+#             */
/*   Updated: 2022/04/27 02:15:43 by sam              ###   ########.fr       */
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
