/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 14:35:28 by dgolear           #+#    #+#             */
/*   Updated: 2017/04/08 14:16:04 by dgolear          ###   ########.fr       */
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

/*
** player and opponent equal to 'X' or to 'O'
** pcoord is array of coordinates of '*' characters in token
** tsize is token size
** pcur is max size of array of pcoord
*/

typedef struct	s_filler
{
	char			**map;
	struct s_coord	msize;
	char			**piece;
	struct s_coord	psize;
	struct s_coord	pcoord[1024];
	int				pcur;
	char			player;
	char			opponent;
}				t_filler;

int				update_map(t_filler *filler);
void			get_piece(t_filler *filler);
t_filler		*init(void);
void			free_filler(t_filler *filler);
int				place_piece(t_filler *filler);

#endif
