/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_imgs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/05 14:48:25 by asolopov          #+#    #+#             */
/*   Updated: 2020/04/05 16:51:28 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/visu.h"

void	manual(t_prop *xt)
{
	if (VISU->pause == 1)
	{
		del_array(xt->map);
		xt->map = 0;
		mlx_clear_window(MLX_PTR, MLX_WIN);
		get_map(xt);
	}
}

int		onupdate(t_prop *xt)
{
	if (VISU->pause == 0)
	{
		del_array(xt->map);
		xt->map = 0;
		mlx_clear_window(MLX_PTR, MLX_WIN);
		get_map(xt);
	}
	return (0);
}

void	display_bg(t_prop *xt)
{
	mlx_put_image_to_window(MLX_PTR, MLX_WIN, VISU->back, 0, 0);
	mlx_put_image_to_window(MLX_PTR, MLX_WIN, VISU->map, 0, 0);
}

void	display_all(t_prop *xt)
{
	display_bg(xt);
	if (xt->map)
	{
		mlx_loop_hook(MLX_PTR, &onupdate, xt);
		mlx_hook(MLX_WIN, 2, 0, key_hook_press, xt);
	}
	mlx_loop(MLX_PTR);
}
