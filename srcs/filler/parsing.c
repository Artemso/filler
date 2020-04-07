/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 11:08:09 by asolopov          #+#    #+#             */
/*   Updated: 2020/04/06 07:31:11 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/filler.h"

void	delete_array(char **array)
{
	int cnt;

	cnt = 0;
	while (array[cnt])
	{
		free(array[cnt]);
		cnt += 1;
	}
}

void	fetch_player_chars(t_prop *xt, char *line)
{
	if (ft_strstr(line, "$$$ exec p1"))
	{
		if (ft_strstr(line, NAME))
		{
			xt->me = "Oo";
			xt->enemy = "Xx";
		}
	}
	else if (ft_strstr(line, "$$$ exec p2"))
	{
		if (ft_strstr(line, NAME))
		{
			xt->me = "Xx";
			xt->enemy = "Oo";
		}
	}
}

void		fetch_plateau(t_prop *xt, char *line)
{
	char **temp;
	
	temp = ft_strsplit(line, ' ');
	xt->brd_x = ft_atoi(temp[1]);
	xt->brd_y = ft_atoi(temp[2]);
	delete_array(temp);
}

int		fetch_piece(t_prop *xt, char *line)
{
	char **temp;
	
	temp = ft_strsplit(line, ' ');
	xt->pc_x = ft_atoi(temp[1]);
	xt->pc_y = ft_atoi(temp[2]);
	delete_array(temp);
	return (1);
}