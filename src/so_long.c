/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberquer <mberquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 11:26:09 by mberquer          #+#    #+#             */
/*   Updated: 2022/05/22 12:21:46 by mberquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av)
{
	t_data	*data;

	if (ac = 2 && check(av[1]))
	{
		data->mlx = mlx_init();
		if (!data->mlx)
			return (0);
		so_parse(data, av[1]);
		so_check(data);
		data->win = mlx_new_window(data->mlx, 32 * data->l_win, 32 * data->h_win, "bababoi");
		so_image(data);
	}
	write(1, "Error\nprovide .ber map\n", 23);
}