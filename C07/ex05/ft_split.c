/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:09:34 by adi-stef          #+#    #+#             */
/*   Updated: 2022/09/23 15:12:15 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

int	ft_in_char(char c, char *set)
{
	int	i;

	i = -1;
	while (set[++i])
		if (c == set[i])
			return (1);
	return (0);
}

int	ft_wrd_nbr(char *str, char *set)
{
	int	i;
	int	j;
	int	c;

	j = 0;
	c = 0;
	i = -1;
	while (str[++i])
	{
		if (ft_in_char(str[i], set) && !j)
		{
			j = 1;
			if (i != 0)
				c++;
		}
		else if (!ft_in_char(str[i], set) && j)
			j = 0;
	}
	if (!j)
		c++;
	return (c);
}

void	ft_char_nbr(char *str, char *set, char **ptr, int i)
{
	int	j;
	int	k;
	int	c;

	c = 0;
	k = 0;
	while (str[++i])
	{
		if (!ft_in_char(str[i], set))
		{
			j = 0;
			c++;
		}
		else if (c > 0 && !j)
		{
			ptr[k] = (char *) malloc ((c + 1) * sizeof (char));
			c = 0;
			j = 1;
			k++;
		}
	}
	if (str[i] == 0)
		ptr[k] = (char *) malloc ((c + 1) * sizeof (char));
}

void	ft_fill(char *str, char *set, char **ptr, int i)
{
	int	j;
	int	k;
	int	c;

	j = 0;
	k = 1;
	c = 0;
	while (str[++i])
	{
		if (!ft_in_char(str[i], set))
		{
			ptr[j][c] = str[i];
			k = 0;
			c++;
		}
		else if (c > 0)
		{
			ptr[j][c] = 0;
			c = 0;
			j++;
		}
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**ptr;

	ptr = (char **) malloc ((ft_wrd_nbr(str, charset) + 1) * 8);
	ft_char_nbr(str, charset, ptr, -1);
	ft_fill(str, charset, ptr, -1);
	return (ptr);
}
/*
int	main(void)
{
	char	**res;
	char	str[] = "fCiaoofffcomefftaif";
	char	set[] = "f";

	res = ft_split(str, set);
	puts(res[0]);
	puts(res[1]);
	puts(res[2]);
	free(res);
}
*/
