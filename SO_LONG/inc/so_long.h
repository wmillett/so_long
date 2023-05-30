/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:10:51 by wmillett          #+#    #+#             */
/*   Updated: 2023/05/28 11:56:43 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//MLX ------------------------------------------
# include "../MLX42/include/MLX42/MLX42.h"
# include <stdbool.h>
//so_long ------------------------------------------
# include "../libft/inc/libft.h"
# include <stdio.h>

# define ERROR2 -2

typedef struct s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct s_img
{
	mlx_image_t	*wall;
	mlx_image_t	*ennemy;
	mlx_image_t	*ground;
	mlx_image_t	*mc;
	mlx_image_t	*door;
	mlx_image_t	*item;
	int32_t		check;
}				t_img;

typedef struct s_mc
{
	t_point		pos;
	int			move;
	bool		rtl;
}				t_mc;

typedef struct s_map
{
	char		**map;
	char		**map2;
	int			collectible;
	t_point		size;
	t_point		begin;
	t_point		end;
	int			missing_exit;
	int			missing_collectibles;
}				t_map;

typedef struct s_count
{
	char		*buffer;
	char		previous_char;
	int			num_lines;
	int			num_bytes_read;
	int			prev_bytes;
}				t_count;

typedef struct s_game
{
	t_img		temps;
	t_map		mpack;
	t_mc		cpack;
	mlx_t		*mlx;
}				t_game;

//error_rend -------------------------------------
void			printerror_mlx(int type, t_game *gpack);
void			printerror_render(int type, t_game *gpack, int len);
//error ------------------------------------------
void			printerror_pre(int type);
void			printerror_mem(int type, t_game *gpack);
void			printerror_pars(int type, t_game *gpack, int nb);
void			printerror_pars2(int type, t_game *gpack);
void			printerror_pars3(int type, t_game *gpack);
//handle_exit -------------------------------------
void			leave(t_game *gpack);
void			win(t_game *gpack);
//init_temp_extra ---------------------------------
mlx_image_t		*init_exit(t_game *gpack);
//init_temp --------------------------------------
mlx_image_t		*init_wall(t_game *gpack);
mlx_image_t		*init_door(t_game *gpack);
mlx_image_t		*init_mc(t_game *gpack);
mlx_image_t		*init_ground(t_game *gpack);
mlx_image_t		*init_item(t_game *gpack);
//pars_maps --------------------------------------
int				validcharacters(t_map mpack, int i, int j, int k);
int				isrectangle(t_map mpack);
int				walls(t_map mpack);
int				objects(t_game *gpack, int i, int j);
t_map			check_path(t_map mpack, t_point cur);
//render_items -----------------------------------
void			print_move(int move, t_game *gpack);
void			render_items(t_game *gpack, int first);
//render_map -------------------------------------
t_game			*render_static_map(t_game *gpack, int test);
mlx_image_t		*render_mc(t_game *gpack, int move);
//utils_check ------------------------------------
void			check_render(int32_t check, t_game *gpack);
void			check_fd(int fd, t_game *gpack, int type);
//utils_mem --------------------------------------
void			mmfree(t_game *gpack);
void			mfree(t_game *gpack);
void			allfree(t_game *gpack, bool term);
void			dfree(t_game *gpack, int len);
//utils_read -------------------------------------
int				count_lines(int fd, t_game *gpack, int num_lines);
//utils ------------------------------------------
int				ft_strchr_count(t_map mpack, char *line, char c);
t_map			duplicate_map(t_game *gpack);
char			**remove_nl(char **map, int nb_lines);
//window ------------------------------------------
int				ft_window(t_game *gpack);
#endif