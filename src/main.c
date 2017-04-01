/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 14:34:50 by dgolear           #+#    #+#             */
/*   Updated: 2017/04/01 16:08:26 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		free_filler(t_filler *filler)
{
	int		i;

	i = 0;
	while (i < filler->msize.y)
		ft_strdel(&filler->map[i++]);
	free(filler->map);
	filler->map = NULL;
	i = 0;
	while (i < filler->tsize.y)
		ft_strdel(&filler->piece[i++]);
	free(filler->piece);
	filler->piece = NULL;
}

int			main(void)
{
	t_filler	*filler;
	int			flag;

	flag = 1;
	filler = init();
	while (flag != 0)
	{
		flag = update_map(filler);
		if (flag == 0)
			break ;
		get_piece(filler);
//		flag = place_piece(filler);
//		if (flag == 0)
//			break ;
		free_filler(filler);
	}
	free(filler);
	return (0);
}
