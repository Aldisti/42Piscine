/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:45:20 by adi-stef          #+#    #+#             */
/*   Updated: 2022/09/19 14:50:29 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_is_prime(int nb)
{
	int	i;

	i = 1;
	while (++i <= (nb / i))
		if (nb % i == 0 && i != nb)
			return (0);
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (ft_is_prime(nb))
		return (nb);
	else
	{
		if (nb % 2)
			ft_find_next_prime(nb + 2);
		else
			ft_find_next_prime(nb + 1);
	}
}
