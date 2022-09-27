/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:21:34 by adi-stef          #+#    #+#             */
/*   Updated: 2022/09/27 15:40:51 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putnbr(int n)
{
	char	c;

	if (n < 0)
	{
		write(1, "-", 1);
		ft_putnbr((n / 10) * -1);
		c = (n % 10 * -1 + 48);
		write(1, &c, 1);
	}
	else if (n > 0)
	{
		ft_putnbr(n / 10);
		c = (n % 10 + 48);
		write(1, &c, 1);
	}
}

void	ft_print(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
	write(1, "\n", 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = -1;
	while (par[++i].str)
	{
		ft_print(par[i].str);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		ft_print(par[i].copy);
	}
}
