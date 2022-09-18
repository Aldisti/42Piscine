/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 12:22:36 by adi-stef          #+#    #+#             */
/*   Updated: 2022/09/18 12:35:28 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	i;

	if (nb == 0)
		return (1);
	else if (nb < 0)
		return (0);
	i = nb;
	while (--i > 0)
		nb *= i;
	return (nb);
}
/*
int	main(void)
{
	printf("%d\n", ft_iterative_factorial(30));
}
*/
