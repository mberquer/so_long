/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberquer <mberquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 11:26:09 by mberquer          #+#    #+#             */
/*   Updated: 2022/05/16 17:11:12 by mberquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av)
{
	t_data	*data;

	if (ac = 2 && check(av[1]))
	{
		so_parse(data, av[1]);
		so_check(data);
	}
	write(1, "Error\nprovide .ber map\n", 23);
}