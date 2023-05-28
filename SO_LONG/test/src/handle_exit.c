/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:37:04 by wmillett          #+#    #+#             */
/*   Updated: 2023/05/23 20:24:32 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	leave(t_game *gpack)
{
	allfree(gpack, 0);
	write(2, "\033[0;32m", 7);
	printf("Program exited successfully.\n");
	write(2, "\033[0m", 4);
	exit(0);
}

void	win(t_game *gpack)
{
	allfree(gpack, 1);
	write(2, "\033[1;34m", 7);
	print_move('T');
	write(2, "\033[0m", 4);
	write(2, "\033[0;32m", 7);
	printf("Congratulations, you escaped!\n");
	write(2, "\033[0m", 4);
	exit(0);
}
