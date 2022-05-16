/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberquer <mberquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 11:26:07 by mberquer          #+#    #+#             */
/*   Updated: 2022/05/16 13:23:18 by mberquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx_linux/mlx.h"
# include <mlx.h>
# include "get_next_line.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdarg.h>

 typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img_wall;
	void	*img_player;
	void	*img_exit;
	void	*img_nothing;
	int		c_count;
	int		p_count;
	int		e_count;
	int		s_count;
	int		h_win;
	int		l_win;
	char	**map;
}	t_data;
#endif