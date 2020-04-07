/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_imgs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/05 14:48:25 by asolopov          #+#    #+#             */
/*   Updated: 2020/04/06 13:00:08 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/visu.h"

void	manual(t_prop *xt)
{
	if (VISU->pause == 1 && xt->map)
	{
		del_array(xt->map);
		xt->map = 0;
		mlx_clear_window(MLX_PTR, MLX_WIN);
		get_map(xt);
	}
}

int		onupdate(t_prop *xt)
{
	if (VISU->pause == 0 && xt->map)
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
	if (VISU->disp_heat == 0)
		mlx_put_image_to_window(MLX_PTR, MLX_WIN, VISU->map, W_WID / 100, W_HEI / 100);
	else if (VISU->disp_heat == 1)
		mlx_put_image_to_window(MLX_PTR, MLX_WIN, VISU->heat, W_WID / 100, W_HEI / 100);
	mlx_string_put(MLX_PTR, MLX_WIN, W_WID * 0.67, 20, C_ME, "Controls:");
	mlx_string_put(MLX_PTR, MLX_WIN, W_WID * 0.67, 45, C_ENEMY, "SPACE: play/pause");
	mlx_string_put(MLX_PTR, MLX_WIN, W_WID * 0.67, 70, C_ENEMY, "ARROW RIGHT: next step");
	mlx_string_put(MLX_PTR, MLX_WIN, W_WID * 0.67, 95, C_ENEMY, "H: toggle heat map");

	if (xt->me_score != 0)
	{
		char *temp = ft_itoa(xt->me_score);
		temp = ft_strjoin("My score: ", temp);
		mlx_string_put(MLX_PTR, MLX_WIN, W_WID * 0.67, 110, C_ME, temp);
		char *temp2 = ft_itoa(xt->enemy_score);
		temp2 = ft_strjoin("Enemy score: ", temp2);
		mlx_string_put(MLX_PTR, MLX_WIN, W_WID * 0.67, 135, C_ENEMY, temp2);
	}
}

void	display_all(t_prop *xt)
{
	display_bg(xt);
	mlx_loop_hook(MLX_PTR, &onupdate, xt);
	mlx_hook(MLX_WIN, 2, 0, key_hook_press, xt);
	mlx_loop(MLX_PTR);
}
