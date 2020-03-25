/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 13:07:39 by asolopov          #+#    #+#             */
/*   Updated: 2020/03/25 10:38:52 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/filler.h"

static void	init_visu(t_prop *xt)
{
	if (!(xt->visu = (t_visu *)malloc(sizeof(t_visu))))
		err_exit("xt->t_visu unallocated");
	MLX_PTR = mlx_init();
	MLX_WIN = mlx_new_window(MLX_PTR, W_WID, W_HEI, "FILLEUR");
}

int 		main(void)
{
	t_prop *xt;

	if (!(xt = (t_prop *)malloc(sizeof(t_prop))))
		err_exit("t_prop xt unallocated");
	get_map(xt);
}