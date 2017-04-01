/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 14:35:28 by dgolear           #+#    #+#             */
/*   Updated: 2017/04/01 16:25:07 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"
# include "errno.h"

typedef struct	s_coord
{
	int		x;
	int		y;
}				t_coord;

typedef struct	s_filler
{
	char			**map;
	struct coord	msize;
	char			**piece;
	strcut coord	*pcoord;
	struct coord	tsize;
	char			player;
}				t_filler;

int			update_map(t_filler *filler);
void		get_piece(t_filler *filler);
t_filler	*init(void);
void		free_filler(t_filler *filler);

#endif
