/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_items.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:03:17 by wmillett          #+#    #+#             */
/*   Updated: 2023/05/24 17:50:37 by wmillett         ###   ########.fr       */
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

static void	print_items(t_game *gpack, mlx_image_t *item)
{
	int	i;
	int	j;

	i = 0;
	while (i < gpack->mpack.size.y)
	{
		j = 0;
		while (gpack->mpack.map[i][j])
		{
			if (gpack->mpack.map[i][j] == 'C')
				gpack->temps.check = mlx_image_to_window(gpack->mlx, item, j
						* 64, i * 64);
			check_render(gpack->temps.check, gpack);
			j++;
		}
		i++;
	}
}

void	render_items(t_game *gpack, int first)
{
	static mlx_image_t	*item;

	if (first == 'F')
	{
		item = init_item(gpack);
		print_items(gpack, item);
		return ;
	}
	gpack->mpack.map[gpack->cpack.pos.y][gpack->cpack.pos.x] = '0';
	mlx_delete_image(gpack->mlx, item);
	item = init_item(gpack);
	print_items(gpack, item);
}
