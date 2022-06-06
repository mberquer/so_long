/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberquer <mberquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 08:16:56 by mberquer          #+#    #+#             */
/*   Updated: 2022/06/06 08:16:56 by mberquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	so_free_mlxwin(t_data data)
{
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
}

void	so_destroy_image(t_data data)
{
	if (data->img_wall)
		mlx_destroy_image(data->img_wall);
	if (data->img_player)
		mlx_destroy_image(data->img_player);
	if (data->img_exit)
		mlx_destroy_image(data->img_exit);
	if (data->img_nothing)
		mlx_destroy_image(data->img_nothing);
	if (data->img_collectible)
		mlx_destroy_image(data->img_collectible);
}

void	so_free_map(t_data data)
{
	int	i;

	i = 0;
	while (data->map[i++])
		free(data->map[i]);
	free(data->map[i]);
	free(data->map);
}

int	so_free(t_data data)
{
	so_free_mlxwin(data);
	so_destroy_image(data);
	so_free_map(data);
	return (0);
}
