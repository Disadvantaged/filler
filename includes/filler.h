/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 14:35:28 by dgolear           #+#    #+#             */
/*   Updated: 2017/04/06 16:26:20 by dgolear          ###   ########.fr       */
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
	struct s_coord	msize;
	char			**piece;
	struct s_coord	pcoord[1024];
	int				pcur;
	struct s_coord	tsize;
	char			player;
}				t_filler;

int				update_map(t_filler *filler);
void			get_piece(t_filler *filler);
t_filler		*init(void);
void			free_filler(t_filler *filler);
int				place_piece(t_filler *filler);

#endif
