/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_imgs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 16:06:33 by asolopov          #+#    #+#             */
/*   Updated: 2020/04/04 16:26:50 by asolopov         ###   ########.fr       */
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
	fill_rctngl(VISU->back_dat, W_WID, W_HEI, C_BACK);	
}

void	create_map_back(t_prop *xt)
{
	int		bpp;
	int		size;
	int		endian;
	int		wid;
	int 	heigh;

	wid = W_WID * 0.64;
	heigh = W_HEI * 0.65;
	VISU->mapback = mlx_new_image(MLX_PTR, wid, heigh);
	VISU->mapback_dat = (int *)mlx_get_data_addr(VISU->mapback, &bpp, &size, &endian);
	fill_rctngl(VISU->mapback_dat, wid, heigh, C_MAPBACK);	
}

void	create_my_cell(t_prop *xt)
{
	int		bpp;
	int		size;
	int		endian;
	int		wid;
	int 	heigh;

	wid = W_WID / xt->brd_y * 0.6;
	heigh = W_HEI / xt->brd_x * 0.6;
	VISU->mycl = mlx_new_image(MLX_PTR, wid, heigh);
	VISU->mycl_dat = (int *)mlx_get_data_addr(VISU->mycl, &bpp, &size, &endian);
	fill_rctngl(VISU->mycl_dat, wid, heigh, C_ME);	
}

void	create_my_new_cell(t_prop *xt)
{
	int		bpp;
	int		size;
	int		endian;
	int		wid;
	int 	heigh;

	wid = W_WID / xt->brd_y * 0.6;
	heigh = W_HEI / xt->brd_x * 0.6;
	VISU->mynewcl = mlx_new_image(MLX_PTR, wid, heigh);
	VISU->mynewcl_dat = (int *)mlx_get_data_addr(VISU->mynewcl, &bpp, &size, &endian);
	fill_rctngl(VISU->mynewcl_dat, wid, heigh, C_MENEW);	
}

void	create_empty_cell(t_prop *xt)
{
	int		bpp;
	int		size;
	int		endian;
	int		wid;
	int 	heigh;

	wid = W_WID / xt->brd_y * 0.6;
	heigh = W_HEI / xt->brd_x * 0.6;
	VISU->emptcl = mlx_new_image(MLX_PTR, wid, heigh);
	VISU->emptcl_dat = (int *)mlx_get_data_addr(VISU->emptcl, &bpp, &size, &endian);
	fill_rctngl(VISU->emptcl_dat, wid, heigh, C_FREEZING);	
}

void	create_enemy_cell(t_prop *xt)
{
	int		bpp;
	int		size;
	int		endian;
	int		wid;
	int 	heigh;

	wid = W_WID / xt->brd_y * 0.6;
	heigh = W_HEI / xt->brd_x * 0.6;
	VISU->encl = mlx_new_image(MLX_PTR, wid, heigh);
	VISU->encl_dat = (int *)mlx_get_data_addr(VISU->encl, &bpp, &size, &endian);
	fill_rctngl(VISU->encl_dat, wid, heigh, C_ENEMY);	
}

void	create_enemy_new_cell(t_prop *xt)
{
	int		bpp;
	int		size;
	int		endian;
	int		wid;
	int 	heigh;

	wid = W_WID / xt->brd_y * 0.6;
	heigh = W_HEI / xt->brd_x * 0.6;
	VISU->enewcl = mlx_new_image(MLX_PTR, wid, heigh);
	VISU->enewcl_dat = (int *)mlx_get_data_addr(VISU->enewcl, &bpp, &size, &endian);
	fill_rctngl(VISU->enewcl_dat, wid, heigh, C_ENEMYNEW);	
}

void	create_images(t_prop *xt)
{
	create_back(xt);
	create_map_back(xt);
	create_my_cell(xt);
	create_my_new_cell(xt);
	create_empty_cell(xt);
	create_enemy_cell(xt);
	create_enemy_new_cell(xt);
	VISU->got_images = 1;
}