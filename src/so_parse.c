/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberquer <mberquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 11:49:48 by mberquer          #+#    #+#             */
/*   Updated: 2022/06/14 13:42:39 by mberquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	so_count(char *path)
{
	int		count;
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	count = 1;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		count++;
	}
	close(fd);
	free(line);
	return (count);
}

int	so_parse(t_data *data, char *path)
{
	int		i;
	int		fd;
	int		count;

	i = 0;
	count = so_count(path);
	data->map = malloc((count + 1) * sizeof(char *));
	if (!data->map)
		return (0);
	fd = open(path, O_RDONLY);
	data->map[i] = get_next_line(fd);
	while (data->map[i++])
		data->map[i] = get_next_line(fd);
	close(fd);
	return (1);
}
