/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 13:32:49 by adi-stef          #+#    #+#             */
/*   Updated: 2022/09/18 18:57:19 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_check_row(int **tab, int x, int y, char *index)
{
	//puts("ft_check_row");
	int	c;
	int	j;

	c = 1;
	j = 0;	
	while (++y < 4)
	{
		if (tab[x][j] < tab[x][y])
		{
			j = y;
			c++;
		}
	}
	if (c + 48 != index[0])
		return (0);
	printf("R1: %d = %c\n", c, index[0]);
	c = 1;
	j = y++;
	while (--y >= 0)
	{
		if (tab[x][y] > tab[x][j])
		{
			j = y;
			c++;
		}
	}
	if (c + 48 != index[1])
		return (0);
	printf("R2: %d = %c\n", c, index[1]);
	puts("row ok");
	return (1);
}

int	ft_check_col(int **tab, int x, int y, char *index) /* x = -1 */
{
	//puts("ft_check_col");
	int	c;
	int	j;

	c = 1;
	j = 0;
	while (++x < 4)
	{
		if (tab[j][y] < tab[x][y])
		{
			j = x;
			c++;
		}
	}
	printf("C1: %d = %c\n", c, index[0]);
	if (c + 48 != index[0]) /* up */
		return (0);
	c = 1;
	j = x++;
	while (--x >= 0)
	{
		if (tab[x][y] > tab[j][y])
		{
			j = x;
			c++;
		}
	}
	printf("C2: %d = %c\n", c, index[0]);
	if (c + 48 != index[1]) /* down */
		return (0);
	puts("Tutte le col ok");
	return (1);
}

int	ft_check_double(int **tab, int y)
{
	int	x;
	int	j;

	while (++y < 3)
	{
		x = -1;
		while (++x < 3)
		{
			j = x;
			while (++j < 4)
				if (tab[x][y] == tab[j][y])
					return (0);
		}
	}
	return (1);
}

int	ft_check_tab(int **tab, char *str)
{
	//puts("ft_check_tab");
	char	index[2];
	int		i;
	int		c;

	//if (ft_check_double(tab, -1) == 0)
		//return (0);
	c = 0;
	i = -1;
	while (++i < 4)
	{
		index[0] = str[16 + i * 2];
		index[1] = str[24 + i * 2];
		if (ft_check_row(tab, i, -1, index))
			c++;
	}
	i = -1;
	while (++i < 4)
	{
		index[0] = str[i * 2];
		index[1] = str[8 + i * 2];
		if (ft_check_col(tab, -1, i, index))
			c++;
	}
	printf("C == %d", c);
	if (c == 8)
	{
		puts("Stampo...");
		return (1);
	}
	return (0);
}
