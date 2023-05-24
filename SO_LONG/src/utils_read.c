/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:50:14 by wmillett          #+#    #+#             */
/*   Updated: 2023/05/23 20:23:38 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include <fcntl.h>
#include <limits.h>
#include <stdarg.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

static void	check_fail_read(int rv, t_game *gpack)
{
	if (rv < 0)
		printerror_mem(2, gpack);
}

int	count_lines(int fd, t_game *gpack, int num_lines)
{
	char	*buffer;
	char	previous_char;
	int		num_bytes_read;
	int		prev_bytes;

	buffer = malloc(sizeof(char *));
	previous_char = '\0';
	prev_bytes = 0;
	num_bytes_read = 0;
	while (1)
	{
		num_bytes_read = read(fd, buffer, 1);
		check_fail_read(num_bytes_read, gpack);
		if (!num_bytes_read)
		{
			if (prev_bytes != '\0' && previous_char != '\n')
				num_lines++;
			break ;
		}
		if (buffer[0] == '\n')
			num_lines++;
		previous_char = buffer[0];
		prev_bytes = num_bytes_read;
	}
	return (free(buffer), num_lines);
}
