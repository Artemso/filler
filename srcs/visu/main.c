/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 10:37:54 by asolopov          #+#    #+#             */
/*   Updated: 2020/03/29 13:33:53 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/visu.h"

static void	init_visu(t_prop *xt)
{
	if (!(xt->visu = (t_visu *)malloc(sizeof(t_visu))))
		err_exit("xt->t_visu unallocated");
	MLX_PTR = mlx_init();
	MLX_WIN = mlx_new_window(MLX_PTR, W_WID, W_HEI, "FILLEUR");
}

int 		main(void)
{
	printf("kek");
}