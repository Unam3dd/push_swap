/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 18:30:04 by stales            #+#    #+#             */
/*   Updated: 2022/04/27 02:14:36 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ra(t_pswap *p)
{
	if (!p)
		return ;
	algo_rotate(&p->a);
	ft_putstr_fd("ra\n", 1);
}
