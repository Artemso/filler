/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_imgs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 16:06:33 by asolopov          #+#    #+#             */
/*   Updated: 2020/04/05 16:36:40 by asolopov         ###   ########.fr       */
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

int		get_map_size()
{
	if (W_WID > W_HEI)
		return (W_HEI * 0.9);
	else
		return (W_WID * 0.7);
}

int		get_ceil_size(t_prop *xt)
{
	return (VISU->map_size / xt->brd_x);
}

void	add_cell(int x, int y, t_prop *xt, int color)
{
	int cntx;
	int cnty;
	int	nx;
	int	ny;

	nx = (VISU->map_size / xt->brd_x) * x;
	ny = (VISU->map_size / xt->brd_y) * y;
	cnty = 0;
	while (cnty++ < VISU->ceil_size * 0.4)
	{
		cntx = 0;
		while (cntx++ < VISU->ceil_size * 0.4)
			VISU->map_dat[(ny + cnty) * VISU->map_size + (nx + cntx)] = color;
	}
}

void	create_map(t_prop *xt)
{
	int		bpp;
	int		size;
	int		endian;
	
	int		color;
	int		ceil_size;

	int cntx;
	int cnty;

	VISU->map_size = get_map_size();
	VISU->ceil_size = get_ceil_size(xt);
	VISU->map = mlx_new_image(MLX_PTR, VISU->map_size, VISU->map_size);
	VISU->map_dat = (int *)mlx_get_data_addr(VISU->map, &bpp, &size, &endian);
	fill_rctngl(VISU->map_dat, VISU->map_size, VISU->map_size, 0xdd303030);
	cntx = 0;
	while (cntx < xt->brd_x)
	{
		cnty = 0;
		while (cnty < xt->brd_y)
		{
			if (ft_strchr(xt->me, xt->map[cntx][cnty]))
				add_cell(cntx, cnty, xt, C_ME);
			else if (ft_strchr(xt->enemy, xt->map[cntx][cnty]))
				add_cell(cntx, cnty, xt, C_ENEMY);
			else
				add_cell(cntx, cnty, xt, C_FREEZING);
			cnty += 1;
		}
		cntx += 1;
	}
}

void	create_imgs(t_prop *xt)
{
	create_back(xt);
}