/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberquer <mberquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 07:20:16 by mberquer          #+#    #+#             */
/*   Updated: 2022/06/13 12:29:33 by mberquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	so_step(t_data *data)
{
	ft_printf("\r%i", ++data->s_count);
	if (data->tile == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->img_exit,
			32 * data->h_x, 32 * data->h_y);
	else
		mlx_put_image_to_window(data->mlx, data->win, data->img_nothing,
			32 * data->h_x, 32 * data->h_y);
}

int	so_move_up(t_data *data)
{	
	data->tile = data->map[data->h_y][data->h_x];
	so_step(data);
	if (data->map[data->h_y - 1][data->h_x] == 'C')
	{
		data->c_count--;
		data->map[data->h_y - 1][data->h_x] = '0';
	}
	else if (data->map[data->h_y - 1][data->h_x] == 'E' && data->c_count == 0)
		return (write(1, "\nGG !\n", 6));
	mlx_put_image_to_window(data->mlx, data->win, data->img_player,
		32 * data->h_x, 32 * --data->h_y);
	return (0);
}

int	so_move_left(t_data *data)
{	
	data->tile = data->map[data->h_y][data->h_x];
	so_step(data);
	if (data->map[data->h_y][data->h_x - 1] == 'C')
	{
		data->c_count--;
		data->map[data->h_y][data->h_x - 1] = '0';
	}
	else if (data->map[data->h_y][data->h_x - 1] == 'E' && data->c_count == 0)
		return (write(1, "\nGG !\n", 6));
	mlx_put_image_to_window(data->mlx, data->win, data->img_player,
		32 * --data->h_x, 32 * data->h_y);
	return (0);
}

int	so_move_down(t_data *data)
{	
	data->tile = data->map[data->h_y][data->h_x];
	so_step(data);
	if (data->map[data->h_y + 1][data->h_x] == 'C')
	{
		data->c_count--;
		data->map[data->h_y + 1][data->h_x] = '0';
	}
	else if (data->map[data->h_y + 1][data->h_x] == 'E' && data->c_count == 0)
		return (write(1, "\nGG !\n", 6));
	mlx_put_image_to_window
		(data->mlx, data->win, data->img_player,
			32 * data->h_x, 32 * ++data->h_y);
	return (0);
}

int	so_move_right(t_data *data)
{	
	data->tile = data->map[data->h_y][data->h_x];
	so_step(data);
	if (data->map[data->h_y][data->h_x + 1] == 'C')
	{
		data->c_count--;
		data->map[data->h_y][data->h_x + 1] = '0';
	}
	else if (data->map[data->h_y][data->h_x + 1] == 'E' && data->c_count == 0)
		return (write(1, "\nGG !\n", 6));
	mlx_put_image_to_window(data->mlx, data->win, data->img_player,
		32 * ++data->h_x, 32 * data->h_y);
	return (0);
}
