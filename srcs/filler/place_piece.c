/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 17:47:30 by asolopov          #+#    #+#             */
/*   Updated: 2020/04/01 16:18:03 by asolopov         ###   ########.fr       */
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
	//print_heat_data(xt);
}

static int	get_score(t_prop *xt, int off_x, int off_y)
{
	int ret_sum;
	int x;
	int y;

	x = 0;
	ret_sum = 0;
	while (x < xt->pc_x)
	{
		y = 0;
		while (y < xt->pc_y)
		{
			if (xt->piece[x][y] == 1)
				ret_sum += xt->heat[x + off_x][y + off_y];
			y += 1;
		}
		x += 1;
	}
	//printf("SUM at X:%d Y:%d		==%d\n", off_x, off_y, ret_sum);
	return (ret_sum);
}

static int	get_overlap(t_prop *xt, int off_x, int off_y)
{
	int	overlap;
	int	x;
	int	y;

	overlap = 0;
	x = 0;
	while (x < xt->pc_x)
	{
		y = 0;
		while (y < xt->pc_y)
		{
			if (xt->piece[x][y] == 1)
			{
				if (xt->heat[x + off_x][y + off_y] == 0)
					return (0);
				if (xt->heat[x + off_x][y + off_y] == -1)
					overlap += 1;
			}
			y += 1;
		}
		x += 1;
	}
	if (overlap == 1)
		return (1);
	else
		return (0);
}

void		get_place_coords(t_prop *xt)
{
	int x;
	int y;
	int score;
	
	x = 0;
	y = 0;
	xt->best = xt->brd_x * xt->brd_y;
	while (x <= xt->brd_x - xt->pc_x)
	{
		y = 0;
		while (y <= xt->brd_y - xt->pc_y)
		{
			if (get_overlap(xt, x, y))
			{
				score = get_score(xt, x, y);
				if (score < xt->best)
				{
					xt->best = score;
					xt->place_x = x;
					xt->place_y = y;
				}
			}
			y += 1;
		}
		x += 1;
	}
	// place_piece(xt, xt->place_x, xt->place_y);
	ft_putnbr(xt->place_x);
	ft_putchar(' ');
	ft_putnbr(xt->place_y);
	ft_putchar('\n');
	xt->map = 0;
	xt->piece = 0;
	xt->heat = 0;
}