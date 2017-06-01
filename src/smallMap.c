/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallMap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 15:06:22 by dgolear           #+#    #+#             */
/*   Updated: 2017/06/01 11:35:29 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	go_down_and_right(t_filler *filler)
{
	int		i;
	int		j;

	i = 0; 
	while (i < filler->msize.y)
	{
		j = 0;
		while (j < filler->msize.x)
		{
			if (can_place(filler, i, j) == 1)
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

static int	go_down_and_left(t_filler *filler)
{
	int		i;
	int		j;

	i = 0 - filler->psize.y;
	while (i < filler->msize.y)
	{
		j = filler->msize.x - 1;
		while (j >= 0)
		{
			if (can_place(filler, i, j) == 1)
			{
				ft_printf("%d %d\n", i - filler->pcoord[0].y,
						j - filler->pcoord[0].x);
				return (1);
			}
			j--;
		}
		i++;
	}
	return (0);
}

static int	go_up_and_right(t_filler *filler)
{
	int		i;
	int		j;

	i = filler->msize.y - 1;
	while (i >= 0)
	{
		j = 0 - filler->psize.x;
		while (j < filler->msize.x)
		{
			if (can_place(filler, i, j) == 1)
			{
				ft_printf("%d %d\n", i - filler->pcoord[0].y,
						j - filler->pcoord[0].x);
				return (1);
			}
			j++;
		}
		i--;
	}
	return (0);
}

static int	go_up_and_left(t_filler *filler)
{
	int		i;
	int		j;

	i = filler->msize.y - 1;
	while (i >= 0)
	{
		j = filler->msize.x - 1;
		while (j >= 0)
		{
			if (can_place(filler, i, j) == 1)
			{
				ft_printf("%d %d\n", i - filler->pcoord[0].y,
						j - filler->pcoord[0].x);
				return (1);
			}
			j--;
		}
		i--;
	}
	return (0);
}

int		small_map(t_filler *filler)
{
	if (filler->playerCoord.y < filler->opCoord.y) 
	{
		if (filler->playerCoord.x < filler->opCoord.x)
			return (go_up_and_left(filler));
		else
			return (go_up_and_right(filler));
	}
	else
	{
		if (filler->playerCoord.x < filler->opCoord.x)
			return (go_down_and_left(filler));
		else
			return (go_down_and_right(filler));
	}
}
