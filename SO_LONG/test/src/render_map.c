/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 21:37:53 by wmillett          #+#    #+#             */
/*   Updated: 2023/05/24 15:14:45 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static bool	not_wall(t_game *gpack, int move)
{
	t_point	tmp;

	tmp = gpack->cpack.pos;
	if (move == 'L')
		tmp.x -= 1;
	if (move == 'R')
		tmp.x += 1;
	if (move == 'D')
		tmp.y += 1;
	if (move == 'U')
		tmp.y -= 1;
	if (gpack->mpack.map[tmp.y][tmp.x] == '1')
		return (0);
	else
		return (1);
}

static void	exit_open(t_game *gpack)
{
	int	count;
	int	i;

	if (gpack->cpack.rtl && gpack->cpack.pos.x == gpack->mpack.end.x
		&& gpack->cpack.pos.y == gpack->mpack.end.y)
		win(gpack);
	else if (gpack->cpack.rtl)
		return ;
	i = 0;
	count = 0;
	while (i < gpack->mpack.size.y)
	{
		count += ft_strchr_count(gpack->mpack, gpack->mpack.map[i], 'C');
		i++;
	}
	if (count == 0)
	{
		mlx_delete_image(gpack->mlx, gpack->temps.door);
		gpack->temps.door = init_exit(gpack);
		mlx_image_to_window(gpack->mlx, gpack->temps.door, gpack->mpack.end.x
			* 64, gpack->mpack.end.y * 64);
		gpack->cpack.rtl = 1;
	}
}

static void	put_image(t_game *gpack, mlx_image_t *mc)
{
	gpack->temps.check = mlx_image_to_window(gpack->mlx, mc, (gpack->cpack.pos.x
				* 64), (gpack->cpack.pos.y * 64));
	check_render(gpack->temps.check, gpack);
}

mlx_image_t	*render_mc(t_game *gpack, int move)
{
	static mlx_image_t	*mc;

	if (!not_wall(gpack, move) && move != 'F')
		return (mc);
	if (move == 'L')
		gpack->cpack.pos.x -= 1;
	if (move == 'R')
		gpack->cpack.pos.x += 1;
	if (move == 'D')
		gpack->cpack.pos.y += 1;
	if (move == 'U')
		gpack->cpack.pos.y -= 1;
	if (move && move != 'F')
		mlx_delete_image(gpack->mlx, mc);
	mc = init_mc(gpack);
	put_image(gpack, mc);
	if (move != 'F'
		&& gpack->mpack.map[gpack->cpack.pos.y][gpack->cpack.pos.x] == 'C')
		render_items(gpack, 0);
	else if (move == 'F')
		render_items(gpack, 'F');
	exit_open(gpack);
	print_move(move);
	return (mc);
}

t_game	*render_static_map(t_game *gpack, int i)
{
	int	j;

	while (i < gpack->mpack.size.y)
	{
		j = 0;
		while (gpack->mpack.map[i][j])
		{
			if (gpack->mpack.map[i][j] == '1')
				gpack->temps.check = mlx_image_to_window(gpack->mlx,
						gpack->temps.wall, j * 64, i * 64);
			if (gpack->mpack.map[i][j] == '0' || gpack->mpack.map[i][j] == 'P'
				|| gpack->mpack.map[i][j] == 'C')
				gpack->temps.check = mlx_image_to_window(gpack->mlx,
						gpack->temps.ground, j * 64, i * 64);
			if (gpack->mpack.map[i][j] == 'E')
				gpack->temps.check = mlx_image_to_window(gpack->mlx,
						gpack->temps.door, j * 64, i * 64);
			check_render(gpack->temps.check, gpack);
			j++;
		}
		i++;
	}
	render_mc(gpack, 'F');
	return (gpack);
}
