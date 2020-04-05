/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 11:18:11 by asolopov          #+#    #+#             */
/*   Updated: 2020/04/05 16:51:05 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/visu.h"

static int	is_piece(t_prop *xt, char *line)
{
	int		cnt;
	char	*allowed;

	cnt = 0;
	allowed = ".*";
	while (line[cnt] != '\0')
	{
		if (ft_strchr(allowed, line[cnt]))
			cnt += 1;
		else
			return 0;
	}
	if (cnt == xt->pc_y)
		return (1);
	else
		return (0);
}

static int	is_map(char *line)
{
	int		cnt;
	char	*allowed;

	cnt = 0;
	allowed = ".XxOo";
	while (line[cnt] != ' ')
	{
		if (ft_isdigit(line[cnt]))
			cnt += 1;
		else
			return (0);
	}
	cnt += 1;
	while (line[cnt] != '\0')
	{
		if (ft_strchr(allowed, line[cnt]))
			cnt += 1;
		else
			return 0;
	}
	return (1);
}

static void	append_to_map(t_prop *xt, char *line)
{
	if (!(xt->map))
	{
		xt->map = (char **)malloc((xt->brd_x + 1) * sizeof(char *));
		xt->map[xt->brd_x] = 0;
		xt->mapcnt = 0;
	}
	xt->map[xt->mapcnt] = ft_strdup(line + 4);
	xt->mapcnt += 1;
}

static void	append_to_piece(t_prop *xt, char *line)
{
	int cnt;

	cnt = 0;
	if (!(xt->piece))
	{
		xt->piece = (int **)malloc(xt->pc_x * sizeof(int *));
		xt->pc_cnt = 0;
	}
	xt->piece[xt->pc_cnt] = (int *)malloc(xt->pc_y * sizeof(int));
	while (line[cnt] != '\0')
	{
		if (line[cnt] == '.')
			xt->piece[xt->pc_cnt][cnt] = 0;
		else if (line[cnt] == '*')
			xt->piece[xt->pc_cnt][cnt] = 1;
		cnt += 1;
	}
	xt->pc_cnt += 1;
}

void	del_array(char **array)
{
	int cnt;
	
	cnt = 0;
	while (array[cnt])
	{
		ft_strdel(&(array[cnt]));
		cnt += 1;
	}
}

void	get_map(t_prop *xt)
{
	int		cnt;
	char	*line;
	int 	plateau;
	
	cnt = 0;
	plateau = 0;
	while(get_next_line(0, &line) > 0)
	{
		if (ft_strnstr(line, "$$$ exec", 8))
			fetch_player_chars(xt, line);
		if (ft_strnstr(line, "Plateau", 7))
		{
			fetch_plateau(xt, line);
			if (VISU->imgs_created == 0)
				create_imgs(xt);
		}
		if (cnt < xt->brd_x && is_map(line))
		{
			append_to_map(xt, line);
			cnt += 1;
		}
		if (cnt > 0 && cnt == xt->brd_x)
		{
			if (VISU->map)
				mlx_destroy_image(MLX_PTR, VISU->map);
			create_map(xt);
			break ;
		}
	}
	display_all(xt);
}