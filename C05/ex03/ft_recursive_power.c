/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 12:46:20 by adi-stef          #+#    #+#             */
/*   Updated: 2022/09/22 13:41:22 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_recursive_power(int nb, int power)
{
	if (nb == 0 && power == 0)
		return (1);
	else if (power == 0)
		return (1);
	else if (power < 0)
		return (0);
	nb *= ft_recursive_power(nb, power - 1);
	return (nb);
}
/*
int	main(void)
{
	printf("%d\n", ft_recursive_power(-4, 1));
}
*/
