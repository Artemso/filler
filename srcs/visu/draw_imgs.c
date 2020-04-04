/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_imgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 16:06:31 by asolopov          #+#    #+#             */
/*   Updated: 2020/04/04 19:37:05 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/visu.h"

void	display_back(t_prop *xt)
{
	mlx_put_image_to_window(MLX_PTR, MLX_WIN, VISU->back, 0, 0);
	mlx_put_image_to_window(MLX_PTR, MLX_WIN, VISU->mapback, W_WID / 125, W_WID / 125);
	mlx_string_put(MLX_PTR, MLX_WIN, W_WID / 27, W_HEI * 0.67, 0x000000, "- My color");
	mlx_string_put(MLX_PTR, MLX_WIN, W_WID / 27, W_HEI * 0.72, 0x000000, "- Enemy color");
	mlx_put_image_to_window(MLX_WIN, MLX_WIN, VISU->mycl, W_WID / 125, W_HEI * 0.67);
	mlx_put_image_to_window(MLX_WIN, MLX_WIN, VISU->encl, W_WID / 125, W_HEI * 0.72);	
}

int		ft_islower(int c)
{
	if (!c)
		return (0);
	if (c >= 97 && c <= 122)
		return (1);
	else
		return (0);
}

void	display_map(t_prop *xt)
{
	int stpx;
	int stpy;
	int cntx;
	int cnty;
	
	stpy = W_WID / 75;
	cntx = 0;
	while (cntx < xt->brd_x)
	{
		cnty = 0;
		stpx = W_WID / 75;
		while (cnty < xt->brd_y)
		{
			if (ft_strchr(xt->me, xt->map[cntx][cnty]))
			{
				if (ft_islower(xt->map[cntx][cnty]))
					mlx_put_image_to_window(MLX_WIN, MLX_WIN, VISU->mynewcl, stpx, stpy);
				else
					mlx_put_image_to_window(MLX_WIN, MLX_WIN, VISU->mycl, stpx, stpy);
				xt->score_me += 1;
			}
			else if (ft_strchr(xt->enemy, xt->map[cntx][cnty]))
			{
				if (ft_islower(xt->map[cntx][cnty]))
					mlx_put_image_to_window(MLX_WIN, MLX_WIN, VISU->enewcl, stpx, stpy);
				else
					mlx_put_image_to_window(MLX_WIN, MLX_WIN, VISU->encl, stpx, stpy);
				xt->score_enemy += 1;
			}
			else
				mlx_put_image_to_window(MLX_WIN, MLX_WIN, VISU->emptcl, stpx, stpy);
			stpx += (W_WID / xt->brd_y * 0.65);
			cnty += 1;
		}
		stpy += (W_HEI / xt->brd_x * 0.65);
		cntx += 1;
	}
}

void	display_score(t_prop *xt)
{
	char *me_num;
	char *enem_num;
	char *score_me;
	char *score_enem;

	me_num = ft_itoa(xt->score_me);
	enem_num = ft_itoa(xt->score_enemy);
	score_me = ft_strjoin("My score: ", me_num);
	score_enem = ft_strjoin("Enemy score: ", enem_num);
	mlx_string_put(MLX_PTR, MLX_WIN, W_WID / 5, W_HEI * 0.67, 0x000000, score_me);
	mlx_string_put(MLX_PTR, MLX_WIN, W_WID / 5, W_HEI * 0.72, 0x000000, score_enem);
	xt->score_me = 0;
	xt->score_enemy = 0;
}

void	display_finish(t_prop *xt)
{
	display_back(xt);
	//display_map(xt);
	display_score(xt);
	mlx_string_put(MLX_PTR, MLX_WIN, W_WID / 5, W_HEI / 2, 0xff0000, "Artem won");
	mlx_loop(MLX_PTR);
}

void	manual(t_prop *xt)
{
	if (VISU->game_finished == 1)
		display_finish(xt);
	if (VISU->pause == 1)
	{
		del_array(xt->map);
		xt->map = 0;
		mlx_clear_window(MLX_WIN, MLX_WIN);
		get_input(xt);
	}
	else
		display_finish(xt);
}

int		onupdate(t_prop *xt)
{
	if (VISU->game_finished == 1)
		display_finish(xt);
	if (VISU->pause == 0)
	{
		del_array(xt->map);
		xt->map = 0;
		mlx_clear_window(MLX_WIN, MLX_WIN);
		get_input(xt);
	}
}

void	display_all(t_prop *xt)
{
	display_back(xt);
	display_map(xt);
	display_score(xt);
	mlx_loop_hook(MLX_PTR, &onupdate, xt);
	mlx_hook(MLX_WIN, 2, 0, key_hook_press, xt);
	mlx_loop(MLX_PTR);
}