/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 16:03:18 by wmillett          #+#    #+#             */
/*   Updated: 2023/05/23 20:23:43 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	mmfree(t_game *gpack)
{
	free(gpack->mpack.map2);
	free(gpack->mpack.map);
	free(gpack);
}

void	mfree(t_game *gpack)
{
	free(gpack->mpack.map);
	free(gpack);
}

void	dfree(t_game *gpack, int len)
{
	while (--len)
		free(gpack->mpack.map2[len]);
	free(gpack->mpack.map2);
	free(gpack->mpack.map);
	free(gpack);
}

void	allfree(t_game *gpack, bool term)
{
	int	i;

	if (term)
		mlx_terminate(gpack->mlx);
	i = 0;
	while (i < gpack->mpack.size.y)
		free(gpack->mpack.map2[i++]);
	free(gpack->mpack.map);
	free(gpack);
}
