/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 10:21:58 by asolopov          #+#    #+#             */
/*   Updated: 2020/03/31 14:45:46 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/filler.h"

static void	print_input_data(t_prop *xt)
{
	int cntx;
	int	cnty;

	cntx = 0;
	printf("CHARS:		P1 chars: %c | P2 chars: %c\n", xt->me, xt->enemy);
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

static int	is_map(char *line)
{
	int cnt;

	cnt = 0;
	if (line[3] == ' ')
	{
		while (cnt < 3)
		{
			if (!ft_isdigit(line[cnt]))
				return (0);
			cnt += 1;
		}
		return (1);
	}
	return (0);
}

static void	append_to_map(t_prop *xt, char *line)
{
	if (!(xt->map))
	{
		xt->map = (char **)malloc(xt->brd_x * sizeof(char *));
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

void		get_map(t_prop *xt)
{
	char *line;
	char **temp;
	int cnt;

	cnt = 0;
	while(get_next_line(0, &line) > 0)
	{
		if (ft_strstr(line, "$$$ exec p1"))
		{
			if (ft_strstr(line, NAME))
			{
				xt->me = 'O';
				xt->enemy = 'X';
			}
			else
			{
				xt->me = 'X';
				xt->enemy = 'O';
			}
		}
		else if (ft_strstr(line, "Plateau"))
		{
			temp = ft_strsplit(line, ' ');
			xt->brd_x = ft_atoi(temp[1]);
			xt->brd_y = ft_atoi(temp[2]);
			free(temp); // mod it later pls
		}
		else if (is_map(line))
			append_to_map(xt, line);
		else if (ft_strstr(line, "Piece"))
		{
			temp = ft_strsplit(line, ' ');
			xt->pc_x = ft_atoi(temp[1]);
			xt->pc_y = ft_atoi(temp[2]);
			free(temp); // mod it later pls
		}
		else if (ft_strlen(line) == xt->pc_y)
		{
			append_to_piece(xt, line);
			cnt += 1;	
			if (cnt == xt->pc_y)
				break ;	
		}
	}
}