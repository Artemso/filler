/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 11:30:46 by asolopov          #+#    #+#             */
/*   Updated: 2020/04/03 15:20:39 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/visu.h"

void	fill_rctngl(int *img_data, int img_w, int img_h, int color)
{
	int count_h;
	int count_w;

	count_h = -1;
	while (++count_h < img_h)
	{
		count_w = -1;
		while (++count_w < img_w)
			img_data[count_h * img_w + count_w] = color;
	}
}

void	draw_map(t_prop *xt)
{
	int		bpp;
	int		size;
	int		endian;

	VISU->back = mlx_new_image(MLX_PTR, W_WID, W_HEI);
	VISU->back_dat = (int *)mlx_get_data_addr(VISU->back, &bpp, &size, &endian);
	fill_rctngl(VISU->back_dat, W_WID, W_HEI, 0xffffff);
	mlx_put_image_to_window(MLX_PTR, MLX_WIN, VISU->back, 0, 0);
	mlx_hook(MLX_WIN, 2, 0, key_hook_press, xt);
	mlx_loop(MLX_PTR);
}