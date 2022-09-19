/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 12:54:36 by adi-stef          #+#    #+#             */
/*   Updated: 2022/09/19 14:38:24 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	else if (index == 0)
		return (index);
	else if (index == 1)
		return (index);
	index = ft_fibonacci(index - 1) + ft_fibonacci(index - 2);
	return (index);
}

int	main(void)
{
	printf("%d\n", ft_fibonacci(5));
}
