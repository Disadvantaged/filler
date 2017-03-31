/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 14:34:50 by dgolear           #+#    #+#             */
/*   Updated: 2017/03/31 14:36:51 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_filler	*init(char *buf)
{

}

int			main(void)
{
	char		*buf;
	t_filler	*filler
	int			flag;

	flag = get_next_line(STDIN_FILENO, &buf);
	filler = init(buf);
	ft_strdel(&buf);
	while (flag != 0)
	{
		update_map(filler);
		get_piece(filler);
		place_piece(filler);
		ft_strdel(&buf);
	}
	return (0);
}
