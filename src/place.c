/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 16:23:17 by dgolear           #+#    #+#             */
/*   Updated: 2017/04/13 16:59:04 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		check_place(t_filler * filler, int i, int y, int x)
{
	int		xs;
	int		ys;

	ys = y + filler->pcoord[i].y - filler->pcoord[0].y;
	xs = x + filler->pcoord[i].x - filler->pcoord[0].x;
	if (xs < 0 || ys < 0 || xs >= filler->msize.x || ys >= filler->msize.y
		|| filler->map[ys][xs] == filler->op
		|| filler->map[ys][xs] == filler->op - 32)
		return (-1);
	return (0);
}

int		place(t_filler *filler, int y, int x)
{
	int		i;
	int		k;
	int		ys;
	int		xs;

	i = 0;
	k = 0;
	while (i < filler->pcur)
	{
		ys = y + filler->pcoord[i].y - filler->pcoord[0].y;
		xs = x + filler->pcoord[i].x - filler->pcoord[0].x;
		if (k > 1 || (check_place(filler, i, y, x) == -1))
			return (-1);
		if (filler->map[ys][xs] == filler->p ||
			filler->map[ys][xs] + 32 == filler->p)
			k++;
		i++;
	}
	return (k == 1 ? 1 : 0);
}

int		place_piece(t_filler *filler)
{
	int		i;
	int		j;
	int		flag;

	i = 0 - filler->psize.y;
	while (i != filler->msize.y)
	{
		j = 0 - filler->psize.x;
		while (j != filler->msize.x)
		{
			if ((flag = place(filler, i, j)) == 1)
			{
				ft_printf("%d %d\n", i - filler->pcoord[0].y,
				j - filler->pcoord[0].x);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
