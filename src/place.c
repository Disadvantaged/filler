/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 16:23:17 by dgolear           #+#    #+#             */
/*   Updated: 2017/04/06 17:17:52 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		place(t_filler *filler, int y, int x, struct s_coord *coord)
{
}

int		place_piece(t_filler *filler)
{
	int		i;
	int		j;
	int		n;
	int		flag;

	i = 0;
	while (i < filler->msize.y)
	{
		j = 0;
		while (j < filler->msize.x)
		{
			n = 0;
			while (n < filler->pcur)
			{
				if ((flag = place(filler, i, j, filler->pcoord[n])) == 1)
				{
					ft_printf("%d %d\n", i, j);
					return (0);
				}
				n++;
			}
			j++;
		}
		i++;
	}
}
