/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_temp_extra.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:38:20 by wmillett          #+#    #+#             */
/*   Updated: 2023/05/23 20:24:26 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

mlx_image_t	*init_exit(t_game *gpack)
{
	mlx_texture_t	*exit;
	mlx_image_t		*image;
	const char		*path;
	bool			check;

	path = "./temp/door3.png";
	exit = mlx_load_png(path);
	if (exit == NULL)
		printerror_mlx(1, gpack);
	image = mlx_new_image(gpack->mlx, 64, 64);
	if (!image)
		printerror_mlx(2, gpack);
	image = mlx_texture_to_image(gpack->mlx, exit);
	check = mlx_resize_image(image, 64, 64);
	if (!check)
		printerror_mlx(3, gpack);
	mlx_delete_texture(exit);
	return (image);
}
