/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:09:43 by adi-stef          #+#    #+#             */
/*   Updated: 2022/09/18 18:13:43 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

int	**ft_create_tab(int row, int col)
{
	puts("ft_create_tab");
	int	**tab;
	int	i;

	i = -1;
	tab = malloc(col * 8);
	while (++i < col)
	{
		tab[i] = malloc(row * 4);
	}
	return (tab);
}

void	ft_fill_tab(int **tab, int *values, int row, int col)
{
	//puts("ft_fill_tab");
	int	i;
	int	j;
	int	x;

	i = -1;
	x = 0;
	while (++i < row)
	{
		j = -1;
		while (++j < col)
		{
			tab[i][j] = values[x];
			x++;
		}
	}
}

void	ft_free_tab(int **tab, int row)
{
	puts("ft_free_tab");
	int	i;

	i = -1;
	while (++i < row)
		free(tab[i]);
	free(tab);
}

int	ft_factorial(int nbr)
{
	int	i;

	i = nbr;
	while (--i > 0)
		nbr *= i;
	return (nbr);
}

