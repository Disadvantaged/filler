/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 16:23:17 by dgolear           #+#    #+#             */
/*   Updated: 2017/04/08 14:17:15 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		place(t_filler *filler, int y, int x)
{
	int		i;
	int		k;
	int		ys;
	int		xs;

	i = 0;
	k = 0;
	if (y + filler->psize.y > filler->msize.y
		|| x + filler->psize.x > filler->msize.x)
		return (-1);
	while (i < filler->pcur)
	{
		ys = y + filler->pcoord[i].y - filler->pcoord[0].y;
		xs = x + filler->pcoord[i].x - filler->pcoord[0].x;
		if (filler->map[ys][xs] == filler->player ||
			ft_toupper(filler->map[ys][xs]) == filler->player)
			k++;
		if (k > 1 || filler->map[ys][xs] == filler->opponent ||
			ft_toupper(filler->map[ys][xs]) == filler->opponent)
			return (-1);
		i++;
	}
	if (k == 1)
		return (1);
	return (0);
}

int		place_piece(t_filler *filler)
{
	int		i;
	int		j;
	int		flag;

	i = 0;
	while (i < filler->msize.y)
	{
		j = 0;
		while (j < filler->msize.x)
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
