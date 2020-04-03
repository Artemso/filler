/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 10:32:34 by asolopov          #+#    #+#             */
/*   Updated: 2020/04/03 17:12:50 by asolopov         ###   ########.fr       */
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
# define C_HOT	12414214 //color: hot
# define C_WARM	41241241 //color: warm
# define C_COOL	12784192 //color: cool
# define NAME	"asolopov.filler"
# define VISU	xt->visu

typedef struct	s_visu
{
	void	*mlx_ptr;
	void	*win_ptr;

	void	*back;
	int		*back_dat;

	void	*mycl;
	int		*mycl_dat;

	void	*encl;
	int		*encl_dat;

	void	*emptcl;
	int		*emptcl_dat;
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