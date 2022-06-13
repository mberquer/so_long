/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberquer <mberquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 11:26:09 by mberquer          #+#    #+#             */
/*   Updated: 2022/06/13 12:30:54 by mberquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	so_init(t_data *data)
{
	data->c_count = 0;
	data->p_count = 0;
	data->e_count = 0;
	data->s_count = 0;
	data->win = NULL;
	data->img_wall = NULL;
	data->img_player = NULL;
	data->img_exit = NULL;
	data->img_nothing = NULL;
	data->img_collectible = NULL;
}

int	check(char *path)
{
	int	i;

	i = 0;
	while (path[i +4])
		i++;
	if (path[i] == '.' && path[i +1] == 'b'
		&& path[i +2] == 'e' && path[i +3] == 'r')
		return (1);
	return (0);
}

void	so_size(t_data *data)
{
	data->l_win = 0;
	data->h_win = 0;
	while (data->map[0][data->l_win] != '\n')
		data->l_win++;
	while (data->map[data->h_win])
		data->h_win++;
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac == 2 && check(av[1]))
	{
		data = malloc(sizeof(t_data));
		if (!data)
			return (0);
		data->mlx = mlx_init();
		if (!data->mlx)
			return (0);
		so_init(data);
		if (!so_parse(data, av[1]))
			return (so_free(data));
		if (!so_check(data))
			return (so_free(data));
		so_size(data);
		data->win = mlx_new_window
			(data->mlx, (32 * data->l_win), (32 * data->h_win), "bababoi");
		if (!so_image(data))
			return (so_free(data));
		so_event(data);
		return (so_free(data));
	}
	write(1, "Error\nprovide .ber map\n", 23);
}
