/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:10:38 by wmillett          #+#    #+#             */
/*   Updated: 2023/02/10 19:03:43 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putnbr_neg(int n)
{
	int	check;

	check = 0;
	if (n == -2147483648)
	{
		check = write(1, "-2147483648", 11);
		if (check == ERROR)
			return (ERROR);
		return (-2);
	}
	else if (n < 0 && n != -2147483648)
	{
		check = ft_putchar('-');
		if (check == ERROR)
			return (ERROR);
		n *= -1;
		return (1);
	}
	return (0);
}

static int	ft_numlen(long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	int	len;
	int	check;

	len = ft_numlen(n);
	check = ft_putnbr_neg(n);
	if (check == ERROR)
		return (ERROR);
	else if (check == 1)
		n *= -1;
	else if (check == -2)
		return (11);
	if (!(n >= 0 && n < 10))
	{
		check = ft_putnbr(n / 10);
		if (check == ERROR)
			return (ERROR);
		check = ft_putnbr(n % 10);
		if (check == ERROR)
			return (ERROR);
	}
	else
		check = ft_putchar(n + 48);
	if (check == ERROR)
		return (ERROR);
	return (len);
}
