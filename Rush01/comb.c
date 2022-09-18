/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:10:28 by adi-stef          #+#    #+#             */
/*   Updated: 2022/09/18 18:08:57 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

void	ft_next_comb(int *comb, int row);
void	ft_next_comb(int *comb, int row);
void	ft_all_in_one(int *one, int *combs, int row);
void	ft_next_comb2(int *comb, int row);
int		ft_factorial(int nbr);
int		ft_numb_diff(int *comb, int row);

int	*ft_possible_combo(int *comb, int ncomb, int row)
{
	int	i;

	i = 0;
	while (i < row)
	{
		comb[i] = 1 + i;
		i++;
	}
	while (comb[0] != row || comb[1] != row)
	{
		if (ft_numb_diff(comb, row))
		{
			ncomb--;
			if (ncomb == 0)
				return (comb);
		}
		ft_next_comb(comb, row);
	}
	return (0);
}

int	ft_numb_diff(int *comb, int row)
{
	int	a;
	int	b;
	int	u;

	a = 0;
	while (a < row)
	{
		u = 0;
		b = 0;
		while (b < row)
		{
			if (comb[a] == comb[b])
				u++;
			b++;
		}
		if (u > 1)
			return (0);
		a++;
	}
	return (1);
}

void	ft_next_comb(int *comb, int row)
{
	int	i;

	i = 1;
	if (comb[row - 1] != row)
		comb[row - 1]++;
	else
	{
		while (i < row)
		{
			if (comb[row - 1 - i] != row)
			{
				comb[row - 1 - i]++;
				while (i > 0)
				{
					comb[row - i] = 1;
					i--;
				}
				break ;
			}
			i++;
		}
	}
}

void	ft_all_in_one(int *one, int *combs, int row)
{
	int	*temp;
	int	i;
	int	j;

	i = 0;
	temp = malloc(row * 4);
	while (i < row)
	{
		j = 0;
		temp = ft_possible_combo(temp, combs[i], row);
		while (j < row)
		{
			one[j + i * row] = temp[j];
			j++;
		}
		i++;
	}
	free(temp);
}

void	ft_next_comb2(int *comb, int row)
{
	int	i;

	i = 1;
	if (comb[row - 1] != ft_factorial(row))
		comb[row - 1]++;
	else
	{
		while (i < row)
		{
			if (comb[row - 1 - i] != ft_factorial(row))
			{
				comb[row - 1 - i]++;
				while (i > 0)
				{
					comb[row - i] = 1;
					i--;
				}
				break ;
			}
			i++;
		}
	}
}

