/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberquer <mberquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 12:08:17 by mberquer          #+#    #+#             */
/*   Updated: 2022/06/14 13:38:38 by mberquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*wich(char a, t_data *data)
{
	if (a == 'P')
		return (data->img_player);
	if (a == 'E')
		return (data->img_exit);
	if (a == 'C')
		return (data->img_collectible);
	if (a == '1')
		return (data->img_wall);
	if (a == '0')
		return (data->img_nothing);
	return (0);
}

int	so_image_to_win(t_data *data)
{
	int	y;
	int	x;

	y = -1;
	while (data->map[++y])
	{
		x = -1;
		while (data->map[y][++x] && data->map[y][x] != '\n')
			mlx_put_image_to_window(data->mlx, data->win, wich
				(data->map[y][x], data), 32 * x, 32 * y);
	}
	return (1);
}

int	so_assets(t_data *data)
{
	int	i;

	data->img_player = mlx_xpm_file_to_image
		(data->mlx, "assets/players.xpm", &i, &i);
	if (!data->img_player)
		return (0);
	data->img_collectible = mlx_xpm_file_to_image
		(data->mlx, "assets/collectibles.xpm", &i, &i);
	if (!data->img_collectible)
		return (0);
	data->img_nothing = mlx_xpm_file_to_image
		(data->mlx, "assets/nothing.xpm", &i, &i);
	if (!data->img_nothing)
		return (0);
	data->img_wall = mlx_xpm_file_to_image
		(data->mlx, "assets/walls.xpm", &i, &i);
	if (!data->img_wall)
		return (0);
	data->img_exit = mlx_xpm_file_to_image
		(data->mlx, "assets/exits.xpm", &i, &i);
	if (!data->img_exit)
		return (0);
	return (1);
}

int	so_image(t_data *data)
{
	if (!so_assets(data))
	{
		ft_printf("Error\nimage initialisation failed\n");
		return (0);
	}
	so_image_to_win(data);
	return (1);
}
