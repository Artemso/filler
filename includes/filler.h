/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 13:07:36 by asolopov          #+#    #+#             */
/*   Updated: 2020/03/30 12:51:09 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libs/libft/libft.h"
# include <stdio.h>

# define NAME "asolopov.filler"

typedef struct	s_prop
{
	char	me;
	char	enemy;
	
	int		brd_x;
	int		brd_y;
	
	char	**map;
	int		mapcnt;

	int		**heat;
}				t_prop;


void			get_map(t_prop *xt);
void			get_heat(t_prop *xt);

void			err_exit(char *msg);

#endif