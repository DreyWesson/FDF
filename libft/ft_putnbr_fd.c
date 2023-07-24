/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conyejib <conyejib@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 07:54:07 by conyejib          #+#    #+#             */
/*   Updated: 2022/06/02 07:54:07 by conyejib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_arith(int nb, int fd)
{
	int		digits;
	int		n;
	long	t;

	n = nb;
	digits = 0;
	t = 1;
	while (n > 0)
	{
		t *= 10;
		digits++;
		n /= 10;
	}
	while (digits > 0)
	{
		n = ((nb % t) / (t / 10));
		ft_putchar_fd(n + '0', fd);
		t /= 10;
		digits--;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		n *= -1;
		ft_putchar_fd('-', fd);
	}
	if (n >= 0 && n < 10)
	{
		ft_putchar_fd(n + '0', fd);
	}
	if (n >= 10)
	{
		ft_arith(n, fd);
	}
}
