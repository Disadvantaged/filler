/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 14:34:50 by dgolear           #+#    #+#             */
/*   Updated: 2017/03/31 17:03:53 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_filler	*init(char *buf)
{
	int			i;
	t_filler	*filler;

	i = 0;
	filler = (t_filler *)malloc(sizeof(t_filler));
	filler->map = NULL;
	filler->piece = NULL;
	filler->msize.x = 0;
	filler->msize.y = 0;
	filler->tsize.x = 0;
	filler->tsize.y = 0;
	while (buf[i] && !ft_isdigit(buf[i]))
		i++;
	filler->player = ft_atoi(&buf[i]);
	return (filler);
}

int			update_map(t_filler *filler)
{
	char	*buf;
	int		i;

	if (get_next_line(STDIN_FILENO, &buf) == 0)
		return (0);
	filler->msize.y = ft_atoi(&buf[8]);
	filler->msize.x = ft_atoi(&buf[9 + ft_nbrlen(filler->msize.y)]);
	ft_strdel(&buf);
	get_next_line(STDIN_FILENO, &buf);
	ft_strdel(&buf);
	filler->map = (char **)malloc(sizeof(char *) * (filler->msize.y + 1));
	i = 0;
	filler->map[filler->msize.y] = NULL;
	while (i < filler->msize.y)
	{
		get_next_line(STDIN_FILENO, &buf);
		filler->map[i++] = ft_strdup(buf + 4);
		ft_strdel(&buf);
	}
	return (1);
}

void		get_piece(t_filler *filler)
{
	char	*buf;
	int		i;

	get_next_line(STDIN_FILENO, &buf);
	filler->tsize.y = ft_atoi(&buf[6]);
	filler->tsize.x = ft_atoi(&buf[7 + ft_nbrlen(filler->tsize.y)]);
	filler->piece = (char **)malloc(sizeof(char *) * (filler->tsize.y + 1));
	i = 0;
	while (i < filler->tsize.y)
		get_next_line(STDIN_FILENO, &filler->piece[i++]);
	filler->piece[i] = NULL;
}

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
	char		*buf;
	t_filler	*filler;
	int			flag;

	flag = get_next_line(STDIN_FILENO, &buf);
	filler = init(buf);
	ft_strdel(&buf);
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
