/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 10:42:16 by tpons             #+#    #+#             */
/*   Updated: 2020/03/10 09:36:25 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		key_management(int key, t_param *p)
{
	if (key == 53)
		close_win();
	else if (key == 13)
		forward(p);
	else if (key == 1)
		backward(p);
	else if (key == 0)
		left(p);
	else if (key == 2)
		right(p);
	else if (key == 123)
		rotate(p, key);
	else if (key == 124)
		rotate(p, key);
	return (0);
}

int		play(t_param *p)
{
	int endian;

	p->i[0]->image_ptr = mlx_new_image(p->d->mlx_ptr, p->s->x, p->s->y);
	p->i[0]->image_data = mlx_get_data_addr(p->i[0]->image_ptr, &p->i[0]->bpp,
		&p->i[0]->size_line, &endian);
	dda(p);
	mlx_put_image_to_window(p->d->mlx_ptr, p->d->win_ptr,
		p->i[0]->image_ptr, 0, 0);
	return (0);
}

void	game(t_param *p)
{
	p->d->win_ptr = mlx_new_window(p->d->mlx_ptr,
		p->s->x, p->s->y, "Cub3D");
	mlx_hook(p->d->win_ptr, 2, 5, key_management, p);
	mlx_hook(p->d->win_ptr, 17, 1, close_win, (void *)0);
	mlx_loop_hook(p->d->mlx_ptr, play, p);
	mlx_loop(p->d->mlx_ptr);
}
