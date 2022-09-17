/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 11:54:11 by adi-stef          #+#    #+#             */
/*   Updated: 2022/09/14 11:58:16 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print(int *arr)
{
	int	temp;

	temp = (arr[0] / 10) + 48;
	write(1, &temp, 1);
	temp = (arr[0] % 10) + 48;
	write(1, &temp, 1);
	write(1, " ", 1);
	temp = (arr[1] / 10) + 48;
	write(1, &temp, 1);
	temp = (arr[1] % 10) + 48;
	write(1, &temp, 1);
	if (arr[0] != 98)
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb2(void)
{
	int	arr[2];

	while (arr[0] < 98)
	{
		if (arr[1] == 99)
		{
			arr[0] += 1;
			arr[1] = arr[0];
		}
		arr[1]++;
		ft_print(arr);
	}
}
