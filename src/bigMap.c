/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigMap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 15:06:10 by dgolear           #+#    #+#             */
/*   Updated: 2017/05/26 15:13:20 by dgolear          ###   ########.fr       */
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

}

static int	GoUp(t_filler *filler)
{

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
