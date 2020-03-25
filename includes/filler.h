/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 13:07:36 by asolopov          #+#    #+#             */
/*   Updated: 2020/03/25 10:24:24 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libs/libft/libft.h"
# include "../libs/libmlx/mlx.h"
# include <stdio.h>

# define W_WID	1080
# define W_HEI	720
# define MLX_PTR xt->visu->mlx_ptr
# define MLX_WIN xt->visu->win_ptr
# define C_HOT	12414214 //color: hot
# define C_WARM	41241241 //color: warm
# define C_COOL	12784192 //color: cool

typedef struct	s_visu
{
	void	*mlx_ptr;
	void	*win_ptr;
	
	void	*img_cell;
	int		*cell_data;
}				t_visu;

typedef struct	s_prop
{
	t_visu		*visu;

	
}				t_prop;




void			err_exit(char *msg);

#endif