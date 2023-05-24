/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_items.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:03:17 by wmillett          #+#    #+#             */
/*   Updated: 2023/05/23 20:24:00 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	print_move(int move)
{
	static int	i;

	if (move == 'F')
	{
		i = 0;
		printf("Moves: 0\n");
	}
	else if (move == 'L' || move == 'R' || move == 'U' || move == 'D')
	{
		i++;
		printf("Moves: %i\n", i);
	}
	else if (move == 'T')
		printf("Total moves: %i\n", ++i);
}

static char	*rm_item(t_game *gpack, t_point lose)
{
	int	i;
	int	j;

	i = 0;
	while (gpack->mpack.map[lose.y][i])
	{
		if (i == lose.x)
			gpack->mpack.map2[lose.y][i] = '0';
		else
			gpack->mpack.map2[lose.y][i] = gpack->mpack.map[lose.y][i];
		i++;
	}
	return (gpack->mpack.map2[lose.y]);
}

char	**render_items(t_game *gpack, int first, int i, int j)
{
	static char			**clt_map;
	static mlx_image_t	*item;

	if (first == 'F')
	{
		clt_map = gpack->mpack.map;
		item = init_item(gpack);
	}
	clt_map[gpack->cpack.pos.y] = rm_item(gpack, gpack->cpack.pos);
	mlx_delete_image(gpack->mlx, item);
	item = init_item(gpack);
	while (i < gpack->mpack.size.y)
	{
		j = 0;
		while (clt_map[i][j])
		{
			if (clt_map[i][j] == 'C')
				gpack->temps.check = mlx_image_to_window(gpack->mlx, item, j
						* 64, i * 64);
			check_render(gpack->temps.check, gpack, j++);
		}
		i++;
	}
	return (clt_map);
}
