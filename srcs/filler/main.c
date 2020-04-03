/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 13:07:39 by asolopov          #+#    #+#             */
/*   Updated: 2020/04/03 17:00:59 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/filler.h"

int 		main(void)
{
	t_prop *xt;

	if (!(xt = (t_prop *)malloc(sizeof(t_prop))))
		err_exit("t_prop xt unallocated");
	ft_bzero(xt, sizeof(t_prop));
	get_map(xt);
}