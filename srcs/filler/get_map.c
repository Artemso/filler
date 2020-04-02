/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 10:21:58 by asolopov          #+#    #+#             */
/*   Updated: 2020/04/02 10:47:59 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/filler.h"

static void	print_input_data(t_prop *xt)
{
	int cntx;
	int	cnty;

	cntx = 0;
	printf("CHARS:		P1 chars: %s | P2 chars: %s\n", xt->me, xt->enemy);
	printf("BOARD SIZE:	x: %d | y: %d\n", xt->brd_x, xt->brd_y);
	printf("MAP STRINGS:\n");
	while (xt->map[cntx])
	{
		if (xt->map[cntx])
			printf("%s\n", xt->map[cntx]);
		cntx += 1;
	}
	printf("\n");
	printf("PIECE SIZE:	x: %d | y: %d\n", xt->pc_x, xt->pc_y);
	printf("PIECE INT:\n");
	cntx = 0;
	while (cntx < xt->pc_x)
	{
		cnty = 0;
		while (cnty < xt->pc_y)
		{
			printf("%d ", xt->piece[cntx][cnty]);
			cnty += 1;
		}
		printf("\n");
		cntx += 1;
	}
	printf("\n");
}

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
		xt->map[xt->brd_x + 1] = 0;
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

void		get_map(t_prop *xt)
{
	char *line;
	char **temp;
	int cnt;

	cnt = 0;
	while(get_next_line(0, &line) > 0)
	{
		if (ft_strnstr(line, "$$$ exec", 8))
			fetch_player_chars(xt, line);
		else if (ft_strnstr(line, "Plateau", 7))
			fetch_plateau(xt, line);
		else if (is_map(line))
			append_to_map(xt, line);
		else if (ft_strnstr(line, "Piece", 5))
			fetch_piece(xt, line);
		else if (is_piece(xt, line))
		{
			append_to_piece(xt, line);
			cnt += 1;
			if (cnt == xt->pc_x)
			{
				cut_piece(xt);
				get_heat(xt);
				get_place_coords(xt);
				cnt = 0;
			}
		}
	}
}