/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 10:21:58 by asolopov          #+#    #+#             */
/*   Updated: 2020/03/30 12:39:45 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/filler.h"

static void	print_input_data(t_prop *xt)
{
	int cnt;

	cnt = 0;
	printf("CHARS:		P1 chars: %c | P2 chars: %c\n", xt->me, xt->enemy);
	printf("BOARD SIZE:	x: %d | y: %d\n", xt->brd_x, xt->brd_y);
	printf("MAP STRINGS:\n");
	while (xt->map[cnt])
	{
		if (xt->map[cnt])
			printf("%s\n", xt->map[cnt]);
		cnt += 1;
	}
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

void		get_map(t_prop *xt)
{
	char *line;
	char **temp;
	
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
		}
		else if (is_map(line))
			append_to_map(xt, line);
	}
	print_input_data(xt);
}