/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 15:19:11 by asolopov          #+#    #+#             */
/*   Updated: 2020/04/03 17:41:12 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/visu.h"

int	key_hook_press(int keycode, t_prop *xt)
{
	if (keycode == 53)
		exit(1);
	if (keycode == 123)
	{
		del_array(xt->map);
		xt->map = 0;
		mlx_clear_window(MLX_WIN, MLX_WIN);
		get_input(xt);
	}
	return (0);
}