/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:42:54 by adi-stef          #+#    #+#             */
/*   Updated: 2022/09/23 14:39:17 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	while (i <= nb / i)
	{
		if (i * i == nb)
			return (i);
		i += 1;
	}
	return (0);
}
/*
int	main(void)
{
	printf("%d\n", ft_sqrt(2147483647));
	printf("%d\n", ft_sqrt(1));
	printf("%d\n", ft_sqrt(0));
	printf("%d\n", ft_sqrt(4));
}
*/
