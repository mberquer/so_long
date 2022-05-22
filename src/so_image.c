/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberquer <mberquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 12:08:17 by mberquer          #+#    #+#             */
/*   Updated: 2022/05/22 12:21:19 by mberquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	so_assets(t_data data)
{
	int	i;

	data->img_player = mlx_xpm_file_to_image(mlx, "assets/players.xpm", &i, &i);
	data->img_collectible = mlx_xpm_file_to_image(mlx, "assets/collectibles.xpm", &i, &i);
	data->img_nothing = mlx_xpm_file_to_image(mlx, "assets/nothing.xpm", &i, &i);
	data->img_wall = mlx_xpm_file_to_image(mlx, "assets/walls.xpm", &i, &i);
	data->img_exit = mlx_xpm_file_to_image(mlx, "assets/exits.xpm", &i, &i);
}

int	so_image(t_data data)
{
	so_assets(data);
}