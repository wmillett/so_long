/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:46:19 by wmillett          #+#    #+#             */
/*   Updated: 2023/04/18 22:09:55 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/types.h>
#include <stdarg.h>
#include "so_long.h"
t_map find_pos(t_map mpack)
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
	return(mpack);
}

int	ft_ismapvalid(t_map mpack)
{
	if (validcharacters(mpack) == ERROR)
		printerror1(4, mpack, 0);
	if ((mpack.size.x = isrectangle(mpack)) == ERROR)
		printerror2(4, mpack);
	if (mpack.size.x == ERROR2)
		printerror2(7, mpack);
	if (walls(mpack) == ERROR)
		printerror2(6, mpack);
	if ((mpack.collectible = objects(mpack)) == ERROR)
		return (ERROR);
	mpack = find_pos(mpack);
	mpack = duplicate_map(mpack);
	mpack = check_path(mpack, mpack.begin);
	if (mpack.missing_exit == -1)
		printerror3(7, mpack);
	if (mpack.missing_collectibles >= 1)
		printerror3(8, mpack);
	mmfree(mpack);
	return (1);
}

int	count_lines(char *to_read)
{
	char	*rd;
	int		len;
	int		fd;

	fd = open(to_read, O_RDONLY);
	len = 0;
	while (fd)
	{
		rd = get_next_line(fd);
		if (rd == NULL)
			break ;
		len++;
		free(rd);
	}
	close(fd);
	get_next_line(fd);
	return (len);
}

int	check_ber(char *file, int argc)
{
	int len;
	int i;
	int j;
	char *ftype;

	if (argc > 2)
		printerror(2);
	if (argc < 2)
		printerror(1);
	j = 0;
	ftype = ".ber";
	len = ft_strlen(file);
	if (len < 4)
		printerror(0);
	i = len - 4;
	while(i < len)
	{
		if(file[i] != ftype[j])
			printerror(0);
		i++;
		j++;
	}
	return(1);
}

int	main(int argc, char **argv)
{
	int		fd;
	int		i;
	char	*tmp;
	t_map mpack;

	check_ber(argv[1], argc);
	mpack.size.y = count_lines(argv[1]);
	mpack.map = ft_calloc(mpack.size.y, sizeof(char *));
	i = 0;
	fd = open(argv[1], O_RDONLY);
	while ((tmp = get_next_line(fd)) && i < mpack.size.y)
		mpack.map[i++] = tmp;
	free(tmp);
	close(fd);
	mpack.map = remove_nl(mpack.map, mpack.size.y);
	ft_ismapvalid(mpack);
	printf("\nIt's good\n");
	mfree(mpack);
}