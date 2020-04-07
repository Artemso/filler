/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 15:19:11 by asolopov          #+#    #+#             */
/*   Updated: 2020/04/06 08:10:23 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/visu.h"

int	key_hook_press(int keycode, t_prop *xt)
{
	if (keycode == 53)
		exit(1);
	else if (keycode == 124)
		manual(xt);
	else if (keycode == 49 && VISU->pause == 1)
		VISU->pause = 0;
	else if (keycode == 49 && VISU->pause == 0)
		VISU->pause = 1;
	else if (keycode == 4 && VISU->disp_heat == 0)
		VISU->disp_heat = 1;
	else if (keycode == 4 && VISU->disp_heat == 1)
		VISU->disp_heat = 0;
	return (0);
}