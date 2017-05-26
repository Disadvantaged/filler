/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallMap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 15:06:22 by dgolear           #+#    #+#             */
/*   Updated: 2017/05/26 15:12:35 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	goDownAndRight(t_filler *filler)
{

}

static int	goDownAndLeft(t_filler *filler)
{

}

static int	goUpAndRight(t_filler *filler)
{

}

static int	goUpAndLeft(t_filler *filler)
{

}

int		smallMap(t_filler *filler)
{
	if (filler->playerCoord.y < filler->msize.y / 2)
	{
		if (filler->playerCoord.x < filler->msize.x / 2)
			return (goDownAndRight(filler));
		else
			return (goDownAndLeft(filler));
	}
	else
	{
		if (filler->playerCoord.x < filler->msize.x / 2)
			return (goUpAndRight(filler));
		else
			return (goUpAndLeft(filler));
	}
}
