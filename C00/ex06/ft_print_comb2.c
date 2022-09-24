/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 11:54:11 by adi-stef          #+#    #+#             */
/*   Updated: 2022/09/20 15:29:13 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print(int n1, int n2)
{
	char	num;

	num = 48 + n1 / 10;
	write(1, &num, 1);
	num = 48 + n1 % 10;
	write(1, &num, 1);
	write(1, " ", 1);
	num = 48 + n2 / 10;
	write(1, &num, 1);
	num = 48 + n2 % 10;
	write(1, &num, 1);
	if (n1 != 98)
		write(1, ", ", 2);
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = -1;
	while (++i <= 99)
	{
		j = i;
		while (++j <= 99)
			ft_print(i, j);
	}
}
/*
int	main(void)
{
	ft_print_comb2();
}
*/
