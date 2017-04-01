/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 14:35:28 by dgolear           #+#    #+#             */
/*   Updated: 2017/04/01 15:56:30 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"
# include "errno.h"

struct coord
{
	int		x;
	int		y;
};

typedef struct	s_filler
{
	char			**map;
	struct coord	msize;
	char			**piece;
	struct coord	tsize;
	
	int				player;
}				t_filler;

int			update_map(t_filler *filler);
void		get_piece(t_filler *filler);
t_filler	*init(void);
void		free_filler(t_filler *filler);

#endif
