/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 19:22:52 by asolopov          #+#    #+#             */
/*   Updated: 2020/04/06 07:33:13 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/filler.h"

static int	is_empty_x(t_prop *xt, int x)
{
	int cnty;
	
	cnty = 0;
	while (cnty < xt->pc_y)
	{
		if (xt->piece[x][cnty] == 1)
			return 0;
		else
			cnty += 1;
	}
	return (1);
}

static int	is_empty_y(t_prop *xt, int y)
{
	int cntx;
	
	cntx = 0;
	while (cntx < xt->pc_x)
	{
		if (xt->piece[cntx][y] == 1)
			return 0;
		else
			cntx += 1;
	}
	return (1);
}

static void	print_new(int **new, int mlcx, int mlcy)
{
	int cntx;
	int cnty;

	cntx = 0;
	cnty = 0;
	while (cntx < mlcx)
	{
		cnty = 0;
		while (cnty < mlcy)
		{
			printf("%d ", new[cntx][cnty]);
			cnty += 1;
		}
		printf("\n");
		cntx += 1;
	}
}

void		cut_piece(t_prop *xt)
{
	int cntx;
	int cnty;
	int x;
	int y;
	int **new;

	x = 0;
	y = 0;
	cntx = 0;
	cnty = 0;
	while (x < xt->pc_x)
	{
		if (is_empty_x(xt, x))
			x += 1;
		else
			break ;
	}
	while (y < xt->pc_y)
	{
		if (is_empty_y(xt, y))
			y += 1;
		else
			break ;
	}
	int mlcx = xt->pc_x - x;
	int mlcy = xt->pc_y - y;
	xt->pc_x = mlcx;
	xt->pc_y = mlcy;
	xt->off_x = x;
	xt->off_y = y;
	int tempy = y;
	new = (int **)malloc(mlcx * sizeof(int *));
	while (cntx < mlcx)
	{
		cnty = 0;
		y = tempy;
		new[cntx] = (int *)malloc(mlcy * sizeof(int *));
		while (cnty < mlcy)
		{
			new[cntx][cnty] = xt->piece[x][y];
			cnty += 1;
			y += 1;
		}
		cntx += 1;
		x += 1;
	}
	//print_new(new, mlcx, mlcy);
	free(xt->piece);
	xt->piece = new;
	//print_new(new, mlcx, mlcy);
}