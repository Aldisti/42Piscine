/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 12:37:33 by adi-stef          #+#    #+#             */
/*   Updated: 2022/09/22 12:54:31 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	if (min >= max)
	{
		range = NULL;
		return (-1);
	}
	i = -1;
	while (++i < (max - min))
		range[0][i] = min + i;
	return (i);
}
/*
int	main(void)
{
	int	*ptr;
	int	min;
	int	max;
	int	i;

	min = 10;
	max = 10;
	ptr = (int *) malloc ((max - min) * sizeof (int));
	printf("%d\n", ft_ultimate_range(&ptr, min, max));
	i = -1;
	while (++i < max - min)
		printf("%d\n", ptr[i]);
	free(ptr);	
}
*/
