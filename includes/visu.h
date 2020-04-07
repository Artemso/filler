/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/05 14:43:32 by asolopov          #+#    #+#             */
/*   Updated: 2020/04/06 13:23:32 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_H
# define VISU_H

# include "../libs/libmlx/mlx.h"
# include "../libs/libft/libft.h"
# include <stdio.h>

# define W_WID	1080
# define W_HEI	720
# define MLX_PTR xt->visu->mlx_ptr
# define MLX_WIN xt->visu->win_ptr
# define C_FREEZING	0x1d3e53
# define C_COOL		0x254b62
# define C_WARMER	0x476d7c
# define C_HOT		0x77abb7

# define C_BACK		0x232931
# define C_MAPBACK	0x393e46
# define C_ME		0xfd7014
# define C_ENEMY	0xffffff
# define C_MENEW	0xA1A1A1
# define C_ENEMYNEW	0x545454
# define NAME	"asolopov.filler"
# define VISU	xt->visu

typedef struct	s_visu
{
	void	*mlx_ptr;
	void	*win_ptr;

	void	*back;
	int		*back_dat;

	void	*map;
	int		*map_dat;
	int		map_size;

	void	*heat;
	int		*heat_dat;

	void	*last;
	int		*last_dat;

	int		ceil_size;

	int		imgs_created;
	int		pause;
	int		disp_heat;
}				t_visu;

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

	int			**heat;
	int			heat_max;
	
	int			me_score;
	int			enemy_score;
	t_visu *visu;
}				t_prop;


void	del_array(char **array);
void	get_map(t_prop *xt);
void	fetch_player_chars(t_prop *xt, char *line);
void		fetch_plateau(t_prop *xt, char *line);

void	create_imgs(t_prop *xt);

void	display_all(t_prop *xt);
int				key_hook_press(int keycode, t_prop *xt);
void	manual(t_prop *xt);

void	err_exit(char *msg);

#endif