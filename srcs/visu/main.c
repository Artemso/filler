/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 10:37:54 by asolopov          #+#    #+#             */
/*   Updated: 2020/04/05 14:59:03 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/visu.h"

static void	init_visu(t_prop *xt)
{
	if (!(xt->visu = (t_visu *)malloc(sizeof(t_visu))))
		err_exit("xt->t_visu unallocated");
	ft_bzero(VISU, sizeof(t_visu));
	MLX_PTR = mlx_init();
	MLX_WIN = mlx_new_window(MLX_PTR, W_WID, W_HEI, "FILLEUR");
}

int 		main(void)
{
	t_prop *xt;

	if (!(xt = (t_prop *)malloc(sizeof(t_prop))))
		err_exit("t_prop xt unallocated");
	ft_bzero(xt, sizeof(t_prop));
	init_visu(xt);
	get_map(xt);
	return (0);
}