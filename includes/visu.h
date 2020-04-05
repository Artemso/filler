/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/05 14:43:32 by asolopov          #+#    #+#             */
/*   Updated: 2020/04/05 16:30:55 by asolopov         ###   ########.fr       */
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
# define C_MAPBACK	0x000000
# define C_ME		0xFFFFFF
# define C_ENEMY	0x303030
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

	void	*last;
	int		*last_dat;

	int		ceil_size;

	int		imgs_created;
	int		pause;
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