/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:33:02 by mberquer          #+#    #+#             */
/*   Updated: 2022/02/02 00:11:32 by mberquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(char *vault, int fd)
{
	int		ret;
	char	*buf;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	ret = 1;
	while (!ft_strchr(vault, '\n') && ret != 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret < 0)
		{
			free(vault);
			free(buf);
			return (NULL);
		}
		buf[ret] = '\0';
		vault = ft_join(vault, buf);
	}
	free(buf);
	return (vault);
}

char	*ft_get(char *s)
{
	char	*s2;
	int		i;

	i = 0;
	if (!s[i])
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	s2 = malloc((i + 1) * sizeof(char));
	if (!s2)
		return (NULL);
	i = -1;
	while (s[++i] && s[i] != '\n')
		s2[i] = s[i];
	if (s[i] == '\n')
	{
		s2[i] = s[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_save(char *vault)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	while (vault[i] && vault[i] != '\n')
		i++;
	new = malloc(sizeof(char) * (ft_strlen(vault) - i + 1));
	if (!new || !vault[i])
	{
		free(new);
		free(vault);
		return (NULL);
	}
	i++;
	j = 0;
	while (vault[i])
	{
		new[j] = vault[i];
		i++;
		j++;
	}
	new[j] = '\0';
	free(vault);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*vault;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	vault = ft_read(vault, fd);
	if (!vault)
		return (NULL);
	line = ft_get(vault);
	vault = ft_save(vault);
	return (line);
}
