/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 16:17:03 by adi-stef          #+#    #+#             */
/*   Updated: 2022/09/12 14:28:20 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_put_comb(char c[9], int n)
{
	int	i;

	i = n - 1;
	if (c[i] > '0' + i)
	{
		write(1, ", ", 2);
	}
	write(1, c, n);
}

void	ft_print_combn(int n)
{
	int		i;
	char	c[9];
	char	last;

	c[0] = '0';
	i = 0;
	while (i >= 0)
	{
		if (c[i] > '9')
		{
			i--;
			c[i]++;
		}
		else if (i < n - 1)
		{
			last = c[i++];
			c[i] = last + 1;
		}
		else if (i == n - 1)
		{
			ft_put_comb(c, n);
			c[i]++;
		}
	}
}
