/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 14:34:50 by dgolear           #+#    #+#             */
/*   Updated: 2017/05/26 15:47:01 by dgolear          ###   ########.fr       */
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
	while (i < filler->psize.y)
		ft_strdel(&filler->piece[i++]);
	free(filler->piece);
	filler->piece = NULL;
}

void		get_starting_position(t_filler *filler)
{
	int		i;
	int		j;

	i = 0;
	while (i < filler->msize.y)
	{
		j = 0;
		while (j < filler->msize.x)
		{
			if (filler->map[i][j] == PLAYER || filler->map[i][j] == PLAYER + 32)
			{
				filler->playerCoord.x = j;
				filler->playerCoord.y = i;
			}
			if (filler->map[i][j] == OP || filler->map[i][j] == OP + 32)
			{
				filler->opCoord.x = j;
				filler->opCoord.y = i;
			}
			j++;
		}
		i++;
	}
}

void		print(char **map, struct s_coord size)
{
	int		i;

	i = 0;
	while (i < size.y)
	{
		ft_dprintf(STDERR_FILENO, "%s\n", map[i]);
		i++;
	}
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
		flag = algo(filler);
		if (flag == 0)
			break ;
		free_filler(filler);
	}
	ft_printf("0 0\n");
	free(filler);
	return (0);
}
