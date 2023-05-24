/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:08:59 by wmillett          #+#    #+#             */
/*   Updated: 2023/02/09 16:30:30 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(char *s)
{
	int	i;
	int	check;

	i = 0;
	if (!s)
	{
		check = write(1, "(null)", 6);
		if (check == ERROR)
			return (ERROR);
		return (6);
	}
	while (!(s[i] == 0))
	{
		check = write(1, &s[i], 1);
		if (check == ERROR)
			return (ERROR);
		i++;
	}
	return ((int)ft_strlen(s));
}
