/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:32:56 by wmillett          #+#    #+#             */
/*   Updated: 2023/01/25 19:20:02 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	n;

	if (!s)
		return (NULL);
	n = ft_strlen(s);
	i = 0;
	while (i <= n)
	{
		if (((char *)s)[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}
