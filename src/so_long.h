/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberquer <mberquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 11:26:07 by mberquer          #+#    #+#             */
/*   Updated: 2022/06/13 12:23:29 by mberquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx_linux/mlx.h"
# include "../gnl/get_next_line.h"
# include "../ft_printf/ft_printf.h"

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img_wall;
	void	*img_player;
	void	*img_exit;
	void	*img_nothing;
	void	*img_collectible;
	int		c_count;
	int		p_count;
	int		e_count;
	int		s_count;
	int		h_win;
	int		l_win;
	int		h_y;
	int		h_x;
	char	**map;
	char	tile;
}	t_data;

int		so_check(t_data *data);
int		so_free(t_data *data);
int		so_image(t_data *data);
void	so_event(t_data *data);
int		so_move_right(t_data *data);
int		so_move_left(t_data *data);
int		so_move_up(t_data *data);
int		so_move_down(t_data *data);
int		so_parse(t_data *data, char *path);
#endif