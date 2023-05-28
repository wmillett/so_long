/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 16:34:46 by wmillett          #+#    #+#             */
/*   Updated: 2023/05/24 15:14:22 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	ft_mchook(mlx_key_data_t k, void *param)
{
	t_game	*gpack;
	int		move;

	gpack = param;
	if (k.key == MLX_KEY_RIGHT && k.action == 1)
		move = 'R';
	if (k.key == MLX_KEY_LEFT && k.action == 1)
		move = 'L';
	if (k.key == MLX_KEY_UP && k.action == 1)
		move = 'U';
	if (k.key == MLX_KEY_DOWN && k.action == 1)
		move = 'D';
	if (move && k.action == 1)
		render_mc(param, move);
	if (k.key == MLX_KEY_ESCAPE && k.action == 1)
	{
		mlx_terminate(gpack->mlx);
		leave(gpack);
	}
}

static t_game	*init_map(t_game *gpack)
{
	gpack->temps.door = init_door(gpack);
	gpack->temps.wall = init_wall(gpack);
	gpack->temps.ground = init_ground(gpack);
	gpack->temps.item = init_item(gpack);
	gpack->temps.mc = init_mc(gpack);
	gpack->temps.check = 0;
	render_static_map(gpack, 0);
	return (gpack);
}

int	ft_window(t_game *gpack)
{
	gpack->mlx = mlx_init(gpack->mpack.size.x * 64, gpack->mpack.size.y * 64,
			"SO_LONG by WMILLETT", true);
	if (!gpack->mlx)
		printerror_mlx(0, gpack);
	gpack = init_map(gpack);
	mlx_key_hook(gpack->mlx, &ft_mchook, gpack);
	mlx_loop(gpack->mlx);
	mlx_terminate(gpack->mlx);
	leave(gpack);
	return (EXIT_SUCCESS);
}
