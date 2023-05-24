/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_temp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 21:38:03 by wmillett          #+#    #+#             */
/*   Updated: 2023/05/23 20:24:22 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

mlx_image_t	*init_door(t_game *gpack)
{
	mlx_texture_t	*door;
	mlx_image_t		*image;
	const char		*path;
	bool			check;

	path = "./temp/door1.png";
	door = mlx_load_png(path);
	if (door == NULL)
		printerror_mlx(1, gpack);
	image = mlx_new_image(gpack->mlx, 64, 64);
	if (!image)
		printerror_mlx(2, gpack);
	image = mlx_texture_to_image(gpack->mlx, door);
	check = mlx_resize_image(image, 64, 64);
	if (!check)
		printerror_mlx(3, gpack);
	mlx_delete_texture(door);
	return (image);
}

mlx_image_t	*init_wall(t_game *gpack)
{
	mlx_texture_t	*wall;
	mlx_image_t		*image;
	const char		*path;
	bool			check;

	path = "./temp/wall3.png";
	wall = mlx_load_png(path);
	if (wall == NULL)
		printerror_mlx(1, gpack);
	image = mlx_new_image(gpack->mlx, 64, 64);
	if (!image)
		printerror_mlx(2, gpack);
	image = mlx_texture_to_image(gpack->mlx, wall);
	check = mlx_resize_image(image, 64, 64);
	if (!check)
		printerror_mlx(3, gpack);
	mlx_delete_texture(wall);
	return (image);
}

mlx_image_t	*init_ground(t_game *gpack)
{
	mlx_texture_t	*ground;
	mlx_image_t		*image;
	const char		*path;
	bool			check;

	path = "./temp/ground1.png";
	ground = mlx_load_png(path);
	if (ground == NULL)
		printerror_mlx(1, gpack);
	image = mlx_new_image(gpack->mlx, 64, 64);
	if (!image)
		printerror_mlx(2, gpack);
	image = mlx_texture_to_image(gpack->mlx, ground);
	check = mlx_resize_image(image, 64, 64);
	if (!check)
		printerror_mlx(3, gpack);
	mlx_delete_texture(ground);
	return (image);
}

mlx_image_t	*init_mc(t_game *gpack)
{
	mlx_texture_t	*mc;
	mlx_image_t		*image;
	const char		*path;
	bool			check;

	path = "./temp/MCW1.png";
	mc = mlx_load_png(path);
	if (mc == NULL)
		printerror_mlx(1, gpack);
	image = mlx_new_image(gpack->mlx, 64, 64);
	if (!image)
		printerror_mlx(2, gpack);
	image = mlx_texture_to_image(gpack->mlx, mc);
	check = mlx_resize_image(image, 64, 64);
	if (!check)
		printerror_mlx(3, gpack);
	mlx_delete_texture(mc);
	return (image);
}

mlx_image_t	*init_item(t_game *gpack)
{
	mlx_texture_t	*item;
	mlx_image_t		*image;
	const char		*path;
	bool			check;

	path = "./temp/item2.png";
	item = mlx_load_png(path);
	if (item == NULL)
		printerror_mlx(1, gpack);
	image = mlx_new_image(gpack->mlx, 64, 64);
	if (!image)
		printerror_mlx(2, gpack);
	image = mlx_texture_to_image(gpack->mlx, item);
	check = mlx_resize_image(image, 64, 64);
	if (!check)
		printerror_mlx(3, gpack);
	mlx_delete_texture(item);
	return (image);
}
