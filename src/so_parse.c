/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberquer <mberquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 11:49:48 by mberquer          #+#    #+#             */
/*   Updated: 2022/05/25 16:19:53 by mberquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	so_count(char *path)
{
	int		count;
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	line = ft_getnextline(fd);
	count = 1;
	while (line)
	{
		free(line);
		line = ft_getnextline(fd);
		count++;
	}
	close(fd);
	free(line);
	return (count);
}

int	so_parse(t_data data, char *path)
{
	int		i;
	int		fd;
	int		count;

	i = 0;
	count = so_count(path);
	data->map = malloc(count + 1 * sizeof(char *));
	if (!data->map)
		return (0);
	data->map[count + 1] = '\0';
	fd = open(path, O_RDONLY);
	data->map[i] = ft_getnextline(fd);
	while (data->map[i++])
		data->map[i] = ft_getnexgline(fd);
	close(fd);
	return (1);
}
