/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 17:47:30 by asolopov          #+#    #+#             */
/*   Updated: 2020/03/30 18:13:46 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/filler.h"

static void	print_heat_data(t_prop *xt)
{
	int cntx;
	int	cnty;

	printf("PIECE PLACED MAP:\n");
	cntx = 0;
	while (cntx < xt->brd_x)
	{
		cnty = 0;
		while (cnty < xt->brd_y)
		{
			if (xt->heat[cntx][cnty] >= 10)
				printf(" %d", xt->heat[cntx][cnty]);
			else if (xt->heat[cntx][cnty] < 10 && xt->heat[cntx][cnty] >= 0)
				printf("  %d", xt->heat[cntx][cnty]);
			else
				printf(" %d", xt->heat[cntx][cnty]);
			cnty += 1;
		}
		printf("\n");
		cntx += 1;
	}
}

void	place_piece(t_prop *xt, int offx, int offy)
{
	int x;
	int y;

	x = 0;
	while (x < xt->pc_x)
	{
		y = 0;
		while (y < xt->pc_y)
		{
			if (xt->piece[x][y] == 1)
				xt->heat[x + offx][y + offy] = 99;
			else if (xt->piece[x][y] == 0)
				xt->heat[x + offx][y + offy] = -2;
			y += 1;
		}
		x += 1;
	}
	print_heat_data(xt);
}

void	get_place_coords(t_prop *xt)
{
	int x;
	int y;
	
	x = 0;
	while (x < xt->brd_x)
	{
		y = 0;
		while (y < xt->brd_y)
		{
			score = get_score(xt, x, y);
			if (score < xt->best && get_overlap(xt, x, y))
			{
				xt->place_x = x;
				xt->place_y = y;
			}
			y += 1;
		}
		x += 1;
	}
}