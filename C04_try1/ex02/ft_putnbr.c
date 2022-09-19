/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 12:11:19 by adi-stef          #+#    #+#             */
/*   Updated: 2022/09/19 15:09:40 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print(int num, int div)
{
	int	temp;

	temp = num / div;
	num -= temp * div;
	div /= 10;
	temp += 48;
	write(1, &temp, 1);
	if (div != 0)
	{
		ft_print(num, div);
	}
}

int	ft_ncifre(int num)
{
	int	div;

	div = 1000000000;
	while (div > num)
		div /= 10;
	return (div);
}

void	ft_putnbr(int nb)
{
	if (nb == 0 || nb == -2147483648)
	{
		if (nb == 0)
		{
			write(1, "0", 1);
		}
		else
		{
			write(1, "-2147483648", 11);
		}
	}
	else if (nb > 0)
	{
		ft_print(nb, ft_ncifre(nb));
	}
	else
	{
		write(1, "-", 1);
		ft_print(-nb, ft_ncifre(-nb));
	}
}
