/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 15:44:31 by dgolear           #+#    #+#             */
/*   Updated: 2017/04/01 16:25:42 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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
	if (filler->map == NULL)
	{
		perror("filler");
		exit(-1);
	}
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

t_filler	*init(void)
{
	t_filler	*filler;
	char		*buf;

	get_next_line(STDIN_FILENO, &buf);
	filler = (t_filler *)malloc(sizeof(t_filler));
	filler->map = NULL;
	filler->piece = NULL;
	filler->msize.x = 0;
	filler->msize.y = 0;
	filler->tsize.x = 0;
	filler->tsize.y = 0;
	filler->player = buf[10] == '1' ? 'O' : 'X';
	ft_strdel(&buf);
	return (filler);
}
