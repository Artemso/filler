/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 15:19:11 by asolopov          #+#    #+#             */
/*   Updated: 2020/04/04 15:08:00 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/visu.h"

int	key_hook_press(int keycode, t_prop *xt)
{
	if (keycode == 53)
		exit(1);
	else if (keycode == 123)
		manual(xt);
	else if (keycode == 49 && VISU->pause == 1)
		VISU->pause = 0;
	else if (keycode == 49 && VISU->pause == 0)
		VISU->pause = 1;
	return (0);
}