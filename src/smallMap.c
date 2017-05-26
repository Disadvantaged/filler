/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallMap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 15:06:22 by dgolear           #+#    #+#             */
/*   Updated: 2017/05/26 15:27:28 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	goDownAndRight(t_filler *filler)
{
	int		i;
	int		j;

	i = 0;
	while (i < filler->msize.y)
	{
		j = 0;
		while (j < filler->msize.x)
		{
			j++;
		}
		i++;
	}
	return (0);
}

static int	goDownAndLeft(t_filler *filler)
{
	int		i;
	int		j;

	i = 0;
	while (i < filler->msize.y)
	{
		j = filler->msize.x - 1;
		while (j >= 0)
		{
			j--;
		}
		i++;
	}
	return (0);
}

static int	goUpAndRight(t_filler *filler)
{
	int		i;
	int		j;

	i = filler->msize.y - 1;
	while (i >= 0)
	{
		j = 0;
		while (j < filler->msize.x)
		{

			j++;
		}
		i--;
	}
	return (0);
}

static int	goUpAndLeft(t_filler *filler)
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

int		smallMap(t_filler *filler)
{
	if (filler->playerCoord.y < filler->msize.y / 2)
	{
		if (filler->playerCoord.x < filler->msize.x / 2)
			return (goUpAndLeft(filler));
		else
			return (goUpAndRight(filler));
	}
	else
	{
		if (filler->playerCoord.x < filler->msize.x / 2)
			return (goDownAndLeft(filler));
		else
			return (goDownAndRight(filler));
	}
}
