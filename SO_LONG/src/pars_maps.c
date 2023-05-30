/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:00:11 by wmillett          #+#    #+#             */
/*   Updated: 2023/05/30 15:12:29 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	validcharacters(t_map mpack, int j, int i, int k)
{
	char	*objects;
	int		check;

	objects = "10PEC";
	while (i < mpack.size.y)
	{
		j = 0;
		while (mpack.map[i][j])
		{
			check = 0;
			k = 0;
			while (objects[k])
			{
				if (objects[k] == mpack.map[i][j])
					check++;
				k++;
			}
			if (check == 0)
				return (ERROR);
			j++;
		}
		i++;
	}
	return (1);
}

int	isrectangle(t_map mpack)
{
	int	j;
	int	tmp;
	int	last;
	int	t;
	int	x;

	t = 0;
	x = 0;
	last = ft_strlen(mpack.map[0]);
	if (mpack.size.y < 3 || last < 3)
		return (ERROR2);
	j = 1;
	while (j < mpack.size.y)
	{
		tmp = ft_strlen(mpack.map[j]);
		if (tmp != last)
			return (ERROR);
		j++;
	}
	if ((mpack.size.y <= 3 && last < 5) || (mpack.size.y < 5 && last <= 3))
		return (ERROR2);
	return (last);
}

int	walls(t_map mpack)
{
	int	j;
	int	last;

	j = 0;
	while (mpack.map[0][j])
		if (mpack.map[0][j++] != '1')
			return (ERROR);
	last = ft_strlen(mpack.map[0]);
	last--;
	j = 1;
	while (j < mpack.size.y)
	{
		if (mpack.map[j][0] != '1')
			return (ERROR);
		if (mpack.map[j++][last] != '1')
			return (ERROR);
	}
	j = 0;
	while (mpack.map[mpack.size.y - 1][j])
		if (mpack.map[mpack.size.y - 1][j++] != '1')
			return (ERROR);
	return (1);
}

int	objects(t_game *gpack, int i, int j)
{
	char	*objects;
	int		count;

	objects = "PEC";
	while (objects[i])
	{
		count = 0;
		j = -1;
		while (++j < gpack->mpack.size.y)
			count += ft_strchr_count(gpack->mpack,
					gpack->mpack.map[j],
					objects[i]);
		if (count != 1 && objects[i] == 'P')
			printerror_pars(2, gpack, count);
		if (count != 1 && objects[i] == 'E')
			printerror_pars(3, gpack, count);
		if (objects[i] == 'C' && count <= 0)
			printerror_pars(4, gpack, count);
		else if (objects[i] == 'C' && count > 0)
			return (count);
		i++;
	}
	return (ERROR);
}

t_map	check_path(t_map mpack, t_point cur)
{
	static int	nb_col;
	static int	exit;

	if (mpack.map2[cur.y][cur.x] == '1' || mpack.map2[cur.y][cur.x] == 'X')
		return (mpack);
	if (mpack.map2[cur.y][cur.x] == 'E')
		exit = 1;
	if (mpack.map2[cur.y][cur.x] == 'C')
		nb_col++;
	mpack.map2[cur.y][cur.x] = 'X';
	check_path(mpack, (t_point){cur.x - 1, cur.y});
	check_path(mpack, (t_point){cur.x + 1, cur.y});
	check_path(mpack, (t_point){cur.x, cur.y - 1});
	check_path(mpack, (t_point){cur.x, cur.y + 1});
	if (exit != 1)
		mpack.missing_exit = -1;
	if (nb_col != mpack.collectible)
		mpack.missing_collectibles = mpack.collectible - nb_col;
	return (mpack);
}
