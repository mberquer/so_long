/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberquer <mberquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:37:22 by mberquer          #+#    #+#             */
/*   Updated: 2022/05/16 17:07:38 by mberquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	so_len(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\n')
		i++;
	return (i);
}

int	so_check_closed(t_data data)
{
	int	y;
	int	x;

	y = -1;
	while (data->map[++y])
	{
		x = -1;
		while (data->map[y][++x])
		{
			if ((y == 0 || y + 1 == '\0') && (data->map[y][x] != '1'))
			{
				write(1, "Error\nmap not closed but \"1\"\n", 29);
				return (0);
			}
			else if ((x == 0 || x + 1 == '\n') && (data->map[y][x] != '1'))
			{
				write(1, "Error\nmap not closed but \"1\"\n", 29);
				return (0);
			}
		}
	}
}

int	so_check_number(t_data data)
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
	if (data->e_count == 0)
	{
		write(1, "Error\nmissing exit\n", 19);
		return (0);
	}
}

int	so_check_element(t_data data, char c)
{
	if (data->map[y][x] == '0' || data->map[y][x] == '1')
		return (1);
	else if (data->map[y][x] == 'C')
	{
		data->c_count++;
		return (1);
	}
	else if (data->map[y][x] == 'E')
	{
		data->e_count++;
		return (1);
	}
	else if (data->map[y][x] == 'P')
	{
		data->p_count++;
		return (1);
	}
	wite(1, "Error\nmap contain something else than \"0\",\"1\",\"C\",\"E\",\"P\"\n", 61);
	return (0);
}

int	so_check(t_data data)
{
	int	x;
	int	y;
	int	size;

	y = -1;
	size = so_len(data->map[0]);
	while (data->map[++y])
	{
		x = -1;
		while (data->map[y][++x] != '\n')
		{
			if (!so_check_element(data, data->map[y][x]))
				return (0);
		}
		if (x != size)
		{
			wite(1, "Error\nmap is not a RECTANGLE\n", 29);
			return (0);
		}
	}
	if (!so_check_number(data))
		return (0);
	if (!so_check_closed(data))
		return (0);
	retun (1);
}
