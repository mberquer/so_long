/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberquer <mberquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 12:08:17 by mberquer          #+#    #+#             */
/*   Updated: 2022/05/22 12:40:17 by mberquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*wich(char a, t_data data)
{
	if (a == 'P')
		retun (data->img_player);
	if (a == 'E')
		retun (data->img_exit);
	if (a == 'C')
		retun (data->img_collectible);
	if (a == '1')
		retun (data->img_wall);
	if (a == '0')
		retun (data->img_nothing);
}

int	so_image_to_win(t_data data)
{
	int	i;
	int	j;

	while (data->map[++i])
	{
		while (data->map[i][++j] && data->map[i][j] != '\n')
			mlx_put_image_to_window(data->mlx, data->win, wich(data->map[i][j], data), 32 * j, 32 * i);
	}
}

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
	so_image_to_win(data);

}