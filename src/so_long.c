/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberquer <mberquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 11:26:09 by mberquer          #+#    #+#             */
/*   Updated: 2022/06/07 09:08:24 by mberquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	so_size(t_data data)
{
	data.l_win = 0;
	data.h_win = 0;
	while (data.map[0][data.l_win] != '\n')
		data.l_win++;
	while (data.map[data.h_win])
		data.h_win++;
}

int main(int ac, char **av)
{
	t_data	*data;

	if (ac = 2 && check(av[1]))
	{
		data.mlx = mlx_init();
		if (!data.mlx)
			return (0);
		if (!so_parse(data, av[1]))
			return (so_free);
		if (!so_check(data))
			return (so_free);
		so_size(data);
		data.win = mlx_new_window
			(data.mlx, 32 * data.l_win, 32 * data.h_win, "bababoi");
		if (!so_image(data))
			return (so_free);
		so_event(data);
		so_free(data);
	}
	write(1, "Error\nprovide .ber map\n", 23);
}
