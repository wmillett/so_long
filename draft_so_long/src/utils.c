/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 19:14:52 by wmillett          #+#    #+#             */
/*   Updated: 2023/04/18 21:32:38 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void mmfree(t_map mpack)
{
	int i;

	i = 0;
	if (mpack.map2)
	{
		while(i < mpack.size.y)
			free(mpack.map2[i++]);
		free(mpack.map2);
	}
}

void mfree(t_map mpack)
{
	int i;

	i = 0;
	while(i < mpack.size.y)	
	{
		free(mpack.map[i]);
		mpack.map[i] = 0;
		i++;
	}
	free(mpack.map);
}

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

t_map duplicate_map(t_map mpack)
{
	int i;

	i = 0;
	mpack.map2 = ft_calloc(mpack.size.y, sizeof(char *));
	if (mpack.map2 == NULL)
	{
		free(mpack.map2);
		mpack.map2 = 0;
		return(mpack);
	}
	else
	{	
		while(i < mpack.size.y)
		{
			mpack.map2[i] = ft_strdup(mpack.map[i]);
			i++;
		}
	}
	return(mpack);
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
