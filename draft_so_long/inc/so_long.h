/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:10:51 by wmillett          #+#    #+#             */
/*   Updated: 2023/04/18 22:10:09 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include <stdio.h>

# define ERROR2 -2

typedef  struct s_point
{
	int		x;
	int		y;
}			t_point;

typedef struct s_map
{
	char	**map;
	char	**map2;
	int		collectible;
	t_point	size;
	t_point	begin;
	t_point	end;
	int		missing_exit;
	int		missing_collectibles;
}			t_map;

//error
void	printerror(int type);
void	printerror1(int type, t_map mpack, int nb);
void	printerror2(int type, t_map mpack);
void	printerror3(int type, t_map mpack);
//main
t_map find_pos(t_map mpack);
int	ft_ismapvalid(t_map mpack);
int	count_lines(char *to_read);
int	check_ber(char *file, int argc);
//maps
int validcharacters(t_map mpack);
int	isrectangle(t_map mpack);
int	walls(t_map mpack);
int	objects(t_map mpack);
t_map check_path(t_map mpack, t_point cur);
//utils
void mmfree(t_map mpack);
void mfree(t_map mpack);
int	ft_strchr_count(t_map mpack, char *line, char c);
t_map duplicate_map(t_map mpack);
char	**remove_nl(char **map, int nb_lines);
#endif