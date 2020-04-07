/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_heat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 12:28:32 by asolopov          #+#    #+#             */
/*   Updated: 2020/04/06 13:02:55 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/visu.h"

static int	**map_to_heat(t_prop *xt)
{
	int	**new;
	int cntx;
	int	cnty;

	cntx = 0;
	new = (int **)malloc(xt->brd_x * sizeof(int *));
	while (cntx < xt->brd_x)
	{
		new[cntx] = (int*)malloc(xt->brd_y * sizeof(int));
		cnty = 0;
		while (cnty < xt->brd_y)
		{
			if (xt->map[cntx][cnty] == '.')
				new[cntx][cnty] = xt->brd_y + xt->brd_x;
			else if (ft_strchr(xt->enemy, xt->map[cntx][cnty]))
				new[cntx][cnty] = 0;
			else if (ft_strchr(xt->me, xt->map[cntx][cnty]))
				new[cntx][cnty] = -1;
			cnty += 1;
		}
		cntx += 1;
	}
	return (new);
}

static int	get_distance(int x, int y, int i, int j)
{
	int dxi;
	int dyj;
	int dist;

	dxi = x - i;
	dxi = (dxi < 0) ? dxi * -1 : dxi;
	dyj = y - j;
	dyj = (dyj < 0) ? dyj * -1 : dyj;
	dist = dxi + dyj;
	return (dist);
}

static void	fill_heat(t_prop *xt)
{
	int cntx;
	int cnty;
	int cntj;
	int cnti;

	cntx = 0;
	cnti = 0;
	while (cnti < xt->brd_x)
	{
		cntj = 0;
		while (cntj < xt->brd_y)
		{
			if (xt->heat[cnti][cntj] == 0)
			{
				cntx = 0;
				while (cntx < xt->brd_x)
				{
					cnty = 0;
					while (cnty < xt->brd_y)
					{
						if (get_distance(cntx, cnty, cnti, cntj) < xt->heat[cntx][cnty])
							xt->heat[cntx][cnty] = get_distance(cntx, cnty, cnti, cntj);
						cnty += 1;
					}
					cntx += 1;
				}
			}
			cntj += 1;
		}
		cnti += 1;
	}
}

void		get_heat_max(t_prop *xt)
{
	int cntx;
	int cnty;

	cntx = 0;
	while (cntx < xt-> brd_x)
	{
		cnty = 0;
		while (cnty < xt->brd_y)
		{
			if (xt->heat[cntx][cnty] > xt->heat_max)
				xt->heat_max = xt->heat[cntx][cnty];
			cnty += 1;
		}
		cntx += 1;
	}
}

void		get_heat(t_prop *xt)
{
	xt->heat = map_to_heat(xt);
	get_heat_max(xt);
	fill_heat(xt);
}