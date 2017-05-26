/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigMap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 15:06:10 by dgolear           #+#    #+#             */
/*   Updated: 2017/05/26 17:07:21 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
/*
static int	has_contact_with_enemy(t_filler *filler)
{
	if (filler)
		return (1);
	else
		return (0);
}

static int	find_best_case(t_filler *filler)
{
	if (filler)
		return (1);
	else
		return (0);
}
*/
static int	go_down(t_filler *filler)
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

static int	go_up(t_filler *filler)
{
	int		i;
	int		j;

	i = 0;
	while (i < filler->msize.y - 1)
	{
		j = 0;
		while (j < filler->msize.x - 1)
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

int		big_map(t_filler *filler)
{
/*	if (has_contact_with_enemy(filler))
		return (find_best_case(filler));
	else
	{
*/		if (filler->playerCoord.y < filler->opCoord.y)
		{
			return (go_down(filler));
		}
		else
		{
			return (go_up(filler));
		}
//	}
}
