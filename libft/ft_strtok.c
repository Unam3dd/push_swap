/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42.angouleme.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 20:02:53 by stales            #+#    #+#             */
/*   Updated: 2022/04/20 20:33:15 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtok(char *str, char *token)
{
	static char	*p;

	if (str)
		p = str;
	if (!p || !token)
		return (NULL);
	str = p;
	if (!*str)
		return (NULL);
	p += ft_strcspn(str, token);
	if (*p)
		*p++ = 0;
	return (str);
}
