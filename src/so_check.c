/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberquer <mberquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:37:22 by mberquer          #+#    #+#             */
/*   Updated: 2022/06/13 12:26:11 by mberquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	so_len(char **map, int y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[0][i] && map[0][i] != '\n')
		i++;
	while (map[y][j] && map[y][j] != '\n')
		j++;
	if (j == i)
		return (1);
	return (0);
}

int	so_check_closed(t_data *data)
{
	int	y;
	int	x;

	y = -1;
	while (data->map[++y])
	{
		x = -1;
		while (data->map[y][++x] && data->map[y][x] != '\n')
		{
			if ((y == 0 || !data->map[y + 1]) && (data->map[y][x] != '1'))
			{
				write(1, "Error\nmap not closed by \"1\"\n", 28);
				return (0);
			}
			else if ((x == 0 || (data->map[y][x + 1] == '\n'
					|| !data->map[y][x + 1])) && (data->map[y][x] != '1'))
			{
				write(1, "Error\nmap not closed by \"1\"\n", 28);
				return (0);
			}
		}
	}
	return (1);
}

int	so_check_number(t_data *data)
{
	if (data->c_count == 0)
	{
		write(1, "Error\nmissing collectible\n", 26);
		return (0);
	}
	if (data->p_count == 0)
	{
		write(1, "Error\nmissing starting point\n", 29);
		return (0);
	}
	if (data->p_count > 1)
	{
		write(1, "Error\ntoo many starting point\n", 30);
		return (0);
	}
	if (data->e_count == 0)
	{
		write(1, "Error\nmissing exit\n", 19);
		return (0);
	}
	return (1);
}

int	so_check_element(t_data *data, char c)
{
	if (c == '0' || c == '1')
		return (1);
	else if (c == 'C')
	{
		data->c_count++;
		return (1);
	}
	else if (c == 'E')
	{
		data->e_count++;
		return (1);
	}
	else if (c == 'P')
	{
		data->p_count++;
		return (1);
	}
	write(1, "Error\nmap contain something else than \"0\",\"1\",\"C\",\"E\",\"P\"\n", 59);
	return (0);
}

int	so_check(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (data->map[++y])
	{
		x = -1;
		while (data->map[y][++x] && data->map[y][x] != '\n')
		{
			if (!so_check_element(data, data->map[y][x]))
				return (0);
		}
		if (!so_len(data->map, y))
		{
			write(1, "Error\nmap is not a RECTANGLE\n", 29);
			return (0);
		}
	}
	if (!so_check_number(data))
		return (0);
	if (!so_check_closed(data))
		return (0);
	return (1);
}
