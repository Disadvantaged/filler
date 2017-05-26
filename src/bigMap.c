/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigMap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 15:06:10 by dgolear           #+#    #+#             */
/*   Updated: 2017/05/26 15:30:45 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	hasContactWithEnemy(t_filler *filler)
{

}

static int	findBestCase(t_filler *filler)
{

}

static int	GoDown(t_filler *filler)
{
	int		i;
	int		j;

	i = filler->msize.y - 1;
	while (i >= 0)
	{
		j = filler->msize.x - 1;
		while (j >= 0)
		{
			j--;
		}
		i--;
	}
	return (0);
}

static int	GoUp(t_filler *filler)
{
	int		i;
	int		j;

	i = 0;
	while (i < filler->msize.y)
	{
		j = 0;
		while (i < filler->msize.x)
		{
			j++;
		}
		i++;
	}
	return (0);
}

int		bigMap(t_filler *filler)
{
	if (hasContactWithEnemy(filler))
		return (findBestCase(filler));
	else
	{
		if (filler->playerCoord.y < filler->opCoord.y)
		{
			return (goDown(filler));
		}
		else
		{
			return (goUp(filler));
		}
	}
}
