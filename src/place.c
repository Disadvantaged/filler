/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 16:23:17 by dgolear           #+#    #+#             */
/*   Updated: 2017/05/26 14:12:15 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		checkPlace(t_filler * filler, int i, int y, int x)
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

int		canPlace(t_filler *filler, int y, int x)
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
