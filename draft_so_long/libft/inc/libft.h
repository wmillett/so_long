/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:21:13 by wmillett          #+#    #+#             */
/*   Updated: 2023/04/18 21:36:29 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include <sys/types.h>
# include <stdarg.h>

# define ERROR -1

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

typedef struct s_info
{
	char	*tmp;
	char	*tmp2;
	int		rv;
	size_t	len;
}			t_all;

int					ft_putchar(char c);

int					ft_putstr(char *s);

int					ft_putnbr(int n);

size_t				ft_strlen(const char *s);

char	*ft_strchr(const char *s, int c);

char	*ft_strdup(char *src);

//printf
int	ft_putadr(void *n);

int	ft_printf(const char *s, ...);

int	ft_unsigned_putnbr(unsigned int n);

int	ft_puthex(unsigned int nb);

int	ft_puthex_toupper(unsigned int nb);


//get_next_line
char		*get_next_line(int fd);

char		ft_find(char *s);

char		*ft_minisplit(char *s, size_t *len);

void		ft_bzero(void *b, size_t len);

void		*ft_sfree(void *str);

void		*ft_calloc(size_t count, size_t size);

char		*ft_strjoin(char *s1, char *s2);

#endif