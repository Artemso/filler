/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:24:28 by asolopov          #+#    #+#             */
/*   Updated: 2019/10/19 16:23:48 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*c;
	size_t	x;

	c = (char *)s;
	x = 0;
	while (x < n)
	{
		c[x] = '\0';
		x++;
	}
}
