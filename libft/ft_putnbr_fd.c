/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_nb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xsaulnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 10:55:58 by xsaulnie          #+#    #+#             */
/*   Updated: 2021/05/21 11:03:19 by xsaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	un;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		un = -n;
	}
	else
		un = n;
	if (un < 10)
		ft_putchar_fd(un + '0', fd);
	else
	{
		ft_putnbr_fd(un / 10, fd);
		ft_putchar_fd((un % 10) + '0', fd);
	}
}
