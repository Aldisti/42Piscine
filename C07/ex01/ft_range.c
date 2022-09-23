/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 12:22:07 by adi-stef          #+#    #+#             */
/*   Updated: 2022/09/22 12:42:07 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	*ptr;
	int	i;

	if (min >= max)
	{
		ptr = NULL;
		return (ptr);
	}
	i = -1;
	ptr = (int *) malloc ((max - min) * sizeof (int));
	while (++i < (max - min))
		ptr[i] = min + i;
	return (ptr);
}
/*
int	main(void)
{
	int	*ptr;
	int	min;
	int	max;
	int	i;

	min = -1;
	max = 10;
	ptr = ft_range(min, max);
	i = -1;
	while (++i < max - min)
		printf("%d\n", ptr[i]);
	free(ptr);
}
*/
