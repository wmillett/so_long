/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:17:56 by wmillett          #+#    #+#             */
/*   Updated: 2023/05/24 15:13:39 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_render(int32_t check, t_game *gpack)
{
	if (check == ERROR)
		printerror_render(0, gpack, 0);
}

void	check_fd(int fd, t_game *gpack, int type)
{
	if (fd < 0 || fd > INT_MAX)
	{
		if (type == 1)
			printerror_pre(4);
		else if (type == 2)
			printerror_mem(4, gpack);
	}
}
