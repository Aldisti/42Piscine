/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 10:44:33 by adi-stef          #+#    #+#             */
/*   Updated: 2022/09/29 18:24:00 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int	*tab, int length, int (*f)(int, int))
{
	int	i;
	int	j;
	int	c;

	c = 1;
	j = 0;
	i = -1;
	while (++i < length - 1)
	{
		if ((*f)(tab[i], tab[i + 1]) < 0)
			j--;
		else if ((*f)(tab[i], tab[i + 1]) > 0)
			j++;
		else
			c++;
	}
	if (j == length - c || - j == length - c || length == 0)
		return (1);
	return (0);
}
/*
int	ft_cmp(int a, int b)
{
	return (a - b);
}
#include <stdio.h>
int	main(void)
{
	int	a[] = {};

	printf("%d\n", ft_is_sort(a, 0, &ft_cmp));
}
*/
