/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:55:11 by wmillett          #+#    #+#             */
/*   Updated: 2023/05/24 13:22:34 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	printerror_pre(int type)
{
	write(2, "\033[1;31m", 7);
	printf("Error\n");
	if (type == 1)
		printf("Please include a 'ber' file.\n");
	else if (type == 2)
		printf("Please only include one file.\n");
	else if (type == 3)
		printf("Included file is not a 'ber' file.\n");
	else if (type == 4)
		printf("Failed to open your map file.\n");
	else
		printf("Unknown error.\n");
	write(2, "\033[0m", 4);
	exit(0);
}

void	printerror_mem(int type, t_game *gpack)
{
	write(2, "\033[1;31m", 7);
	printf("Error\n");
	if (type == 1)
	{
		printf("Memory allocation failed for (t_game*).\n");
		free(gpack);
	}
	else if (type == 2)
	{
		printf("Failed to read your file.\n");
		free(gpack);
	}
	else if (type == 3)
	{
		printf("Memory allocation failed for (char*/char**).\n");
		mfree(gpack);
	}
	write(2, "\033[0m", 4);
	exit(1);
}

void	printerror_pars(int type, t_game *gpack, int nb)
{
	write(2, "\033[1;31m", 7);
	printf("Error\n");
	if (type == 1)
	{
		printf("Your map contains invalid characters.\n");
		mfree(gpack);
	}
	if (type == 2)
	{
		printf("Your map has %i starting positions instead of 1.\n", nb);
		mfree(gpack);
	}
	if (type == 3)
	{
		printf("Your map has %i exits instead of 1.\n", nb);
		mfree(gpack);
	}
	if (type == 4)
	{
		printf("Your map needs at least one collectible.\n");
		mfree(gpack);
	}
	write(2, "\033[0m", 4);
	exit(0);
}

void	printerror_pars2(int type, t_game *gpack)
{
	write(2, "\033[1;31m", 7);
	printf("Error\n");
	if (type == 4)
	{
		printf("Your map is not a rectangle.\n");
		mfree(gpack);
	}
	else if (type == 6)
	{
		printf("Your map format is too small.\n");
		mfree(gpack);
	}
	else if (type == 7)
	{
		printf("Your map is not surrounded by walls.\n");
		mfree(gpack);
	}
	else if (type == 8)
	{
		printf("Your map format is too big.\n");
		mfree(gpack);
	}
	write(2, "\033[0m", 4);
	exit(0);
}

void	printerror_pars3(int type, t_game *gpack)
{
	write(2, "\033[1;31m", 7);
	printf("Error\n");
	if (type == 7)
	{
		printf("You can't access the end of the ");
		printf("level from your starting position.\n");
		allfree(gpack, 0);
	}
	else if (type == 8)
	{
		printf("You can't access '%i' ", gpack->mpack.missing_collectibles);
		printf("collectible(s) from your starting position.\n");
		allfree(gpack, 0);
	}
	else if (type == 9)
	{
		printf("Failed to locate all objects within your map.\n");
		allfree(gpack, 0);
	}
	write(2, "\033[0m", 4);
	exit(0);
}
