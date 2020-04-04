/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 10:32:34 by asolopov          #+#    #+#             */
/*   Updated: 2020/04/04 19:28:21 by asolopov         ###   ########.fr       */
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
# define C_FREEZING	0x155263
# define C_COOL		0xffc93c
# define C_WARMER	0xff9a3c
# define C_HOT		0xff6f3c

# define C_BACK		0x505050
# define C_MAPBACK	0x909090
# define C_ME		0xFFFFFF
# define C_ENEMY	0x000000
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

	void	*mapback;
	int		*mapback_dat;

	void	*mycl;
	int		*mycl_dat;

	void	*mynewcl;
	int		*mynewcl_dat;

	void	*encl;
	int		*encl_dat;

	void	*enewcl;
	int		*enewcl_dat;

	void	*emptcl;
	int		*emptcl_dat;

	int		pause;
	int		got_images;
	int			game_finished;
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
	int			pisya;

	int			score_me;
	int			score_enemy;
	
	t_visu *visu;
}				t_prop;

void			get_input(t_prop *xt);
int				fetch_piece(t_prop *xt, char *line);
void			fetch_plateau(t_prop *xt, char *line);
void			fetch_player_chars(t_prop *xt, char *line);


void			get_heat(t_prop *xt);
void			err_exit(char *msg);

void	create_images(t_prop *xt);
void			fill_rctngl(int *img_data, int img_w, int img_h, int color);

void			draw_window(t_prop *xt);
int				key_hook_press(int keycode, t_prop *xt);

#endif