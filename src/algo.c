/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 14:09:20 by dgolear           #+#    #+#             */
/*   Updated: 2017/05/26 14:11:28 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		play(t_filler *filler)
{
	if (filler->msize.y > 20)
		return (bigMap(filler));
	else
		return (smallMap(filler));
}
