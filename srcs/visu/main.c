/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 10:37:54 by asolopov          #+#    #+#             */
/*   Updated: 2020/03/31 14:31:24 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/visu.h"

void	err_exit(char *msg)
{
	perror(msg);
	exit(0);
}

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