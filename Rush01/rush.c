/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:10:51 by adi-stef          #+#    #+#             */
/*   Updated: 2022/09/18 17:41:16 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int		**ft_create_tab(int row, int col);
void	ft_free_tab(int **tab, int row);
void	ft_all_in_one(int *one, int *combs, int row);
void	ft_fill_tab(int **tab, int *values, int row, int col);
void	ft_next_comb2(int *comb, int row);
void	ft_print_tab(int **tab, int row, int col);
int		ft_check_tab(int **tab, char *str);

void	ft_print_tab(int **tab, int row, int col)
{
	puts("ft_print_tab");
	int	x;
	int	y;

	x = -1;
	while (++x < row)
	{
		y = - 1;
		while (++y < col)
		{
			write(1, &tab[x][y], 1);
			if (y < col - 1)
				write(1, " ", 1);
		}
		write(1, "\n", 1);
	}
}

void	rush(int row, int col, char *input)
{
	int	**tab;
	int	*comb;
	int	*values;
	int	end;

	end = 1;
	values = malloc(row * row * 4);
	comb = malloc(row * 4);
	comb[0] = 1;
	comb[1] = 1;
	comb[2] = 1;
	comb[3] = 1;
	tab = ft_create_tab(row, col);
	/* create last comb */
	while (comb[0] != 24 || comb[1] != 24)
	{
		ft_all_in_one(values, comb, row);
		ft_fill_tab(tab, values, row, col);
		/* create check */
		if (ft_check_tab(tab, input))
		{
			puts("Il problema é la stampa");
			ft_print_tab(tab, row, col);
			end = 0;
			break;
		}
		ft_next_comb2(comb, row);
	}
	if (end)
		write(1, "Error", 5);
	free(values);
	free(comb);
	ft_free_tab(tab, row);
}

