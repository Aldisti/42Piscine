/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 10:28:22 by adi-stef          #+#    #+#             */
/*   Updated: 2022/09/29 10:38:10 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*ptr;
	int	i;

	ptr = (int *) malloc (length * sizeof (int));
	if (ptr == 0)
		return (ptr);
	i = -1;
	while (++i < length)
		ptr[i] = (*f)(tab[i]);
	return (ptr);
}
/*
#include <stdio.h>
int	main(void)
{
	int	a[] = {1, 2, 3, 4, 5, 6};
	int	*p;
	int	i;

	p = ft_map(a, 6, &ft_add);
	i = -1;
	while (++i < 6)
		printf("%d\n", p[i]);
	free(p);
}
*/
