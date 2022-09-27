/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 12:37:33 by adi-stef          #+#    #+#             */
/*   Updated: 2022/09/27 11:14:13 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*temp;
	int	i;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	temp = (int *) malloc ((max - min) * sizeof (int));
	if (!temp)
		return (-1);
	i = -1;
	while (++i < (max - min))
		temp[i] = min + i;
	*range = temp;
	return (i);
}
/*
int	main(void)
{
	int	*ptr;
	int	min;
	int	max;
	int	i;

	min = -10;
	max = 10;
	printf("i: %d\n", ft_ultimate_range(&ptr, min, max));
	i = -1;
	while (++i < max - min)
		printf("%d\n", ptr[i]);
	free(ptr);	
}
*/
