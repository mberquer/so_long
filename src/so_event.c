/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberquer <mberquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 21:26:25 by mberquer          #+#    #+#             */
/*   Updated: 2022/06/05 21:26:25 by mberquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	so_move(t_data data, char c)
{
	int	check;

	if (c == 'W' && data->map[data->h_y - 1][data->h_x] != '1')
		check = so_move_up(data);
	if (c == 'A' && data->map[data->h_y][data->h_x - 1] != '1')
		check = so_move_left(data);
	if (c == 'S' && data->map[data->h_y + 1][data->h_x] != '1')
		check = so_move_down(data);
	if (c == 'D' && data->map[data->h_y][data->h_x + 1] != '1')
		check = so_move_right(data);
	if (check)
		mlx_loop_end(data->mlx);
}
int	so_key(int key, t_data data)
{
	if (key == 65307)
		mlx_loop_end(data->mlx);
	else if (key == 65362 || key == 119)
		so_move(data, 'W');
	else if (key == 65361 || key == 97)
		so_move(data, 'A');
	else if (key == 65364 || key == 115)
		so_move(data, 'S');
	else if (key == 65363 || key == 100)
		so_move(data, 'D');
	return (0);
}

void	so_event(t_data data)
{
	mlx_key_hook(data->win, int so_key, data);
	mlx_hook(win, 17, 0, mlx_loop_end, data->mlx);
	mlx_loop(data->mlx)
}