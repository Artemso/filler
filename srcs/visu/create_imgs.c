/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_imgs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 16:06:33 by asolopov          #+#    #+#             */
/*   Updated: 2020/04/03 16:29:02 by asolopov         ###   ########.fr       */
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

void	create_back(t_prop *xt)
{
	int		bpp;
	int		size;
	int		endian;

	VISU->back = mlx_new_image(MLX_PTR, W_WID, W_HEI);
	VISU->back_dat = (int *)mlx_get_data_addr(VISU->back, &bpp, &size, &endian);
	fill_rctngl(VISU->back_dat, W_WID, W_HEI, 0xffffff);	
}

void	create_my_cell(t_prop *xt)
{
	int		bpp;
	int		size;
	int		endian;

	VISU->mycl = mlx_new_image(MLX_PTR, 20, 20);
	VISU->mycl_dat = (int *)mlx_get_data_addr(VISU->mycl, &bpp, &size, &endian);
	fill_rctngl(VISU->mycl_dat, 20, 20, 0xff00ff);	
}

void	create_empty_cell(t_prop *xt)
{
	int		bpp;
	int		size;
	int		endian;

	VISU->emptcl = mlx_new_image(MLX_PTR, 20, 20);
	VISU->emptcl_dat = (int *)mlx_get_data_addr(VISU->emptcl, &bpp, &size, &endian);
	fill_rctngl(VISU->emptcl_dat, 20, 20, 0x00ff00);	
}

void	create_enemy_cell(t_prop *xt)
{
	int		bpp;
	int		size;
	int		endian;

	VISU->encl = mlx_new_image(MLX_PTR, 20, 20);
	VISU->encl_dat = (int *)mlx_get_data_addr(VISU->encl, &bpp, &size, &endian);
	fill_rctngl(VISU->encl_dat, 20, 20, 0x0000ff);	
}

void	create_images(t_prop *xt)
{
	create_back(xt);
	create_my_cell(xt);
	create_empty_cell(xt);
	create_enemy_cell(xt);
}