/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_imgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 16:06:31 by asolopov          #+#    #+#             */
/*   Updated: 2020/04/03 17:45:43 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/visu.h"

void	display_back(t_prop *xt)
{
	mlx_put_image_to_window(MLX_PTR, MLX_WIN, VISU->back, 0, 0);
}

void	display_map(t_prop *xt)
{
	int stpx;
	int stpy;
	int cntx;
	int cnty;
	
	stpx = 0;
	cntx = 0;
	while (cntx < xt->brd_x)
	{
		cnty = 0;
		stpx = 0;
		while (cnty < xt->brd_y)
		{
			if (xt->map[cntx][cnty] == 'O')
				mlx_put_image_to_window(MLX_WIN, MLX_WIN, VISU->mycl, stpx, stpy);
			else if (xt->map[cntx][cnty] == 'X')
				mlx_put_image_to_window(MLX_WIN, MLX_WIN, VISU->encl, stpx, stpy);
			else if (xt->map[cntx][cnty] == 'x')
				mlx_put_image_to_window(MLX_WIN, MLX_WIN, VISU->encl, stpx, stpy);
			else
				mlx_put_image_to_window(MLX_WIN, MLX_WIN, VISU->emptcl, stpx, stpy);
			stpx += 25;
			cnty += 1;
		}
		stpy += 25;
		cntx += 1;
	}
}

void	display_all(t_prop *xt)
{
	//display_back(xt);
	display_map(xt);
	mlx_hook(MLX_WIN, 2, 0, key_hook_press, xt);
	mlx_loop(MLX_PTR);
}