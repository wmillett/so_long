/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:31:39 by wmillett          #+#    #+#             */
/*   Updated: 2023/05/23 18:43:47 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_minisplit(char *s, size_t *len)
{
	char	*new;
	size_t	i;

	i = 0;
	while (s[i])
		if (s[i++] == '\n')
			break ;
	new = ft_calloc(i, sizeof(char));
	if (!new)
		return (NULL);
	*len = i;
	while (i--)
		new[i] = s[i];
	return (new);
}

char	ft_find(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return ('\n');
		i++;
	}
	return ('0');
}

char	*ft_get_next_line(int fd)
{
	static char	*line;
	t_all		t_var;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (line = ft_sfree(line));
	if (!line)
		line = ft_calloc(1, sizeof(char));
	t_var.tmp = ft_calloc(BUFFER_SIZE, sizeof(char));
	t_var.rv = 0;
	while (ft_find(line) == '0')
	{
		ft_bzero(t_var.tmp, BUFFER_SIZE + 1);
		t_var.rv = read(fd, t_var.tmp, BUFFER_SIZE);
		if (t_var.rv <= 0)
			break ;
		line = ft_strjoin(line, t_var.tmp);
	}
	ft_sfree(t_var.tmp);
	if (t_var.rv == -1 || *line <= 0)
		return (line = ft_sfree(line), NULL);
	t_var.tmp = ft_minisplit(line, &t_var.len);
	t_var.tmp2 = line;
	line = ft_strjoin(NULL, line + t_var.len);
	return (ft_sfree(line), t_var.tmp2);
}
