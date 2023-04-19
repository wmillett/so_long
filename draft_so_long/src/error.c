/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:55:11 by wmillett          #+#    #+#             */
/*   Updated: 2023/04/18 21:15:36 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	printerror(int type)
{
	printf("Error\n");
	if (type == -1)
		printf("The program failed to execute the task.\n");
	else if (type == 0)
		printf("Included file is not a 'ber' file.\n");
	else if (type == 1)
		printf("Please include a 'ber' file.\n");
	else if (type == 2)
		printf("Please only include one map file.\n");
	else if (type == 3)
		printf("Map format is invalid.\n");
	else
		printf("Unknown error.\n");
	exit(0);
}

void	printerror1(int type, t_map mpack, int nb)
{
	printf("Error\n");
	if (type == 1)
	{
		printf("Your map has %i starting positions instead of 1.\n", nb);
		mfree(mpack);
	}
	else if (type == 2)
	{
		printf("Your map has %i exits instead of 1.\n", nb);
		mfree(mpack);
	}
	else if (type == 3)
	{
		printf("Your map needs at least one collectible.\n");
		mfree(mpack);
	}
	else if (type == 4)
	{
		printf("Your map contains invalid characters.\n");
		mfree(mpack);
	}
	else
		printf("Unknown error.\n");
	exit(0);
}

void	printerror2(int type, t_map mpack)
{
	printf("Error\n");
	if (type == 4)
	{
		printf("Your map is not a rectangle.\n");
		mfree(mpack);
	}
	else if (type == 5)
	{
		printf("Could not duplicate map.\n");
		mfree(mpack);
	}
	else if (type == 6)
	{
		printf("Your map is not surrounded by walls.\n");
		mfree(mpack);
	}
	else if (type == 7)
	{
		printf("Your map format is too small.\n");
		mfree(mpack);
	}
	else
		printf("Unknown error.\n");
	exit(0);
}

void	printerror3(int type, t_map mpack)
{
	printf("Error\n");
	if (type == 7)
	{
		printf("You can't access the end of the level from your starting position.\n");
		mfree(mpack);
		mmfree(mpack);
	}
	else if (type == 8)
	{
		printf("You can't access '%i' collectible(s) from your starting position.\n", mpack.missing_collectibles);
		mfree(mpack);
		mmfree(mpack);
	}
	else
		printf("Unknown error.\n");
	exit(0);
}