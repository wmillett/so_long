/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 19:14:52 by wmillett          #+#    #+#             */
/*   Updated: 2023/05/23 20:22:18 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_strchr_count(t_map mpack, char *line, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (i < mpack.size.x)
	{
		if (line[i] == c)
			count++;
		i++;
	}
	return (count);
}

t_map	duplicate_map(t_game *gpack)
{
	int	i;

	i = 0;
	gpack->mpack.map2 = ft_calloc(gpack->mpack.size.y, sizeof(char *));
	if (gpack->mpack.map2 == NULL)
		printerror_pars3(10, gpack);
	else
	{
		while (i < gpack->mpack.size.y)
		{
			gpack->mpack.map2[i] = ft_strdup(gpack->mpack.map[i],
					gpack->mpack.map2[i]);
			if (gpack->mpack.map2[i] == NULL)
				printerror_render(3, gpack, i);
			i++;
		}
	}
	return (gpack->mpack);
}

char	**remove_nl(char **map, int nb_lines)
{
	int		i;
	int		j;
	char	**newmap;

	newmap = map;
	i = 0;
	while (i < nb_lines)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '\n')
				newmap[i][j] = '\0';
			j++;
		}
		i++;
	}
	return (newmap);
}
