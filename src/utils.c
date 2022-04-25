/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42.angouleme.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 13:15:24 by stales            #+#    #+#             */
/*   Updated: 2022/04/25 11:37:14 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int ft_check_charset(char *str, char *set)
{
    while (*str)
    {
        if (ft_strchr(set, *str))
            return (1);
        str++;
    }
    return (0);
}
