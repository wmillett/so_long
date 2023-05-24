/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_rend.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 16:09:53 by wmillett          #+#    #+#             */
/*   Updated: 2023/05/23 20:26:29 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	printerror_mlx(int type, t_game *gpack)
{
	write(2, "\033[1;31m", 7);
	printf("Error\n");
	if (type == 0)
	{
		printf("MLX could not be initialized.\n");
		allfree(gpack, 0);
	}
	if (type == 1)
	{
		printf("PNG image failed to load.\n");
		allfree(gpack, 1);
	}
	if (type == 2)
	{
		printf("Image allocation failed.\n");
		allfree(gpack, 1);
	}
	if (type == 3)
	{
		printf("Image failed to resize.\n");
		allfree(gpack, 1);
	}
	exit(1);
}

void	printerror_render(int type, t_game *gpack, int len)
{
	write(2, "\033[1;31m", 7);
	printf("Error\n");
	if (type == 0)
	{
		printf("Image could not be displayed.\n");
		allfree(gpack, 1);
	}
	if (type == 2)
	{
		printf("Could not allocate memory to duplicate the map.\n");
		allfree(gpack, 1);
	}
	if (type == 3)
	{
		printf("Could not allocate memory to duplicate the map.\n");
		dfree(gpack, len);
	}
	exit(1);
}
