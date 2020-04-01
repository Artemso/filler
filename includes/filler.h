/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 13:07:36 by asolopov          #+#    #+#             */
/*   Updated: 2020/04/01 19:50:17 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libs/libft/libft.h"
# include <stdio.h>

# define NAME	"asolopov.filler"
# define HEAT	xt->heat
# define PIECE	xt->piece

typedef struct	s_prop
{
	char		*me;
	char		*enemy;
	
	char		**map;
	int			brd_x;
	int			brd_y;
	int			mapcnt;

	int			**piece;
	int			pc_x;
	int			pc_y;
	int			pc_cnt;
	int			overlap;
	int			off_x;
	int			off_y;

	int			best;
	int			place_x;
	int			place_y;

	int			**heat;
}				t_prop;


void			get_map(t_prop *xt);
void			fetch_player_chars(t_prop *xt, char *line);
void			fetch_plateau(t_prop *xt, char *line);
int				fetch_piece(t_prop *xt, char *line);

void			get_heat(t_prop *xt);
void			place_piece(t_prop *xt, int offx, int offy);
void			get_place_coords(t_prop *xt);

void			err_exit(char *msg);

#endif