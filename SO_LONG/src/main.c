/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:46:19 by wmillett          #+#    #+#             */
/*   Updated: 2023/05/23 20:37:29 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static t_map	find_pos(t_map mpack)
{
	int	i;
	int	n;

	i = 0;
	while (i < mpack.size.y)
	{
		n = 0;
		while (n < mpack.size.x)
		{
			if (mpack.map[i][n] == 'P')
			{
				mpack.begin.x = n;
				mpack.begin.y = i;
			}
			if (mpack.map[i][n] == 'E')
			{
				mpack.end.x = n;
				mpack.end.y = i;
			}
			n++;
		}
		i++;
	}
	return (mpack);
}

static int	ft_ismapvalid(t_game *gpack)
{
	if (validcharacters(gpack->mpack, 0, 0, 0) == ERROR)
		printerror_pars(1, gpack, 0);
	gpack->mpack.size.x = isrectangle(gpack->mpack);
	if (gpack->mpack.size.x == ERROR)
		printerror_pars2(4, gpack);
	if (gpack->mpack.size.x == ERROR2)
		printerror_pars2(6, gpack);
	if (walls(gpack->mpack) == ERROR)
		printerror_pars2(7, gpack);
	gpack->mpack.collectible = objects(gpack, 0, 0);
	if (gpack->mpack.collectible == ERROR)
		printerror_pars3(9, gpack);
	gpack->mpack = find_pos(gpack->mpack);
	gpack->mpack = duplicate_map(gpack);
	gpack->mpack = check_path(gpack->mpack, gpack->mpack.begin);
	if (gpack->mpack.missing_exit == -1)
		printerror_pars3(7, gpack);
	if (gpack->mpack.missing_collectibles >= 1)
		printerror_pars3(8, gpack);
	gpack->cpack.pos = gpack->mpack.begin;
	return (1);
}

static int	check_ber(char *file, int argc)
{
	int		len;
	int		i;
	int		j;
	char	*ftype;

	if (argc < 2)
		printerror_pre(1);
	if (argc > 2)
		printerror_pre(2);
	j = 0;
	ftype = ".ber";
	len = ft_strlen(file);
	if (len < 4)
		printerror_pre(3);
	i = len - 4;
	while (i < len)
	{
		if (file[i] != ftype[j])
			printerror_pre(3);
		i++;
		j++;
	}
	return (1);
}

static void	get_map(t_game *gpack, int fd)
{
	int	i;

	i = 0;
	while (i < gpack->mpack.size.y)
	{
		gpack->mpack.map[i] = ft_get_next_line(fd);
		if (gpack->mpack.map[i] == NULL)
			printerror_mem(3, gpack);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		fd;
	t_game	*gpack;

	check_ber(argv[1], argc);
	fd = open(argv[1], O_RDONLY);
	check_fd(fd, gpack, 1);
	gpack = malloc(sizeof(t_game));
	if (gpack == NULL)
		printerror_mem(1, gpack);
	gpack->mpack.size.y = count_lines(fd, gpack, 0);
	gpack->mpack.map = (char **)malloc(sizeof(char *) * (gpack->mpack.size.y
				+ 1));
	if (gpack->mpack.map == NULL)
		printerror_mem(3, gpack);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	check_fd(fd, gpack, 2);
	get_map(gpack, fd);
	close(fd);
	gpack->mpack.map = remove_nl(gpack->mpack.map, gpack->mpack.size.y);
	if (ft_ismapvalid(gpack))
		ft_window(argc, argv, gpack);
	leave(gpack);
}
